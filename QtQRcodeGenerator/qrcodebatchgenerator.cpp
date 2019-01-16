#include "qrcodebatchgenerator.h"
#include "ui_qrcodebatchgenerator.h"

#include "imagepainter.h"
#include "QRCodeUtil.h"
#include "worker.h"

#include <QMessageBox>
#include <QDesktopServices>
#include <QDateTime>
#include <QDir>
#include <QThread>
#include <QFile>

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

void QRcodeBatchGenerator::on_btnGenerateOne_clicked()
{
	if (ui->leditData->text().isEmpty())
	{
		QMessageBox::information(this, tr("Tip"), tr("Data is empty, please "));
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