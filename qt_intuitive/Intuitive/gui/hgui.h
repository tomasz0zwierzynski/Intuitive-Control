#ifndef HGUI_H
#define HGUI_H

#include <QVector>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>

struct hCtrGroup
{
    QGroupBox * gB_axes;
    QPushButton * pB_11;
    QPushButton * pB_2x;
    QPushButton * pB_5x;
    QPushButton * pB_lock;
    QSlider * vS_value;
    QLabel * lab_value;
};


class hGUI
{
public:
    hGUI();
    QVector<hCtrGroup>axes;
    QGroupBox * gB_in;
    QGroupBox * gB_adv;
    QGroupBox * gB_control;
    QGroupBox * gB_relativity;

    QVector<QLabel*>label_raw;
    QLabel* label_left;
    QLabel* label_right;

    QCheckBox * cB_enable;
    QRadioButton * rB_base;
    QRadioButton * rB_tip;

    QPushButton * pB_all_11;
    QPushButton * pB_all_2x;
    QPushButton * pB_all_5x;
    QPushButton * pB_all_lock_ABC;
    QPushButton * pB_all_lock_XYZ;
    QSlider * vS_all;
    QLabel * label_all;
};

#endif // HGUI_H
