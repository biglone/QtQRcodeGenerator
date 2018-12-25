#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QFile>

class Worker : public QObject
{
	Q_OBJECT

public:
	Worker(const QString &startId, const QString &path, const int generateCount);
	~Worker();

public slots:
	void process();

signals:
	void finished();
	void error(const QString &err);
	void progressChanged(int value);

private:
	bool createCSVFile();

private:
	QFile m_csvFile;
	QString m_startId;
	QString m_savingPath;
	int m_generateCount;
};

#endif // WORKER_H
