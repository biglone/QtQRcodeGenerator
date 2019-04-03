#ifndef NEWPLATEWORKER_H
#define NEWPLATEWORKER_H

#include "patrolinfo.h"

#include <QObject>
#include <QFile>


class NewPlateWorker : public QObject
{
	Q_OBJECT

public:
	NewPlateWorker(const QString &startId, const QString &path, const QList<PatrolInfo > &infos);
	~NewPlateWorker();

public slots:
	void process();

signals:
	void finished();
	void error(const QString &err);
	void progressChanged(int value);

private:
	bool createCSVFile();

private:
	QString m_startId;
	QFile m_csvFile;
	QString m_savingPath;
	QList<PatrolInfo> m_patrolInfos;
};

#endif // NEWPLATEWORKER_H
