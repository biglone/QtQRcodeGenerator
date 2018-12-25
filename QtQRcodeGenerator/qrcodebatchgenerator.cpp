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

void QRcodeBatchGenerator::onError(const QString &errorString)
{
	// todo
	QMessageBox::information(this, tr("Tip"), errorString);
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
		QMessageBox::information(this, tr("Tip"), tr("start ID and generate num can not be empty"));
		return;
	}
	
	bool toIntOk = true;
	int nStartId = startId.toInt(&toIntOk);
	if (!toIntOk)
	{
		QMessageBox::information(this, tr("Tip"), tr("please make sure that start ID is pure number"));
		return;
	}

	int nNum = num.toInt(&toIntOk);
	if (!toIntOk)
	{
		QMessageBox::information(this, tr("Tip"), tr("please make sure that generate count is pure number"));
		return;
	}

	if (nStartId < 0)
	{
		QMessageBox::information(this, tr("Tip"), tr("start ID can not be minus"));
		return;
	}

	if (nNum <= 0)
	{
		QMessageBox::information(this, tr("Tip"), tr("generate num should be positive"));
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