#include "qtqrcodegenerator.h"

#include "qrcodebatchgenerator.h"

#include <QApplication>
#include <QTextCodec>
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/images/icon.png"));

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

	//QString translatorName = QString::fromLatin1("qtqrcodegenerator_zh");
	QString translatorName = QString::fromLatin1("qtqrcodegenerator_zh");
	QTranslator *translator = new QTranslator(&a);
	if (translator->load(translatorName/*, ":/translator/"*/))
		QApplication::installTranslator(translator);

	QRcodeBatchGenerator w;
	w.show();
	w.activateWindow();

	return a.exec();
}
