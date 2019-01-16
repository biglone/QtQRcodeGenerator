#include "qtqrcodegenerator.h"
#include "QRCodeUtil.h"
#include <QImage>
#include <QString>
#include <QColor>

//	-------------------------------------------------------
//	MEMBER FUNCTIONS OF CLASS QtQRcodeGenerator
QtQRcodeGenerator::QtQRcodeGenerator(QWidget *parent)
	: QDialog(parent, Qt::WindowTitleHint|Qt::WindowMaximizeButtonHint|Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint)
{
	ui.setupUi(this);
}

QtQRcodeGenerator::~QtQRcodeGenerator()
{

}

void QtQRcodeGenerator::on_pushButtonCode_clicked()
{
	QString dataStr = QString("edu#patrol#abcd123467890");
	QImage qrImage;
	if (QRCodeUtil::getQRImage(qrImage, dataStr.toUtf8(), 10, QColor("#000000")))
	{
		QImage image = qrImage.scaled(ui.labelImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
		ui.labelImage->setPixmap(QPixmap::fromImage(image));
	} 
	else
	{
		ui.labelImage->setText(QString::fromLocal8Bit("Éú³É¶şÎ¬ÂëÊ§°Ü"));
	}
}
