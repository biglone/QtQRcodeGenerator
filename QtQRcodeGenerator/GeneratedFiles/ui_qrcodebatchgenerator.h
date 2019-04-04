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
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *labelStartId;
    QLineEdit *lineEditStartID;
    QLabel *labelGenerateNum;
    QLineEdit *lineEditGenerateNum;
    QProgressBar *progressBar;
    QPushButton *pushButtonGenerate;
    QHBoxLayout *horizontalLayout;
    QLabel *labelData;
    QLineEdit *leditData;
    QPushButton *btnGenerateOne;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *labelStartId_2;
    QLabel *lblDepartName;
    QLabel *labelExcelFilename;
    QLineEdit *lineEditFileName;
    QPushButton *btnOpenExcelFile;
    QLineEdit *lineEditDepartName;
    QLineEdit *lineEditStartIDNew;
    QProgressBar *progressBarNew;
    QPushButton *btnGenerateNew;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *QRcodeBatchGenerator)
    {
        if (QRcodeBatchGenerator->objectName().isEmpty())
            QRcodeBatchGenerator->setObjectName(QStringLiteral("QRcodeBatchGenerator"));
        QRcodeBatchGenerator->resize(423, 361);
        verticalLayout = new QVBoxLayout(QRcodeBatchGenerator);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(QRcodeBatchGenerator);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelStartId = new QLabel(tab);
        labelStartId->setObjectName(QStringLiteral("labelStartId"));

        gridLayout->addWidget(labelStartId, 0, 0, 1, 1);

        lineEditStartID = new QLineEdit(tab);
        lineEditStartID->setObjectName(QStringLiteral("lineEditStartID"));

        gridLayout->addWidget(lineEditStartID, 0, 1, 1, 1);

        labelGenerateNum = new QLabel(tab);
        labelGenerateNum->setObjectName(QStringLiteral("labelGenerateNum"));

        gridLayout->addWidget(labelGenerateNum, 1, 0, 1, 1);

        lineEditGenerateNum = new QLineEdit(tab);
        lineEditGenerateNum->setObjectName(QStringLiteral("lineEditGenerateNum"));

        gridLayout->addWidget(lineEditGenerateNum, 1, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        progressBar = new QProgressBar(tab);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout_3->addWidget(progressBar);

        pushButtonGenerate = new QPushButton(tab);
        pushButtonGenerate->setObjectName(QStringLiteral("pushButtonGenerate"));

        verticalLayout_3->addWidget(pushButtonGenerate);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelData = new QLabel(tab);
        labelData->setObjectName(QStringLiteral("labelData"));

        horizontalLayout->addWidget(labelData);

        leditData = new QLineEdit(tab);
        leditData->setObjectName(QStringLiteral("leditData"));

        horizontalLayout->addWidget(leditData);

        btnGenerateOne = new QPushButton(tab);
        btnGenerateOne->setObjectName(QStringLiteral("btnGenerateOne"));

        horizontalLayout->addWidget(btnGenerateOne);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 137, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        labelStartId_2 = new QLabel(tab_2);
        labelStartId_2->setObjectName(QStringLiteral("labelStartId_2"));

        gridLayout_2->addWidget(labelStartId_2, 0, 0, 1, 1);

        lblDepartName = new QLabel(tab_2);
        lblDepartName->setObjectName(QStringLiteral("lblDepartName"));

        gridLayout_2->addWidget(lblDepartName, 1, 0, 1, 2);

        labelExcelFilename = new QLabel(tab_2);
        labelExcelFilename->setObjectName(QStringLiteral("labelExcelFilename"));

        gridLayout_2->addWidget(labelExcelFilename, 2, 0, 1, 3);

        lineEditFileName = new QLineEdit(tab_2);
        lineEditFileName->setObjectName(QStringLiteral("lineEditFileName"));

        gridLayout_2->addWidget(lineEditFileName, 2, 3, 1, 1);

        btnOpenExcelFile = new QPushButton(tab_2);
        btnOpenExcelFile->setObjectName(QStringLiteral("btnOpenExcelFile"));

        gridLayout_2->addWidget(btnOpenExcelFile, 2, 4, 1, 1);

        lineEditDepartName = new QLineEdit(tab_2);
        lineEditDepartName->setObjectName(QStringLiteral("lineEditDepartName"));

        gridLayout_2->addWidget(lineEditDepartName, 1, 3, 1, 1);

        lineEditStartIDNew = new QLineEdit(tab_2);
        lineEditStartIDNew->setObjectName(QStringLiteral("lineEditStartIDNew"));

        gridLayout_2->addWidget(lineEditStartIDNew, 0, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        progressBarNew = new QProgressBar(tab_2);
        progressBarNew->setObjectName(QStringLiteral("progressBarNew"));
        progressBarNew->setValue(24);

        verticalLayout_2->addWidget(progressBarNew);

        btnGenerateNew = new QPushButton(tab_2);
        btnGenerateNew->setObjectName(QStringLiteral("btnGenerateNew"));

        verticalLayout_2->addWidget(btnGenerateNew);

        verticalSpacer_3 = new QSpacerItem(20, 153, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

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
        labelStartId_2->setText(QApplication::translate("QRcodeBatchGenerator", "\350\265\267\345\247\213ID", 0));
        lblDepartName->setText(QApplication::translate("QRcodeBatchGenerator", "\345\215\225\344\275\215\345\220\215\347\247\260", 0));
        labelExcelFilename->setText(QApplication::translate("QRcodeBatchGenerator", "\346\226\207\344\273\266", 0));
        btnOpenExcelFile->setText(QApplication::translate("QRcodeBatchGenerator", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        btnGenerateNew->setText(QApplication::translate("QRcodeBatchGenerator", "\347\224\237\346\210\220", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QRcodeBatchGenerator", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class QRcodeBatchGenerator: public Ui_QRcodeBatchGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRCODEBATCHGENERATOR_H
