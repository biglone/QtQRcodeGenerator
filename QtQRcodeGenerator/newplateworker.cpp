#include "newplateworker.h"

#include "imagepainter.h"

#include <QDir>
#include <QTextStream>

NewPlateWorker::NewPlateWorker(const QString &startId, const QString &path, const QList<PatrolInfo> &infos)
	:m_startId(startId), m_savingPath(path), m_patrolInfos(infos)
{
}

NewPlateWorker::~NewPlateWorker()
{
}

bool NewPlateWorker::createCSVFile()
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

void NewPlateWorker::process()
{
	if (!createCSVFile())
	{
		emit error(tr("create csv file failed"));
	}

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

	int count = m_patrolInfos.count();


	for (qint64 i = nStartId; i < count + nStartId; ++i)
	{
		int width = m_startId.length();
		QString id = QString("%1").arg(i, width, 10, QLatin1Char('0'));

		ImagePainter imagePainter(this);
		imagePainter.generateBGImage(QSize(600, 600));
		
		imagePainter.setId(id);
		if (!imagePainter.makeQRcodeImage())
		{
			emit error(tr("make QRcode image failed"));
			return;
		}

		imagePainter.drawQRcode();
	}

	
}