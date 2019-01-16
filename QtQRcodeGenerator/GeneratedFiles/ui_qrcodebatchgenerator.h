/********************************************************************************
** Form generated from reading UI file 'qrcodebatchgenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRCODEBATCHGENERATOR_H
#define UI_QRCODEBATCHGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QRcodeBatchGenerator
{
public:
    QPushButton *pushButtonGenerate;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelStartId;
    QLineEdit *lineEditStartID;
    QLabel *labelGenerateNum;
    QLineEdit *lineEditGenerateNum;
    QProgressBar *progressBar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelData;
    QLineEdit *leditData;
    QPushButton *btnGenerateOne;

    void setupUi(QDialog *QRcodeBatchGenerator)
    {
        if (QRcodeBatchGenerator->objectName().isEmpty())
            QRcodeBatchGenerator->setObjectName(QStringLiteral("QRcodeBatchGenerator"));
        QRcodeBatchGenerator->resize(363, 383);
        pushButtonGenerate = new QPushButton(QRcodeBatchGenerator);
        pushButtonGenerate->setObjectName(QStringLiteral("pushButtonGenerate"));
        pushButtonGenerate->setGeometry(QRect(40, 220, 281, 41));
        layoutWidget = new QWidget(QRcodeBatchGenerator);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 60, 281, 111));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelStartId = new QLabel(layoutWidget);
        labelStartId->setObjectName(QStringLiteral("labelStartId"));

        gridLayout->addWidget(labelStartId, 0, 0, 1, 1);

        lineEditStartID = new QLineEdit(layoutWidget);
        lineEditStartID->setObjectName(QStringLiteral("lineEditStartID"));

        gridLayout->addWidget(lineEditStartID, 0, 1, 1, 1);

        labelGenerateNum = new QLabel(layoutWidget);
        labelGenerateNum->setObjectName(QStringLiteral("labelGenerateNum"));

        gridLayout->addWidget(labelGenerateNum, 1, 0, 1, 1);

        lineEditGenerateNum = new QLineEdit(layoutWidget);
        lineEditGenerateNum->setObjectName(QStringLiteral("lineEditGenerateNum"));

        gridLayout->addWidget(lineEditGenerateNum, 1, 1, 1, 1);

        progressBar = new QProgressBar(QRcodeBatchGenerator);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(40, 180, 281, 23));
        progressBar->setValue(24);
        widget = new QWidget(QRcodeBatchGenerator);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 290, 281, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelData = new QLabel(widget);
        labelData->setObjectName(QStringLiteral("labelData"));

        horizontalLayout->addWidget(labelData);

        leditData = new QLineEdit(widget);
        leditData->setObjectName(QStringLiteral("leditData"));

        horizontalLayout->addWidget(leditData);

        btnGenerateOne = new QPushButton(widget);
        btnGenerateOne->setObjectName(QStringLiteral("btnGenerateOne"));

        horizontalLayout->addWidget(btnGenerateOne);


        retranslateUi(QRcodeBatchGenerator);

        QMetaObject::connectSlotsByName(QRcodeBatchGenerator);
    } // setupUi

    void retranslateUi(QDialog *QRcodeBatchGenerator)
    {
        QRcodeBatchGenerator->setWindowTitle(QApplication::translate("QRcodeBatchGenerator", "QRcodeBatchGenerator", 0));
        pushButtonGenerate->setText(QApplication::translate("QRcodeBatchGenerator", "\345\274\200\345\247\213\347\224\237\346\210\220", 0));
        labelStartId->setText(QApplication::translate("QRcodeBatchGenerator", "\350\265\267\345\247\213ID\357\274\232", 0));
        labelGenerateNum->setText(QApplication::translate("QRcodeBatchGenerator", "\347\224\237\346\210\220\344\270\252\346\225\260\357\274\232", 0));
        labelData->setText(QApplication::translate("QRcodeBatchGenerator", "\346\225\260\346\215\256:", 0));
        btnGenerateOne->setText(QApplication::translate("QRcodeBatchGenerator", "\347\224\237\346\210\220\344\270\200\345\274\240", 0));
    } // retranslateUi

};

namespace Ui {
    class QRcodeBatchGenerator: public Ui_QRcodeBatchGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRCODEBATCHGENERATOR_H
