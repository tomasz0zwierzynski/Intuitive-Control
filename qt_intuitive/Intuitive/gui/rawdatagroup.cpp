#include "rawdatagroup.h"
#include "3Dmouse/mousedata.h"
#include "gui/hgui.h"

#include <QDebug>
#include <cmath>

RawDataGroup::RawDataGroup(hGUI handles,QObject *parent) : QObject(parent)
{
    ui = handles;
    relative_to_tip = false;

    connect(ui.rB_base,SIGNAL(toggled(bool)),this,SLOT(on_radio_button_change()));
    //connect(ui.rB_tip,SIGNAL(toggled(bool)),this,SLOT(on_radio_button_change()));
    connect(ui.cB_enable,SIGNAL(toggled(bool)),this,SLOT(on_enable_checkbox()));

    connect(ui.vS_all,SIGNAL(valueChanged(int)),this,SLOT(on_any_gain_change()));
    for (int i=0;i<6;i++)
        connect(ui.axes.at(i).vS_value,SIGNAL(valueChanged(int)),this,SLOT(on_any_gain_change()));

    connect(ui.pB_all_lock_ABC,SIGNAL(toggled(bool)),this,SLOT(on_any_lock_button_change()));
    connect(ui.pB_all_lock_XYZ,SIGNAL(toggled(bool)),this,SLOT(on_any_lock_button_change()));
    connect(ui.pB_all_11,SIGNAL(clicked(bool)),this,SLOT(on_all_11_button_clicked()));
    connect(ui.pB_all_2x,SIGNAL(clicked(bool)),this,SLOT(on_all_2x_button_clicked()));
    connect(ui.pB_all_5x,SIGNAL(clicked(bool)),this,SLOT(on_all_5x_button_clicked()));
    for (int i=0;i<6;i++)
    {
        connect(ui.axes.at(i).pB_lock,SIGNAL(toggled(bool)),this,SLOT(on_any_lock_button_change()));
    }

    connect(ui.axes.at(0).pB_11,SIGNAL(clicked(bool)),this,SLOT(on_a1_11_button_clicked()));
    connect(ui.axes.at(0).pB_2x,SIGNAL(clicked(bool)),this,SLOT(on_a1_2x_button_clicked()));
    connect(ui.axes.at(0).pB_5x,SIGNAL(clicked(bool)),this,SLOT(on_a1_5x_button_clicked()));

    connect(ui.axes.at(1).pB_11,SIGNAL(clicked(bool)),this,SLOT(on_a2_11_button_clicked()));
    connect(ui.axes.at(1).pB_2x,SIGNAL(clicked(bool)),this,SLOT(on_a2_2x_button_clicked()));
    connect(ui.axes.at(1).pB_5x,SIGNAL(clicked(bool)),this,SLOT(on_a2_5x_button_clicked()));

    connect(ui.axes.at(2).pB_11,SIGNAL(clicked(bool)),this,SLOT(on_a3_11_button_clicked()));
    connect(ui.axes.at(2).pB_2x,SIGNAL(clicked(bool)),this,SLOT(on_a3_2x_button_clicked()));
    connect(ui.axes.at(2).pB_5x,SIGNAL(clicked(bool)),this,SLOT(on_a3_5x_button_clicked()));

    connect(ui.axes.at(3).pB_11,SIGNAL(clicked(bool)),this,SLOT(on_a4_11_button_clicked()));
    connect(ui.axes.at(3).pB_2x,SIGNAL(clicked(bool)),this,SLOT(on_a4_2x_button_clicked()));
    connect(ui.axes.at(3).pB_5x,SIGNAL(clicked(bool)),this,SLOT(on_a4_5x_button_clicked()));

    connect(ui.axes.at(4).pB_11,SIGNAL(clicked(bool)),this,SLOT(on_a5_11_button_clicked()));
    connect(ui.axes.at(4).pB_2x,SIGNAL(clicked(bool)),this,SLOT(on_a5_2x_button_clicked()));
    connect(ui.axes.at(4).pB_5x,SIGNAL(clicked(bool)),this,SLOT(on_a5_5x_button_clicked()));

    connect(ui.axes.at(5).pB_11,SIGNAL(clicked(bool)),this,SLOT(on_a6_11_button_clicked()));
    connect(ui.axes.at(5).pB_2x,SIGNAL(clicked(bool)),this,SLOT(on_a6_2x_button_clicked()));
    connect(ui.axes.at(5).pB_5x,SIGNAL(clicked(bool)),this,SLOT(on_a6_5x_button_clicked()));

    for (int i=0;i<6;i++)
    {
        axis_gain[i] = 1;
        axis_lock[i] = false;
    }
    general_gain = 1;

}

void RawDataGroup::on_radio_button_change()
{
    //qDebug() << "changed";
    if(ui.rB_base->isChecked())
        relative_to_tip = false;
    else
        relative_to_tip = true;
}

void RawDataGroup::update_raw_labels()
{
    ui.label_raw.at(0)->setText(QString::number(mousedata.getTX()));
    ui.label_raw.at(1)->setText(QString::number(mousedata.getTY()));
    ui.label_raw.at(2)->setText(QString::number(mousedata.getTZ()));
    ui.label_raw.at(3)->setText(QString::number(mousedata.getRX()));
    ui.label_raw.at(4)->setText(QString::number(mousedata.getRY()));
    ui.label_raw.at(5)->setText(QString::number(mousedata.getRZ()));
    if (mousedata.getLBS()==0)
        ui.label_left->setText("LB Released");
    else
        ui.label_left->setText("LB Pressed");
    if (mousedata.getRBS()==0)
        ui.label_right->setText("RB Released");
    else
        ui.label_right->setText("RB Pressed");
}

void RawDataGroup::new_mouse_data(MouseData * md)
{
    mousedata = *md;
    this->update_raw_labels();

    process_velocities();
}

void RawDataGroup::process_velocities()
{
    /*Will be in another place*/
    if (motion_enabled)
    {
        int motion[6] = {mousedata.getTX(),mousedata.getTZ(),mousedata.getTY(),mousedata.getRX(),mousedata.getRZ(),mousedata.getRY()};

        for (int i=0;i<6;i++)
        {
            if (motion[i]<100 && motion[i]>-100)
                motion[i]=0;
        }

        if (relative_to_tip)
        {
            for (int i=0;i<3;i++)
            {
                if (axis_lock[i])
                    output_velocities_tip[i] = 0;
                else
                    output_velocities_tip[i] = general_gain * axis_gain[i] * (motion[i] /1.0);
            }
            for (int i=3;i<6;i++)
            {
                if (axis_lock[i])
                    output_velocities_tip[i] = 0;
                else
                    output_velocities_tip[i] = general_gain * axis_gain[i] * (motion[i] /1.0);
            }

            if (output_velocities_tip[0]+output_velocities_tip[1]+output_velocities_tip[2]+output_velocities_tip[3]+output_velocities_tip[4]+output_velocities_tip[5]==0)
                emit motion_type_changed(false);
            else
                emit motion_type_changed(true);

            emit new_output_data(output_velocities_tip,1);

        }else{

            for (int i=0;i<6;i++)
            {
                if (axis_lock[i])
                    output_velocities_base[i] = 0;
                else
                    output_velocities_base[i] = general_gain * axis_gain[i] * (motion[i] /5.0);
            }
            for (int i=3;i<6;i++)
            {
                if (axis_lock[i])
                    output_velocities_base[i] = 0;
                else
                    output_velocities_base[i] = general_gain * axis_gain[i] * (motion[i] /0.5);
            }

            if (output_velocities_base[0]+output_velocities_base[1]+output_velocities_base[2]+output_velocities_base[3]+output_velocities_base[4]+output_velocities_base[5]==0)
                emit motion_type_changed(false);
            else
                emit motion_type_changed(true);


             emit new_output_data(output_velocities_base,0);

        }

        if (mousedata.getLBS() == 1)
            on_left_button();
        if (mousedata.getRBS() == 1)
            on_right_button();
    }
}

/*
void RawDataGroup::send_velocities_to_vrep()
{

}
*/

void RawDataGroup::on_any_gain_change()
{
    general_gain = gainFromSlider(ui.vS_all->value());
    ui.label_all->setText(QString::number(general_gain,'g',2));
    for (int i=0;i<6;i++)
    {
        axis_gain[i] = gainFromSlider(ui.axes.at(i).vS_value->value());
        ui.axes.at(i).lab_value->setText(QString::number(axis_gain[i],'g',2));
    }
}

void RawDataGroup::on_any_lock_button_change()
{
    for (int i=0;i<6;i++)
    {
        if (ui.axes.at(i).pB_lock->isChecked())
        {
            axis_lock[i] = true;
        }else{
            axis_lock[i] = false;
        }
    }

    if (ui.pB_all_lock_XYZ->isChecked() || ui.pB_all_lock_ABC->isChecked())
    {
        if (ui.pB_all_lock_XYZ->isChecked())
        {
            axis_lock[0] = true;
            axis_lock[1] = true;
            axis_lock[2] = true;
        }else{
            axis_lock[0] = false;
            axis_lock[1] = false;
            axis_lock[2] = false;
        }

        if (ui.pB_all_lock_ABC->isChecked())
        {
            axis_lock[3] = true;
            axis_lock[4] = true;
            axis_lock[5] = true;
        }else{
            axis_lock[3] = false;
            axis_lock[4] = false;
            axis_lock[5] = false;
        }
    }

}

void RawDataGroup::on_enable_checkbox()
{
    if (ui.cB_enable->isChecked())
        motion_enabled = true;
    else
        motion_enabled = false;
}

void RawDataGroup::on_left_button()
{
     emit gripper_open_close(false);
}

void RawDataGroup::on_right_button()
{
     emit gripper_open_close(true);
}

double RawDataGroup::gainFromSlider(int reading)
{
    return pow(4.0,((reading-50.0)/50.0))+0.01;
}

void RawDataGroup::on_all_11_button_clicked()
{
    ui.vS_all->setValue(50);
}
void RawDataGroup::on_all_2x_button_clicked()
{
    ui.vS_all->setValue(75);
}
void RawDataGroup::on_all_5x_button_clicked()
{
    ui.vS_all->setValue(24);
}

void RawDataGroup::on_a1_11_button_clicked()
{
    ui.axes.at(0).vS_value->setValue(50);
}
void RawDataGroup::on_a1_2x_button_clicked()
{
    ui.axes.at(0).vS_value->setValue(75);
}
void RawDataGroup::on_a1_5x_button_clicked()
{
    ui.axes.at(0).vS_value->setValue(24);
}

void RawDataGroup::on_a2_11_button_clicked()
{
    ui.axes.at(1).vS_value->setValue(50);
}
void RawDataGroup::on_a2_2x_button_clicked()
{
    ui.axes.at(1).vS_value->setValue(75);
}
void RawDataGroup::on_a2_5x_button_clicked()
{
    ui.axes.at(1).vS_value->setValue(24);
}

void RawDataGroup::on_a3_11_button_clicked()
{
    ui.axes.at(2).vS_value->setValue(50);
}
void RawDataGroup::on_a3_2x_button_clicked()
{
    ui.axes.at(2).vS_value->setValue(75);
}
void RawDataGroup::on_a3_5x_button_clicked()
{
    ui.axes.at(2).vS_value->setValue(24);
}

void RawDataGroup::on_a4_11_button_clicked()
{
    ui.axes.at(3).vS_value->setValue(50);
}
void RawDataGroup::on_a4_2x_button_clicked()
{
    ui.axes.at(3).vS_value->setValue(75);
}
void RawDataGroup::on_a4_5x_button_clicked()
{
    ui.axes.at(3).vS_value->setValue(24);
}

void RawDataGroup::on_a5_11_button_clicked()
{
    ui.axes.at(4).vS_value->setValue(50);
}
void RawDataGroup::on_a5_2x_button_clicked()
{
    ui.axes.at(4).vS_value->setValue(75);
}
void RawDataGroup::on_a5_5x_button_clicked()
{
    ui.axes.at(4).vS_value->setValue(24);
}

void RawDataGroup::on_a6_11_button_clicked()
{
    ui.axes.at(5).vS_value->setValue(50);
}
void RawDataGroup::on_a6_2x_button_clicked()
{
    ui.axes.at(5).vS_value->setValue(75);
}
void RawDataGroup::on_a6_5x_button_clicked()
{
    ui.axes.at(5).vS_value->setValue(24);
}
