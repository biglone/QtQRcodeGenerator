#ifndef QRCODEBATCHGENERATOR_H
#define QRCODEBATCHGENERATOR_H

#include <QDialog>
#include <QFile>
#include <QThread>

class ImagePainter;
class PatrolInfo;

namespace Ui {class QRcodeBatchGenerator;};

class QRcodeBatchGenerator : public QDialog
{
	Q_OBJECT

public:
	QRcodeBatchGenerator(QWidget *parent = 0);
	~QRcodeBatchGenerator();

public slots:
	void on_btnGenerateOne_clicked();
	void on_pushButtonGenerate_clicked();

	void on_btnOpenExcelFile_clicked();
	void on_btnGenerateNew_clicked();
	void onError(const QString &errorString);
	void onFinished();
	void onProgressChanged(int value);

	void onNewProGressChanged(int value);

private:
	void createDirectory();

	void createDirectoryNew();

	void removeDirectory();

	void removeDirectoryNew();

	void dealWithErrors(const QString &errString);

	void dealWithErrorsNew(const QString &errString);

	void showErrors(const QString &errString);

	void reset();

	void resetNew();

	void makeQRcodeWidthLogo(const QString &data, const QImage &logo);

	QList<PatrolInfo> readPatrolInfoFromFile(const QString &fileName);
private:
	Ui::QRcodeBatchGenerator *ui;
	QString m_path;
	QString m_pathNew;
	bool m_inOperating;
	bool m_inOperatingNew;
	QThread *m_thread;
	QThread *m_threadNewPlate;
};

#endif // QRCODEBATCHGENERATOR_H
