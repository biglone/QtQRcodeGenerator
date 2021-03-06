#include "worker.h"

#include "imagepainter.h"
#include <QDir>
#include <QTextStream>

Worker::Worker(const QString &startId, const QString &path, const int generateCount)
	:m_startId(startId), m_savingPath(path), m_generateCount(generateCount)
{
	if (!createCSVFile())
	{
		emit error(tr("create csv file failed"));
	}
}

Worker::~Worker()
{

}

bool Worker::createCSVFile()
{
	QString csvFileName = QString("readme.csv");
	QString currentPath = QDir::currentPath();
	QString csvFilePath = m_savingPath;
	csvFilePath.append(QString("/%1").arg(csvFileName));
	m_csvFile.setFileName(csvFilePath);

	if (m_csvFile.open(QIODevice::ReadWrite))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Worker::process()
{
	QTextStream textStream;
	textStream.setDevice(&m_csvFile);
	QString header;
	header.append("id");
	header.append(",");
	header.append("data");
	header.append(",");
	header.append("file name\n");
	textStream << header;

	qint64 nStartId = m_startId.toLongLong();

	for(qint64 i = nStartId; i < m_generateCount + nStartId; ++i)
	{
		int width = m_startId.length();
		QString id = QString("%1").arg(i, width, 10, QLatin1Char('0'));

		ImagePainter imagePainter(this);
		imagePainter.setId(id);
		if (!imagePainter.makeQRcodeImage())
		{
			emit error(tr("make QRcode image failed"));
			return;
		}
		imagePainter.drawQRcode();
		//imagePainter.drawText();
		imagePainter.setSavingPath(m_savingPath);
		if (imagePainter.saveImage())
		{
			emit progressChanged(i - nStartId + 1);
		}
		else
		{
			emit error(tr("save QRcode image failed"));
		}
		QString record;
		record.append(id);
		record.append(",");
		record.append(imagePainter.data());
		record.append(",");

		record.append(QString("%1.png").arg(id));
		record.append("\n");

		textStream << record;
	}
	m_csvFile.close();

	emit finished();
}