/********************************************************************************
** Form generated from reading UI file 'setwnd.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETWND_H
#define UI_SETWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setWnd
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_4;

    void setupUi(QWidget *setWnd)
    {
        if (setWnd->objectName().isEmpty())
            setWnd->setObjectName(QStringLiteral("setWnd"));
        setWnd->resize(254, 272);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(setWnd->sizePolicy().hasHeightForWidth());
        setWnd->setSizePolicy(sizePolicy);
        widget = new QWidget(setWnd);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(140, 180, 94, 83));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        widget1 = new QWidget(setWnd);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 20, 238, 61));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(widget1);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setTristate(false);

        verticalLayout_2->addWidget(checkBox);

        pushButton_4 = new QPushButton(widget1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_2->addWidget(pushButton_4);


        retranslateUi(setWnd);

        QMetaObject::connectSlotsByName(setWnd);
    } // setupUi

    void retranslateUi(QWidget *setWnd)
    {
        setWnd->setWindowTitle(QApplication::translate("setWnd", "Form", 0));
        pushButton->setText(QApplication::translate("setWnd", "Save and Close", 0));
        pushButton_2->setText(QApplication::translate("setWnd", "Save and Restart", 0));
        pushButton_3->setText(QApplication::translate("setWnd", "Cancel", 0));
        checkBox->setText(QApplication::translate("setWnd", "Autorun v-rep simulation on application start", 0));
        pushButton_4->setText(QApplication::translate("setWnd", "Path settings dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class setWnd: public Ui_setWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETWND_H
