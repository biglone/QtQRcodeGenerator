#ifndef QRCODEBATCHGENERATOR_H
#define QRCODEBATCHGENERATOR_H

#include <QDialog>
#include <QFile>
#include <QThread>

class ImagePainter;

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

private:
	void createDirectory();

	void removeDirectory();

	void dealWithErrors(const QString &errString);

	void showErrors(const QString &errString);

	void reset();

	void makeQRcodeWidthLogo(const QString &data, const QImage &logo);

private:
	Ui::QRcodeBatchGenerator *ui;
	QString m_path;
	bool m_inOperating;
	QThread *m_thread;
};

#endif // QRCODEBATCHGENERATOR_H
