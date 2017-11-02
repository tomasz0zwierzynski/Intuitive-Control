#ifndef RAWDATAGROUP_H
#define RAWDATAGROUP_H

#include <QObject>
#include <QLabel>
#include <QVector>
#include "3Dmouse/mousedata.h"
#include "gui/hgui.h"


class RawDataGroup : public QObject
{
    Q_OBJECT
public:
    explicit RawDataGroup(hGUI handles,QObject *parent = 0);

signals:
    void new_output_data(double*,int);
    void motion_type_changed(bool);
    void gripper_open_close(bool);

public slots:
    void new_mouse_data(MouseData *);
    void update_raw_labels();

    void on_left_button();
    void on_right_button();

    void on_radio_button_change();
    void on_enable_checkbox();
    void on_any_gain_change();
    void on_any_lock_button_change();

    void on_all_11_button_clicked();
    void on_all_2x_button_clicked();
    void on_all_5x_button_clicked();

    void on_a1_11_button_clicked();
    void on_a2_11_button_clicked();
    void on_a3_11_button_clicked();
    void on_a4_11_button_clicked();
    void on_a5_11_button_clicked();
    void on_a6_11_button_clicked();

    void on_a1_2x_button_clicked();
    void on_a2_2x_button_clicked();
    void on_a3_2x_button_clicked();
    void on_a4_2x_button_clicked();
    void on_a5_2x_button_clicked();
    void on_a6_2x_button_clicked();

    void on_a1_5x_button_clicked();
    void on_a2_5x_button_clicked();
    void on_a3_5x_button_clicked();
    void on_a4_5x_button_clicked();
    void on_a5_5x_button_clicked();
    void on_a6_5x_button_clicked();

    void process_velocities();
    //void send_velocities_to_vrep();

private:
    hGUI ui;

    MouseData mousedata;
    bool relative_to_tip;
    bool motion_enabled;
    double output_velocities_base[6];
    double output_velocities_tip[6];

    double axis_gain[6];
    bool axis_lock[6];
    double general_gain;

    double gainFromSlider(int reading);
};

#endif // RAWDATAGROUP_H
