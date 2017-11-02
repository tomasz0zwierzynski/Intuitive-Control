/********************************************************************************
** Form generated from reading UI file 'graphwnd.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWND_H
#define UI_GRAPHWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_graphWnd
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QPushButton *pB_draw;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QScrollBar *verticalScrollBar;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *plot1;
    QScrollBar *horizontalScrollBar;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSlider *horizontalSlider;

    void setupUi(QWidget *graphWnd)
    {
        if (graphWnd->objectName().isEmpty())
            graphWnd->setObjectName(QStringLiteral("graphWnd"));
        graphWnd->resize(643, 397);
        verticalLayout_3 = new QVBoxLayout(graphWnd);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(graphWnd);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(graphWnd);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(300, 0));

        horizontalLayout_2->addWidget(comboBox);

        pB_draw = new QPushButton(graphWnd);
        pB_draw->setObjectName(QStringLiteral("pB_draw"));

        horizontalLayout_2->addWidget(pB_draw);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(graphWnd);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalScrollBar = new QScrollBar(graphWnd);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setMinimum(1);
        verticalScrollBar->setMaximum(100);
        verticalScrollBar->setOrientation(Qt::Vertical);
        verticalScrollBar->setInvertedAppearance(true);

        horizontalLayout->addWidget(verticalScrollBar);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        plot1 = new QCustomPlot(graphWnd);
        plot1->setObjectName(QStringLiteral("plot1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot1->sizePolicy().hasHeightForWidth());
        plot1->setSizePolicy(sizePolicy);
        plot1->setMinimumSize(QSize(330, 200));

        verticalLayout_2->addWidget(plot1);

        horizontalScrollBar = new QScrollBar(graphWnd);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setMaximum(100);
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalScrollBar);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        checkBox = new QCheckBox(graphWnd);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy1);
        checkBox->setMaximumSize(QSize(130, 16777215));
        checkBox->setChecked(true);

        verticalLayout->addWidget(checkBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(graphWnd);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(130, 16777215));

        verticalLayout->addWidget(label);

        horizontalSlider = new QSlider(graphWnd);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setMaximumSize(QSize(130, 16777215));
        horizontalSlider->setMinimum(5);
        horizontalSlider->setMaximum(40);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(graphWnd);

        QMetaObject::connectSlotsByName(graphWnd);
    } // setupUi

    void retranslateUi(QWidget *graphWnd)
    {
        graphWnd->setWindowTitle(QApplication::translate("graphWnd", "Graphs", 0));
        label_2->setText(QApplication::translate("graphWnd", "Select graph:", 0));
        pB_draw->setText(QApplication::translate("graphWnd", "Clear", 0));
        label_3->setText(QApplication::translate("graphWnd", "Size: 0 kB", 0));
        checkBox->setText(QApplication::translate("graphWnd", "Adaptive View", 0));
        label->setText(QApplication::translate("graphWnd", "Adjust time window width", 0));
    } // retranslateUi

};

namespace Ui {
    class graphWnd: public Ui_graphWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWND_H
