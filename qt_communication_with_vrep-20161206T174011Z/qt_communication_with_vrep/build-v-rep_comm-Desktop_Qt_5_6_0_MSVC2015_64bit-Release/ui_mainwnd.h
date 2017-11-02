/********************************************************************************
** Form generated from reading UI file 'mainwnd.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWND_H
#define UI_MAINWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWnd
{
public:
    QWidget *centralWidget;
    QPushButton *pb_run;
    QPushButton *pushButton_3;
    QSlider *vX;
    QSlider *vY;
    QSlider *vZ;
    QSlider *vA;
    QSlider *vB;
    QSlider *vC;
    QGroupBox *groupBox;
    QRadioButton *radio_grip;
    QRadioButton *radio_base;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWnd)
    {
        if (MainWnd->objectName().isEmpty())
            MainWnd->setObjectName(QStringLiteral("MainWnd"));
        MainWnd->resize(721, 307);
        centralWidget = new QWidget(MainWnd);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pb_run = new QPushButton(centralWidget);
        pb_run->setObjectName(QStringLiteral("pb_run"));
        pb_run->setGeometry(QRect(10, 210, 181, 31));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 210, 371, 31));
        vX = new QSlider(centralWidget);
        vX->setObjectName(QStringLiteral("vX"));
        vX->setGeometry(QRect(30, 30, 160, 22));
        vX->setMaximum(100);
        vX->setValue(50);
        vX->setOrientation(Qt::Horizontal);
        vY = new QSlider(centralWidget);
        vY->setObjectName(QStringLiteral("vY"));
        vY->setGeometry(QRect(30, 70, 160, 22));
        vY->setMaximum(100);
        vY->setValue(50);
        vY->setOrientation(Qt::Horizontal);
        vZ = new QSlider(centralWidget);
        vZ->setObjectName(QStringLiteral("vZ"));
        vZ->setGeometry(QRect(30, 110, 160, 22));
        vZ->setMaximum(100);
        vZ->setValue(50);
        vZ->setOrientation(Qt::Horizontal);
        vA = new QSlider(centralWidget);
        vA->setObjectName(QStringLiteral("vA"));
        vA->setGeometry(QRect(280, 30, 160, 22));
        vA->setMaximum(100);
        vA->setValue(50);
        vA->setOrientation(Qt::Horizontal);
        vB = new QSlider(centralWidget);
        vB->setObjectName(QStringLiteral("vB"));
        vB->setGeometry(QRect(280, 70, 160, 22));
        vB->setMaximum(100);
        vB->setValue(50);
        vB->setOrientation(Qt::Horizontal);
        vC = new QSlider(centralWidget);
        vC->setObjectName(QStringLiteral("vC"));
        vC->setGeometry(QRect(280, 110, 160, 22));
        vC->setMaximum(100);
        vC->setValue(50);
        vC->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(530, 80, 120, 80));
        radio_grip = new QRadioButton(groupBox);
        radio_grip->setObjectName(QStringLiteral("radio_grip"));
        radio_grip->setGeometry(QRect(20, 50, 82, 17));
        radio_base = new QRadioButton(groupBox);
        radio_base->setObjectName(QStringLiteral("radio_base"));
        radio_base->setGeometry(QRect(20, 20, 82, 17));
        radio_base->setChecked(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 150, 431, 31));
        MainWnd->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWnd);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 721, 21));
        MainWnd->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWnd);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWnd->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWnd);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWnd->setStatusBar(statusBar);

        retranslateUi(MainWnd);

        QMetaObject::connectSlotsByName(MainWnd);
    } // setupUi

    void retranslateUi(QMainWindow *MainWnd)
    {
        MainWnd->setWindowTitle(QApplication::translate("MainWnd", "MainWnd", 0));
        pb_run->setText(QApplication::translate("MainWnd", "Run", 0));
        pushButton_3->setText(QApplication::translate("MainWnd", "Po\305\202\304\205cz z V-REP", 0));
        groupBox->setTitle(QApplication::translate("MainWnd", "Relative To", 0));
        radio_grip->setText(QApplication::translate("MainWnd", "Gripper", 0));
        radio_base->setText(QApplication::translate("MainWnd", "Base", 0));
        pushButton->setText(QApplication::translate("MainWnd", "Zero OUT!", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWnd: public Ui_MainWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWND_H
