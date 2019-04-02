#include "qrcodebatchgenerator.h"
#include "ui_qrcodebatchgenerator.h"

#include "imagepainter.h"
#include "QRCodeUtil.h"
#include "worker.h"

#include "xlsx/xlsxdocument.h"
#include "xlsx/xlsxabstractsheet.h"
#include "xlsx/xlsxworkbook.h"
#include "patrolinfo.h"

#include <QMessageBox>
#include <QDesktopServices>
#include <QDateTime>
#include <QDir>
#include <QThread>
#include <QFile>
#include <QFileDialog>

static const char *PATROL_NAME = "patrolName";
static const char *AREA_NAME = "areaName";
static const char *PEOPLE_IN_CHARGE = "peopleInCharge";
static const char *PERIOD = "period";
static const char *WEEK_DAYS = "weekDays";
static const char *START_TIME = "startTime";
static const char *END_TIME = "endTime";
static const char *END_DAY = "endDay";
static const char *PATROL_TIMES_PER_DAY = "patrolTimesPerDay";
static const char *PATROL_TRRGET = "patrolTarget";

QRcodeBatchGenerator::QRcodeBatchGenerator(QWidget *parent)
	: QDialog(parent), m_inOperating(false)
{
	ui = new Ui::QRcodeBatchGenerator();
	ui->setupUi(this);
	
	QString progressStyleSheet("QProgressBar{\
		border: none;\
		color: white;\
		text-align: center;\
		background: rgb(68, 69, 73);\
		}\
		QProgressBar::chunk {\
		border: none;\
		background: rgb(0, 160, 230);\
	}");
	ui->progressBar->setStyleSheet(progressStyleSheet);
	ui->progressBar->setMinimum(0);
	ui->progressBar->setMaximum(0);
	ui->progressBar->hide();
}

QRcodeBatchGenerator::~QRcodeBatchGenerator()
{
	delete ui;
}

void QRcodeBatchGenerator::createDirectory()
{
	QString deskTopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

	QDateTime dateTime = QDateTime::currentDateTime();
	QString folerName = dateTime.toString("yyyy-MM-dd HHmmss");
	folerName.append("_");
	folerName.append(tr("QRcode"));
	
	QDir dir(deskTopPath);

	dir.mkdir(folerName);
	dir.cd(folerName);
	m_path = dir.path();
}

void QRcodeBatchGenerator::removeDirectory()
{
	QDir createdDir(m_path);
	if (createdDir.exists())
	{
		createdDir.removeRecursively();
	}
}

void QRcodeBatchGenerator::dealWithErrors(const QString &errString)
{
	if (!errString.isEmpty())
	{
		showErrors(errString);
	}
	
	removeDirectory();
	reset();
}

void QRcodeBatchGenerator::showErrors(const QString &errString)
{
	if (!errString.isEmpty())
	{
		QMessageBox::information(this, tr("Tip"), errString);
	}
}

void QRcodeBatchGenerator::reset()
{
	m_inOperating = false;
}

void QRcodeBatchGenerator::onError(const QString &errorString)
{
	// todo
	dealWithErrors(errorString);
}

void QRcodeBatchGenerator::onFinished()
{
	//ui->progressBa
	m_inOperating = false;
}

void QRcodeBatchGenerator::onProgressChanged(int value)
{
	ui->progressBar->setValue(value);
}

void QRcodeBatchGenerator::on_pushButtonGenerate_clicked()
{
	if (m_inOperating)
	{
		QMessageBox::information(this, tr("Tip"), tr("It's working now, please wait."));
		return;
	}

	m_inOperating = true;
	createDirectory();
	
	QString startId = ui->lineEditStartID->text().trimmed();
	QString num = ui->lineEditGenerateNum->text().trimmed();

	if (startId.isEmpty() || num.isEmpty())
	{
		dealWithErrors(tr("start ID and generate num can not be empty"));
		return;
	}

	bool toIntOk = true;
	qint64 nStartId = startId.toLongLong(&toIntOk, 10);
	if (!toIntOk)
	{
		dealWithErrors(tr("please make sure that start ID is pure number"));
		return;
	}

	int nNum = num.toInt(&toIntOk);
	if (!toIntOk)
	{
		dealWithErrors(tr("please make sure that generate count is pure number"));
		return;
	}

	if (nStartId < 0)
	{
		dealWithErrors(tr("start ID can not be minus"));
		return;
	}

	if (nNum <= 0)
	{
		dealWithErrors(tr("generate num should be positive"));
		return;
	}

	ui->progressBar->setMaximum(nNum);
	ui->progressBar->setVisible(true);

	m_thread = new QThread();
	Worker *worker = new Worker(startId, m_path, nNum);
	worker->moveToThread(m_thread);

	connect(worker, SIGNAL(error(QString)), this, SLOT(onError(QString)));
	connect(m_thread, SIGNAL(started()), worker, SLOT(process()));
	connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
	connect(worker, SIGNAL(finished()), this, SLOT(onFinished()));
	connect(m_thread, SIGNAL(finished()), m_thread, SLOT(deleteLater()));
	connect(worker, SIGNAL(progressChanged(int)), SLOT(onProgressChanged(int)));

	m_thread->start();
}

void QRcodeBatchGenerator::on_btnGenerateNew_clicked()
{
	createDirectory();
	QString startId = ui->lineEditStartIDNew->text().trimmed();
	if (startId.isEmpty())
	{
		dealWithErrors(tr("start ID and generate num can not be empty"));
		return;
	}

	QString excelFileName = ui->lineEditFileName->text().trimmed();
	if (excelFileName.isEmpty())
	{
		dealWithErrors(tr("open the excel file first"));
		return;
	}

	
}

void QRcodeBatchGenerator::on_btnOpenExcelFile_clicked()
{
	QString excleFileName = QFileDialog::getOpenFileName(this, tr("Open File"),
		QString(),
		tr("Excel Files (*.xlsx)"));

	ui->lineEditFileName->setText(excleFileName);
}

void QRcodeBatchGenerator::on_btnGenerateOne_clicked()
{
	if (ui->leditData->text().isEmpty())
	{
		QMessageBox::information(this, tr("Tip"), tr("Data is empty, please fill it."));
		return;
	}

	QString data = ui->leditData->text().trimmed();
	makeQRcodeWidthLogo(data, QImage(":/images/logo.png"));
}

void QRcodeBatchGenerator::makeQRcodeWidthLogo(const QString &data, const QImage &logo)
{
	if (data.isEmpty() || logo.isNull())
	{
		return;
	}
	QString savingPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
	ImagePainter imagePainter;
	imagePainter.makeQRcodeImageWithData(data);
	imagePainter.drawQRcode();

	imagePainter.setSavingPath(savingPath);
	imagePainter.saveImage();
}

QList<PatrolInfo> QRcodeBatchGenerator::readPatrolInfoFromFile(const QString &fileName)
{
	QList<PatrolInfo> patrolInfos;
	if (fileName.isEmpty())
	{
		return patrolInfos;
	}

	QXlsx::Document xlsx(QStringLiteral("patrolPoint2user.xlsx"));
	QXlsx::Workbook *workBook = xlsx.workbook();
	QXlsx::Worksheet *workSheet = static_cast<QXlsx::Worksheet*>(workBook->sheet(0));

	int rowCount = workSheet->dimension().rowCount();
	int columnCount = workSheet->dimension().columnCount();

	QStringList titles;
	// get first row titles;
	for (int i = 1; i <= columnCount; ++i)
	{
		titles << workSheet->read(1, i).toString();
	}

	QList<PatrolInfo> patrolInfos;

	for (int i = 2; i <= rowCount; ++i)
	{
		PatrolInfo info;
		for (int j = 1; j <= columnCount; ++j)
		{
			QString content = workSheet->read(i, j).toString();
			QString title = titles[j- 1];
			if (PATROL_NAME == title)
			{
				info.setPatrolName(content);
			}
			else if (AREA_NAME == title)
			{
				info.setAreaName(content);
			}
			else if (PEOPLE_IN_CHARGE == title)
			{
				info.setPeopleInCharege(content);
			}
			else if (PERIOD == title)
			{
				info.setPeriod(content);
			}
			else if (WEEK_DAYS == title)
			{
				info.setWeekDays(content);
			}
			else if (START_TIME == title)
			{
				info.setStartTime(content);
			}
			else if (END_TIME == title)
			{
				info.setEndTime(content);
			}
			else if (END_DAY == title)
			{
				info.setEndDay(content);
			}
			else if (PATROL_TIMES_PER_DAY == title)
			{
				info.setPatrolTimesPerDay(content);
			}
			else if (PATROL_TRRGET == title)
			{
				info.setPatrolTarget(content);
			}
		}
		patrolInfos.append(info);
	}
}