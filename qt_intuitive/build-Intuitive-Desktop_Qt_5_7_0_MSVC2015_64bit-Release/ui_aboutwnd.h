/********************************************************************************
** Form generated from reading UI file 'aboutwnd.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWND_H
#define UI_ABOUTWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutWnd
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *aboutWnd)
    {
        if (aboutWnd->objectName().isEmpty())
            aboutWnd->setObjectName(QStringLiteral("aboutWnd"));
        aboutWnd->resize(400, 200);
        aboutWnd->setMinimumSize(QSize(400, 200));
        aboutWnd->setMaximumSize(QSize(400, 200));
        label = new QLabel(aboutWnd);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 351, 141));
        label->setWordWrap(true);
        pushButton = new QPushButton(aboutWnd);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 160, 75, 23));

        retranslateUi(aboutWnd);

        QMetaObject::connectSlotsByName(aboutWnd);
    } // setupUi

    void retranslateUi(QWidget *aboutWnd)
    {
        aboutWnd->setWindowTitle(QApplication::translate("aboutWnd", "About...", 0));
        label->setText(QApplication::translate("aboutWnd", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; text-decoration: underline;\">Intuitive Control</span></p><p align=\"justify\"><span style=\" font-size:12pt;\">This software should be considered as part of </span><a href=\"http://pl.bab.la/slownik/angielski-polski/bsc-thesis\"><span style=\" font-family:'Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; text-decoration: underline; color:#000000;\">BSc Thesis</span></a><span style=\" font-family:'Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#333333;\"> &quot;Intuitive control of mobile robot's manipulator&quot; and cannot be used in other purposes than educational. Please reference to mentioned paper for more informations.</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("aboutWnd", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class aboutWnd: public Ui_aboutWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWND_H
