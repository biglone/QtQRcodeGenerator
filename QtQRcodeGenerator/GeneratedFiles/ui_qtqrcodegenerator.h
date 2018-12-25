/********************************************************************************
** Form generated from reading UI file 'qtqrcodegenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTQRCODEGENERATOR_H
#define UI_QTQRCODEGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QtQRcodeGeneratorClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelImage;
    QPushButton *pushButtonCode;

    void setupUi(QDialog *QtQRcodeGeneratorClass)
    {
        if (QtQRcodeGeneratorClass->objectName().isEmpty())
            QtQRcodeGeneratorClass->setObjectName(QStringLiteral("QtQRcodeGeneratorClass"));
        QtQRcodeGeneratorClass->resize(438, 521);
        verticalLayout_2 = new QVBoxLayout(QtQRcodeGeneratorClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelImage = new QLabel(QtQRcodeGeneratorClass);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setMinimumSize(QSize(400, 400));
        labelImage->setMaximumSize(QSize(400, 400));

        verticalLayout->addWidget(labelImage);

        pushButtonCode = new QPushButton(QtQRcodeGeneratorClass);
        pushButtonCode->setObjectName(QStringLiteral("pushButtonCode"));
        pushButtonCode->setMinimumSize(QSize(0, 30));
        pushButtonCode->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(pushButtonCode);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(QtQRcodeGeneratorClass);

        QMetaObject::connectSlotsByName(QtQRcodeGeneratorClass);
    } // setupUi

    void retranslateUi(QDialog *QtQRcodeGeneratorClass)
    {
        QtQRcodeGeneratorClass->setWindowTitle(QApplication::translate("QtQRcodeGeneratorClass", "\344\272\214\347\273\264\347\240\201\347\224\237\346\210\220\345\231\250", 0));
        labelImage->setText(QString());
        pushButtonCode->setText(QApplication::translate("QtQRcodeGeneratorClass", "\347\224\237\346\210\220", 0));
    } // retranslateUi

};

namespace Ui {
    class QtQRcodeGeneratorClass: public Ui_QtQRcodeGeneratorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTQRCODEGENERATOR_H
