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

	void createDirectory();

public slots:
	void on_pushButtonGenerate_clicked();
	void onError(const QString &errorString);
	void onFinished();
	void onProgressChanged(int value);

private:
	Ui::QRcodeBatchGenerator *ui;
	QString m_path;
	bool m_inOperating;
	QThread *m_thread;
};

#endif // QRCODEBATCHGENERATOR_H
