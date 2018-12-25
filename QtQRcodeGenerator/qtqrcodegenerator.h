#ifndef QTQRCODEGENERATOR_H
#define QTQRCODEGENERATOR_H

#include <QDialog>
#include "ui_qtqrcodegenerator.h"

class BackgroundQRCode;
class MoveDialog;

class QtQRcodeGenerator : public QDialog
{
	Q_OBJECT

public:
	QtQRcodeGenerator(QWidget *parent = 0);
	~QtQRcodeGenerator();

private Q_SLOTS:
	void on_pushButtonCode_clicked();

private:
	Ui::QtQRcodeGeneratorClass ui;
};

#endif // QTQRCODEGENERATOR_H
