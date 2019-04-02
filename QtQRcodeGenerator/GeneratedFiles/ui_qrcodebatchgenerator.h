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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QRcodeBatchGenerator
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelStartId;
    QLineEdit *lineEditStartID;
    QLabel *labelGenerateNum;
    QLineEdit *lineEditGenerateNum;
    QProgressBar *progressBar;
    QPushButton *pushButtonGenerate;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *labelData;
    QLineEdit *leditData;
    QPushButton *btnGenerateOne;
    QWidget *tab_2;
    QPushButton *btnGenerateNew;
    QProgressBar *progressBarNew;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelStartId_2;
    QLineEdit *lineEditStartIDNew;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelExcelFilename;
    QLineEdit *lineEditFileName;
    QPushButton *btnOpenExcelFile;

    void setupUi(QDialog *QRcodeBatchGenerator)
    {
        if (QRcodeBatchGenerator->objectName().isEmpty())
            QRcodeBatchGenerator->setObjectName(QStringLiteral("QRcodeBatchGenerator"));
        QRcodeBatchGenerator->resize(433, 389);
        verticalLayout = new QVBoxLayout(QRcodeBatchGenerator);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(QRcodeBatchGenerator);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 20, 281, 111));
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

        progressBar = new QProgressBar(tab);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(90, 160, 281, 23));
        progressBar->setValue(24);
        pushButtonGenerate = new QPushButton(tab);
        pushButtonGenerate->setObjectName(QStringLiteral("pushButtonGenerate"));
        pushButtonGenerate->setGeometry(QRect(90, 200, 281, 41));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 250, 281, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelData = new QLabel(layoutWidget1);
        labelData->setObjectName(QStringLiteral("labelData"));

        horizontalLayout->addWidget(labelData);

        leditData = new QLineEdit(layoutWidget1);
        leditData->setObjectName(QStringLiteral("leditData"));

        horizontalLayout->addWidget(leditData);

        btnGenerateOne = new QPushButton(layoutWidget1);
        btnGenerateOne->setObjectName(QStringLiteral("btnGenerateOne"));

        horizontalLayout->addWidget(btnGenerateOne);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        btnGenerateNew = new QPushButton(tab_2);
        btnGenerateNew->setObjectName(QStringLiteral("btnGenerateNew"));
        btnGenerateNew->setGeometry(QRect(80, 220, 281, 41));
        progressBarNew = new QProgressBar(tab_2);
        progressBarNew->setObjectName(QStringLiteral("progressBarNew"));
        progressBarNew->setGeometry(QRect(67, 160, 331, 23));
        progressBarNew->setValue(24);
        widget = new QWidget(tab_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 50, 177, 22));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelStartId_2 = new QLabel(widget);
        labelStartId_2->setObjectName(QStringLiteral("labelStartId_2"));

        horizontalLayout_2->addWidget(labelStartId_2);

        lineEditStartIDNew = new QLineEdit(widget);
        lineEditStartIDNew->setObjectName(QStringLiteral("lineEditStartIDNew"));

        horizontalLayout_2->addWidget(lineEditStartIDNew);

        widget1 = new QWidget(tab_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(70, 100, 288, 25));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelExcelFilename = new QLabel(widget1);
        labelExcelFilename->setObjectName(QStringLiteral("labelExcelFilename"));

        horizontalLayout_3->addWidget(labelExcelFilename);

        lineEditFileName = new QLineEdit(widget1);
        lineEditFileName->setObjectName(QStringLiteral("lineEditFileName"));

        horizontalLayout_3->addWidget(lineEditFileName);

        btnOpenExcelFile = new QPushButton(widget1);
        btnOpenExcelFile->setObjectName(QStringLiteral("btnOpenExcelFile"));

        horizontalLayout_3->addWidget(btnOpenExcelFile);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(QRcodeBatchGenerator);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QRcodeBatchGenerator);
    } // setupUi

    void retranslateUi(QDialog *QRcodeBatchGenerator)
    {
        QRcodeBatchGenerator->setWindowTitle(QApplication::translate("QRcodeBatchGenerator", "QRcodeBatchGenerator", 0));
        labelStartId->setText(QApplication::translate("QRcodeBatchGenerator", "\350\265\267\345\247\213ID\357\274\232", 0));
        labelGenerateNum->setText(QApplication::translate("QRcodeBatchGenerator", "\347\224\237\346\210\220\344\270\252\346\225\260\357\274\232", 0));
        pushButtonGenerate->setText(QApplication::translate("QRcodeBatchGenerator", "\345\274\200\345\247\213\347\224\237\346\210\220", 0));
        labelData->setText(QApplication::translate("QRcodeBatchGenerator", "\346\225\260\346\215\256:", 0));
        btnGenerateOne->setText(QApplication::translate("QRcodeBatchGenerator", "\347\224\237\346\210\220\344\270\200\345\274\240", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QRcodeBatchGenerator", "Tab 1", 0));
        btnGenerateNew->setText(QApplication::translate("QRcodeBatchGenerator", "\347\224\237\346\210\220", 0));
        labelStartId_2->setText(QApplication::translate("QRcodeBatchGenerator", "\350\265\267\345\247\213ID", 0));
        labelExcelFilename->setText(QApplication::translate("QRcodeBatchGenerator", "Excel\346\226\207\344\273\266\345\220\215", 0));
        btnOpenExcelFile->setText(QApplication::translate("QRcodeBatchGenerator", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QRcodeBatchGenerator", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class QRcodeBatchGenerator: public Ui_QRcodeBatchGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRCODEBATCHGENERATOR_H
