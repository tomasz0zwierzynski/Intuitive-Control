/********************************************************************************
** Form generated from reading UI file 'mwnd.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWND_H
#define UI_MWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mWnd
{
public:
    QAction *actionClose_Application;
    QAction *actionRun_simulation;
    QAction *actionStop_simulation;
    QAction *actionSettings;
    QAction *actionAbout;
    QAction *actionShow_logs;
    QAction *actionRestart_Application;
    QAction *actionShow_graphs;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_10;
    QFrame *frame;
    QGroupBox *gB_in;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_raw_x;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_raw_y;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_raw_z;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_raw_a;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *label_raw_b;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *label_raw_c;
    QLabel *label_raw_left;
    QLabel *label_raw_right;
    QSpacerItem *verticalSpacer_9;
    QGroupBox *gB_control;
    QCheckBox *cB_enable;
    QGroupBox *gB_relativity;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *rB_base;
    QRadioButton *rB_tip;
    QGroupBox *gB_adv;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *gB_X;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QSlider *vS_X;
    QLabel *lab_X;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pB_X_lock;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pB_X_2x;
    QPushButton *pB_X_11;
    QPushButton *pB_X_5x;
    QGroupBox *gB_Y;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_9;
    QSlider *vS_Y;
    QLabel *lab_Y;
    QVBoxLayout *verticalLayout_10;
    QPushButton *pB_Y_lock;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pB_Y_2x;
    QPushButton *pB_Y_11;
    QPushButton *pB_Y_5x;
    QGroupBox *gB_Z;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QSlider *vS_Z;
    QLabel *lab_Z;
    QVBoxLayout *verticalLayout_12;
    QPushButton *pB_Z_lock;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pB_Z_2x;
    QPushButton *pB_Z_11;
    QPushButton *pB_Z_5x;
    QWidget *tab_2;
    QGroupBox *gB_C;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_13;
    QSlider *vS_C;
    QLabel *lab_C;
    QVBoxLayout *verticalLayout_14;
    QPushButton *pB_C_lock;
    QSpacerItem *verticalSpacer_6;
    QPushButton *pB_C_2x;
    QPushButton *pB_C_11;
    QPushButton *pB_C_5x;
    QGroupBox *gB_A;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_15;
    QSlider *vS_A;
    QLabel *lab_A;
    QVBoxLayout *verticalLayout_16;
    QPushButton *pB_A_lock;
    QSpacerItem *verticalSpacer_7;
    QPushButton *pB_A_2x;
    QPushButton *pB_A_11;
    QPushButton *pB_A_5x;
    QGroupBox *gB_B;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_17;
    QSlider *vS_B;
    QLabel *lab_B;
    QVBoxLayout *verticalLayout_18;
    QPushButton *pB_B_lock;
    QSpacerItem *verticalSpacer_8;
    QPushButton *pB_B_2x;
    QPushButton *pB_B_11;
    QPushButton *pB_B_5x;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QSlider *vS_gen;
    QLabel *lab_gen;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pB_gen_lock_XYZ;
    QPushButton *pB_gen_lock_ABC;
    QSpacerItem *verticalSpacer;
    QPushButton *pB_gen_2x;
    QPushButton *pB_gen_11;
    QPushButton *pB_gen_5x;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_17;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mWnd)
    {
        if (mWnd->objectName().isEmpty())
            mWnd->setObjectName(QStringLiteral("mWnd"));
        mWnd->resize(876, 475);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mWnd->sizePolicy().hasHeightForWidth());
        mWnd->setSizePolicy(sizePolicy);
        mWnd->setMinimumSize(QSize(868, 475));
        mWnd->setMaximumSize(QSize(16777215, 475));
        actionClose_Application = new QAction(mWnd);
        actionClose_Application->setObjectName(QStringLiteral("actionClose_Application"));
        actionRun_simulation = new QAction(mWnd);
        actionRun_simulation->setObjectName(QStringLiteral("actionRun_simulation"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/resources/run.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun_simulation->setIcon(icon);
        actionStop_simulation = new QAction(mWnd);
        actionStop_simulation->setObjectName(QStringLiteral("actionStop_simulation"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/resources/stop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop_simulation->setIcon(icon1);
        actionSettings = new QAction(mWnd);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/resources/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon2);
        actionAbout = new QAction(mWnd);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionShow_logs = new QAction(mWnd);
        actionShow_logs->setObjectName(QStringLiteral("actionShow_logs"));
        actionRestart_Application = new QAction(mWnd);
        actionRestart_Application->setObjectName(QStringLiteral("actionRestart_Application"));
        actionShow_graphs = new QAction(mWnd);
        actionShow_graphs->setObjectName(QStringLiteral("actionShow_graphs"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/resources/graph.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow_graphs->setIcon(icon3);
        centralWidget = new QWidget(mWnd);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_16 = new QHBoxLayout(centralWidget);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(711, 381));
        frame->setMaximumSize(QSize(711, 381));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gB_in = new QGroupBox(frame);
        gB_in->setObjectName(QStringLiteral("gB_in"));
        gB_in->setGeometry(QRect(0, 0, 141, 381));
        sizePolicy1.setHeightForWidth(gB_in->sizePolicy().hasHeightForWidth());
        gB_in->setSizePolicy(sizePolicy1);
        gB_in->setMinimumSize(QSize(141, 381));
        gB_in->setSizeIncrement(QSize(141, 381));
        QFont font;
        font.setPointSize(10);
        gB_in->setFont(font);
        layoutWidget = new QWidget(gB_in);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 121, 341));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        label_raw_x = new QLabel(layoutWidget);
        label_raw_x->setObjectName(QStringLiteral("label_raw_x"));
        label_raw_x->setFont(font1);
        label_raw_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_raw_x);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        label_raw_y = new QLabel(layoutWidget);
        label_raw_y->setObjectName(QStringLiteral("label_raw_y"));
        label_raw_y->setFont(font1);
        label_raw_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_raw_y);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        label_raw_z = new QLabel(layoutWidget);
        label_raw_z->setObjectName(QStringLiteral("label_raw_z"));
        label_raw_z->setFont(font1);
        label_raw_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_raw_z);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        label_raw_a = new QLabel(layoutWidget);
        label_raw_a->setObjectName(QStringLiteral("label_raw_a"));
        label_raw_a->setFont(font1);
        label_raw_a->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_raw_a);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_5->addWidget(label_5);

        label_raw_b = new QLabel(layoutWidget);
        label_raw_b->setObjectName(QStringLiteral("label_raw_b"));
        label_raw_b->setFont(font1);
        label_raw_b->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_raw_b);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_6->addWidget(label_6);

        label_raw_c = new QLabel(layoutWidget);
        label_raw_c->setObjectName(QStringLiteral("label_raw_c"));
        label_raw_c->setFont(font1);
        label_raw_c->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_raw_c);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);

        label_raw_left = new QLabel(layoutWidget);
        label_raw_left->setObjectName(QStringLiteral("label_raw_left"));
        label_raw_left->setFont(font1);

        verticalLayout_2->addWidget(label_raw_left);

        label_raw_right = new QLabel(layoutWidget);
        label_raw_right->setObjectName(QStringLiteral("label_raw_right"));
        label_raw_right->setFont(font1);

        verticalLayout_2->addWidget(label_raw_right);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_9);

        gB_control = new QGroupBox(frame);
        gB_control->setObjectName(QStringLiteral("gB_control"));
        gB_control->setGeometry(QRect(150, 0, 551, 381));
        sizePolicy1.setHeightForWidth(gB_control->sizePolicy().hasHeightForWidth());
        gB_control->setSizePolicy(sizePolicy1);
        gB_control->setMinimumSize(QSize(551, 381));
        gB_control->setMaximumSize(QSize(551, 381));
        gB_control->setFont(font);
        cB_enable = new QCheckBox(gB_control);
        cB_enable->setObjectName(QStringLiteral("cB_enable"));
        cB_enable->setGeometry(QRect(20, 30, 201, 31));
        cB_enable->setChecked(true);
        gB_relativity = new QGroupBox(gB_control);
        gB_relativity->setObjectName(QStringLiteral("gB_relativity"));
        gB_relativity->setGeometry(QRect(230, 10, 311, 61));
        layoutWidget1 = new QWidget(gB_relativity);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 241, 22));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        rB_base = new QRadioButton(layoutWidget1);
        rB_base->setObjectName(QStringLiteral("rB_base"));
        rB_base->setChecked(true);

        horizontalLayout_7->addWidget(rB_base);

        rB_tip = new QRadioButton(layoutWidget1);
        rB_tip->setObjectName(QStringLiteral("rB_tip"));

        horizontalLayout_7->addWidget(rB_tip);

        gB_adv = new QGroupBox(gB_control);
        gB_adv->setObjectName(QStringLiteral("gB_adv"));
        gB_adv->setGeometry(QRect(10, 80, 531, 291));
        tabWidget = new QTabWidget(gB_adv);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(130, 30, 391, 231));
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gB_X = new QGroupBox(tab);
        gB_X->setObjectName(QStringLiteral("gB_X"));
        gB_X->setGeometry(QRect(0, 0, 121, 191));
        layoutWidget_2 = new QWidget(gB_X);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 109, 164));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        vS_X = new QSlider(layoutWidget_2);
        vS_X->setObjectName(QStringLiteral("vS_X"));
        vS_X->setMaximum(100);
        vS_X->setValue(50);
        vS_X->setOrientation(Qt::Vertical);

        verticalLayout_5->addWidget(vS_X);

        lab_X = new QLabel(layoutWidget_2);
        lab_X->setObjectName(QStringLiteral("lab_X"));
        lab_X->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lab_X);


        horizontalLayout_9->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        pB_X_lock = new QPushButton(layoutWidget_2);
        pB_X_lock->setObjectName(QStringLiteral("pB_X_lock"));
        pB_X_lock->setCheckable(true);

        verticalLayout_6->addWidget(pB_X_lock);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        pB_X_2x = new QPushButton(layoutWidget_2);
        pB_X_2x->setObjectName(QStringLiteral("pB_X_2x"));

        verticalLayout_6->addWidget(pB_X_2x);

        pB_X_11 = new QPushButton(layoutWidget_2);
        pB_X_11->setObjectName(QStringLiteral("pB_X_11"));

        verticalLayout_6->addWidget(pB_X_11);

        pB_X_5x = new QPushButton(layoutWidget_2);
        pB_X_5x->setObjectName(QStringLiteral("pB_X_5x"));

        verticalLayout_6->addWidget(pB_X_5x);


        horizontalLayout_9->addLayout(verticalLayout_6);

        gB_Y = new QGroupBox(tab);
        gB_Y->setObjectName(QStringLiteral("gB_Y"));
        gB_Y->setGeometry(QRect(130, 0, 121, 191));
        layoutWidget_4 = new QWidget(gB_Y);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 20, 109, 164));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        vS_Y = new QSlider(layoutWidget_4);
        vS_Y->setObjectName(QStringLiteral("vS_Y"));
        vS_Y->setMaximum(100);
        vS_Y->setValue(50);
        vS_Y->setOrientation(Qt::Vertical);

        verticalLayout_9->addWidget(vS_Y);

        lab_Y = new QLabel(layoutWidget_4);
        lab_Y->setObjectName(QStringLiteral("lab_Y"));
        lab_Y->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(lab_Y);


        horizontalLayout_11->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        pB_Y_lock = new QPushButton(layoutWidget_4);
        pB_Y_lock->setObjectName(QStringLiteral("pB_Y_lock"));
        pB_Y_lock->setCheckable(true);

        verticalLayout_10->addWidget(pB_Y_lock);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_4);

        pB_Y_2x = new QPushButton(layoutWidget_4);
        pB_Y_2x->setObjectName(QStringLiteral("pB_Y_2x"));

        verticalLayout_10->addWidget(pB_Y_2x);

        pB_Y_11 = new QPushButton(layoutWidget_4);
        pB_Y_11->setObjectName(QStringLiteral("pB_Y_11"));

        verticalLayout_10->addWidget(pB_Y_11);

        pB_Y_5x = new QPushButton(layoutWidget_4);
        pB_Y_5x->setObjectName(QStringLiteral("pB_Y_5x"));

        verticalLayout_10->addWidget(pB_Y_5x);


        horizontalLayout_11->addLayout(verticalLayout_10);

        gB_Z = new QGroupBox(tab);
        gB_Z->setObjectName(QStringLiteral("gB_Z"));
        gB_Z->setGeometry(QRect(260, 0, 121, 191));
        layoutWidget_5 = new QWidget(gB_Z);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 20, 109, 164));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        vS_Z = new QSlider(layoutWidget_5);
        vS_Z->setObjectName(QStringLiteral("vS_Z"));
        vS_Z->setMaximum(100);
        vS_Z->setValue(50);
        vS_Z->setOrientation(Qt::Vertical);

        verticalLayout_11->addWidget(vS_Z);

        lab_Z = new QLabel(layoutWidget_5);
        lab_Z->setObjectName(QStringLiteral("lab_Z"));
        lab_Z->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(lab_Z);


        horizontalLayout_12->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        pB_Z_lock = new QPushButton(layoutWidget_5);
        pB_Z_lock->setObjectName(QStringLiteral("pB_Z_lock"));
        pB_Z_lock->setCheckable(true);

        verticalLayout_12->addWidget(pB_Z_lock);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_5);

        pB_Z_2x = new QPushButton(layoutWidget_5);
        pB_Z_2x->setObjectName(QStringLiteral("pB_Z_2x"));

        verticalLayout_12->addWidget(pB_Z_2x);

        pB_Z_11 = new QPushButton(layoutWidget_5);
        pB_Z_11->setObjectName(QStringLiteral("pB_Z_11"));

        verticalLayout_12->addWidget(pB_Z_11);

        pB_Z_5x = new QPushButton(layoutWidget_5);
        pB_Z_5x->setObjectName(QStringLiteral("pB_Z_5x"));

        verticalLayout_12->addWidget(pB_Z_5x);


        horizontalLayout_12->addLayout(verticalLayout_12);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gB_C = new QGroupBox(tab_2);
        gB_C->setObjectName(QStringLiteral("gB_C"));
        gB_C->setGeometry(QRect(260, 0, 121, 191));
        layoutWidget_6 = new QWidget(gB_C);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 20, 109, 164));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        vS_C = new QSlider(layoutWidget_6);
        vS_C->setObjectName(QStringLiteral("vS_C"));
        vS_C->setMaximum(100);
        vS_C->setValue(50);
        vS_C->setOrientation(Qt::Vertical);

        verticalLayout_13->addWidget(vS_C);

        lab_C = new QLabel(layoutWidget_6);
        lab_C->setObjectName(QStringLiteral("lab_C"));
        lab_C->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(lab_C);


        horizontalLayout_13->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        pB_C_lock = new QPushButton(layoutWidget_6);
        pB_C_lock->setObjectName(QStringLiteral("pB_C_lock"));
        pB_C_lock->setCheckable(true);

        verticalLayout_14->addWidget(pB_C_lock);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_14->addItem(verticalSpacer_6);

        pB_C_2x = new QPushButton(layoutWidget_6);
        pB_C_2x->setObjectName(QStringLiteral("pB_C_2x"));

        verticalLayout_14->addWidget(pB_C_2x);

        pB_C_11 = new QPushButton(layoutWidget_6);
        pB_C_11->setObjectName(QStringLiteral("pB_C_11"));

        verticalLayout_14->addWidget(pB_C_11);

        pB_C_5x = new QPushButton(layoutWidget_6);
        pB_C_5x->setObjectName(QStringLiteral("pB_C_5x"));

        verticalLayout_14->addWidget(pB_C_5x);


        horizontalLayout_13->addLayout(verticalLayout_14);

        gB_A = new QGroupBox(tab_2);
        gB_A->setObjectName(QStringLiteral("gB_A"));
        gB_A->setGeometry(QRect(0, 0, 121, 191));
        layoutWidget_7 = new QWidget(gB_A);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(10, 20, 109, 164));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        vS_A = new QSlider(layoutWidget_7);
        vS_A->setObjectName(QStringLiteral("vS_A"));
        vS_A->setMaximum(100);
        vS_A->setValue(50);
        vS_A->setOrientation(Qt::Vertical);

        verticalLayout_15->addWidget(vS_A);

        lab_A = new QLabel(layoutWidget_7);
        lab_A->setObjectName(QStringLiteral("lab_A"));
        lab_A->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(lab_A);


        horizontalLayout_14->addLayout(verticalLayout_15);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        pB_A_lock = new QPushButton(layoutWidget_7);
        pB_A_lock->setObjectName(QStringLiteral("pB_A_lock"));
        pB_A_lock->setCheckable(true);

        verticalLayout_16->addWidget(pB_A_lock);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_7);

        pB_A_2x = new QPushButton(layoutWidget_7);
        pB_A_2x->setObjectName(QStringLiteral("pB_A_2x"));

        verticalLayout_16->addWidget(pB_A_2x);

        pB_A_11 = new QPushButton(layoutWidget_7);
        pB_A_11->setObjectName(QStringLiteral("pB_A_11"));

        verticalLayout_16->addWidget(pB_A_11);

        pB_A_5x = new QPushButton(layoutWidget_7);
        pB_A_5x->setObjectName(QStringLiteral("pB_A_5x"));

        verticalLayout_16->addWidget(pB_A_5x);


        horizontalLayout_14->addLayout(verticalLayout_16);

        gB_B = new QGroupBox(tab_2);
        gB_B->setObjectName(QStringLiteral("gB_B"));
        gB_B->setGeometry(QRect(130, 0, 121, 191));
        layoutWidget_8 = new QWidget(gB_B);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(10, 20, 109, 164));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        vS_B = new QSlider(layoutWidget_8);
        vS_B->setObjectName(QStringLiteral("vS_B"));
        vS_B->setMaximum(100);
        vS_B->setValue(50);
        vS_B->setOrientation(Qt::Vertical);

        verticalLayout_17->addWidget(vS_B);

        lab_B = new QLabel(layoutWidget_8);
        lab_B->setObjectName(QStringLiteral("lab_B"));
        lab_B->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(lab_B);


        horizontalLayout_15->addLayout(verticalLayout_17);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        pB_B_lock = new QPushButton(layoutWidget_8);
        pB_B_lock->setObjectName(QStringLiteral("pB_B_lock"));
        pB_B_lock->setCheckable(true);

        verticalLayout_18->addWidget(pB_B_lock);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_18->addItem(verticalSpacer_8);

        pB_B_2x = new QPushButton(layoutWidget_8);
        pB_B_2x->setObjectName(QStringLiteral("pB_B_2x"));

        verticalLayout_18->addWidget(pB_B_2x);

        pB_B_11 = new QPushButton(layoutWidget_8);
        pB_B_11->setObjectName(QStringLiteral("pB_B_11"));

        verticalLayout_18->addWidget(pB_B_11);

        pB_B_5x = new QPushButton(layoutWidget_8);
        pB_B_5x->setObjectName(QStringLiteral("pB_B_5x"));

        verticalLayout_18->addWidget(pB_B_5x);


        horizontalLayout_15->addLayout(verticalLayout_18);

        tabWidget->addTab(tab_2, QString());
        layoutWidget2 = new QWidget(gB_adv);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 30, 111, 231));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        vS_gen = new QSlider(layoutWidget2);
        vS_gen->setObjectName(QStringLiteral("vS_gen"));
        vS_gen->setMaximum(100);
        vS_gen->setValue(50);
        vS_gen->setOrientation(Qt::Vertical);

        verticalLayout_3->addWidget(vS_gen);

        lab_gen = new QLabel(layoutWidget2);
        lab_gen->setObjectName(QStringLiteral("lab_gen"));
        lab_gen->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lab_gen);


        horizontalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pB_gen_lock_XYZ = new QPushButton(layoutWidget2);
        pB_gen_lock_XYZ->setObjectName(QStringLiteral("pB_gen_lock_XYZ"));
        pB_gen_lock_XYZ->setCheckable(true);

        verticalLayout_4->addWidget(pB_gen_lock_XYZ);

        pB_gen_lock_ABC = new QPushButton(layoutWidget2);
        pB_gen_lock_ABC->setObjectName(QStringLiteral("pB_gen_lock_ABC"));
        pB_gen_lock_ABC->setCheckable(true);

        verticalLayout_4->addWidget(pB_gen_lock_ABC);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        pB_gen_2x = new QPushButton(layoutWidget2);
        pB_gen_2x->setObjectName(QStringLiteral("pB_gen_2x"));

        verticalLayout_4->addWidget(pB_gen_2x);

        pB_gen_11 = new QPushButton(layoutWidget2);
        pB_gen_11->setObjectName(QStringLiteral("pB_gen_11"));

        verticalLayout_4->addWidget(pB_gen_11);

        pB_gen_5x = new QPushButton(layoutWidget2);
        pB_gen_5x->setObjectName(QStringLiteral("pB_gen_5x"));

        verticalLayout_4->addWidget(pB_gen_5x);


        horizontalLayout_8->addLayout(verticalLayout_4);


        horizontalLayout_10->addWidget(frame);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        horizontalLayout_17 = new QHBoxLayout(groupBox);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        treeWidget = new QTreeWidget(groupBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        horizontalLayout_17->addWidget(treeWidget);


        horizontalLayout_10->addWidget(groupBox);


        horizontalLayout_16->addLayout(horizontalLayout_10);

        mWnd->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mWnd);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 876, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        mWnd->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mWnd);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mWnd->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mWnd);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mWnd->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionRun_simulation);
        menuFile->addAction(actionStop_simulation);
        menuFile->addSeparator();
        menuFile->addAction(actionRestart_Application);
        menuFile->addAction(actionClose_Application);
        menuSettings->addAction(actionSettings);
        menuSettings->addAction(actionShow_logs);
        menuSettings->addAction(actionShow_graphs);
        menuSettings->addSeparator();
        menuSettings->addAction(actionAbout);
        mainToolBar->addAction(actionRun_simulation);
        mainToolBar->addAction(actionStop_simulation);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionShow_graphs);
        mainToolBar->addAction(actionSettings);

        retranslateUi(mWnd);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mWnd);
    } // setupUi

    void retranslateUi(QMainWindow *mWnd)
    {
        mWnd->setWindowTitle(QApplication::translate("mWnd", "Intuitive Control", 0));
        actionClose_Application->setText(QApplication::translate("mWnd", "Close Application", 0));
        actionRun_simulation->setText(QApplication::translate("mWnd", "Run simulation", 0));
        actionStop_simulation->setText(QApplication::translate("mWnd", "Stop simulation", 0));
        actionSettings->setText(QApplication::translate("mWnd", "Settings", 0));
        actionAbout->setText(QApplication::translate("mWnd", "About", 0));
        actionShow_logs->setText(QApplication::translate("mWnd", "Show logs", 0));
        actionRestart_Application->setText(QApplication::translate("mWnd", "Restart Application", 0));
        actionShow_graphs->setText(QApplication::translate("mWnd", "Show graphs", 0));
        gB_in->setTitle(QApplication::translate("mWnd", "3D mouse raw data", 0));
        label->setText(QApplication::translate("mWnd", "X:", 0));
        label_raw_x->setText(QApplication::translate("mWnd", "0", 0));
        label_2->setText(QApplication::translate("mWnd", "Y:", 0));
        label_raw_y->setText(QApplication::translate("mWnd", "0", 0));
        label_3->setText(QApplication::translate("mWnd", "Z:", 0));
        label_raw_z->setText(QApplication::translate("mWnd", "0", 0));
        label_4->setText(QApplication::translate("mWnd", "A:", 0));
        label_raw_a->setText(QApplication::translate("mWnd", "0", 0));
        label_5->setText(QApplication::translate("mWnd", "B:", 0));
        label_raw_b->setText(QApplication::translate("mWnd", "0", 0));
        label_6->setText(QApplication::translate("mWnd", "C:", 0));
        label_raw_c->setText(QApplication::translate("mWnd", "0", 0));
        label_raw_left->setText(QApplication::translate("mWnd", "LB Released", 0));
        label_raw_right->setText(QApplication::translate("mWnd", "PB Released", 0));
        gB_control->setTitle(QApplication::translate("mWnd", "Control settings", 0));
        cB_enable->setText(QApplication::translate("mWnd", "enable 3Dconnexion control", 0));
        gB_relativity->setTitle(QApplication::translate("mWnd", "Motion is relative to:", 0));
        rB_base->setText(QApplication::translate("mWnd", "Base frame", 0));
        rB_tip->setText(QApplication::translate("mWnd", "Wrist frame", 0));
        gB_adv->setTitle(QApplication::translate("mWnd", "Advanced velocity configuration", 0));
        gB_X->setTitle(QApplication::translate("mWnd", "X axis", 0));
        lab_X->setText(QApplication::translate("mWnd", "1", 0));
        pB_X_lock->setText(QApplication::translate("mWnd", "Lock", 0));
        pB_X_2x->setText(QApplication::translate("mWnd", "2 x", 0));
        pB_X_11->setText(QApplication::translate("mWnd", "1:1", 0));
        pB_X_5x->setText(QApplication::translate("mWnd", "0.5 x", 0));
        gB_Y->setTitle(QApplication::translate("mWnd", "Y axis", 0));
        lab_Y->setText(QApplication::translate("mWnd", "1", 0));
        pB_Y_lock->setText(QApplication::translate("mWnd", "Lock", 0));
        pB_Y_2x->setText(QApplication::translate("mWnd", "2 x", 0));
        pB_Y_11->setText(QApplication::translate("mWnd", "1:1", 0));
        pB_Y_5x->setText(QApplication::translate("mWnd", "0.5 x", 0));
        gB_Z->setTitle(QApplication::translate("mWnd", "Z axis", 0));
        lab_Z->setText(QApplication::translate("mWnd", "1", 0));
        pB_Z_lock->setText(QApplication::translate("mWnd", "Lock", 0));
        pB_Z_2x->setText(QApplication::translate("mWnd", "2 x", 0));
        pB_Z_11->setText(QApplication::translate("mWnd", "1:1", 0));
        pB_Z_5x->setText(QApplication::translate("mWnd", "0.5 x", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("mWnd", "Translation", 0));
        gB_C->setTitle(QApplication::translate("mWnd", "C axis", 0));
        lab_C->setText(QApplication::translate("mWnd", "0", 0));
        pB_C_lock->setText(QApplication::translate("mWnd", "Lock", 0));
        pB_C_2x->setText(QApplication::translate("mWnd", "2 x", 0));
        pB_C_11->setText(QApplication::translate("mWnd", "1:1", 0));
        pB_C_5x->setText(QApplication::translate("mWnd", "0.5 x", 0));
        gB_A->setTitle(QApplication::translate("mWnd", "A axis", 0));
        lab_A->setText(QApplication::translate("mWnd", "0", 0));
        pB_A_lock->setText(QApplication::translate("mWnd", "Lock", 0));
        pB_A_2x->setText(QApplication::translate("mWnd", "2 x", 0));
        pB_A_11->setText(QApplication::translate("mWnd", "1:1", 0));
        pB_A_5x->setText(QApplication::translate("mWnd", "0.5 x", 0));
        gB_B->setTitle(QApplication::translate("mWnd", "B axis", 0));
        lab_B->setText(QApplication::translate("mWnd", "0", 0));
        pB_B_lock->setText(QApplication::translate("mWnd", "Lock", 0));
        pB_B_2x->setText(QApplication::translate("mWnd", "2 x", 0));
        pB_B_11->setText(QApplication::translate("mWnd", "1:1", 0));
        pB_B_5x->setText(QApplication::translate("mWnd", "0.5 x", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("mWnd", "Rotational", 0));
        lab_gen->setText(QApplication::translate("mWnd", "1", 0));
        pB_gen_lock_XYZ->setText(QApplication::translate("mWnd", "Lock XYZ", 0));
        pB_gen_lock_ABC->setText(QApplication::translate("mWnd", "Lock ABC", 0));
        pB_gen_2x->setText(QApplication::translate("mWnd", "2 x", 0));
        pB_gen_11->setText(QApplication::translate("mWnd", "1:1", 0));
        pB_gen_5x->setText(QApplication::translate("mWnd", "0.5 x", 0));
        groupBox->setTitle(QApplication::translate("mWnd", "V-REP data stream", 0));
        menuFile->setTitle(QApplication::translate("mWnd", "File", 0));
        menuSettings->setTitle(QApplication::translate("mWnd", "More...", 0));
    } // retranslateUi

};

namespace Ui {
    class mWnd: public Ui_mWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWND_H
