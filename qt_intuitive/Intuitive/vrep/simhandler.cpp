#include "simhandler.h"

#include "vrapi.h"

#include <QDebug>
#include <QThread>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>
#include <QProcess>
#include <QMessageBox>

SimHandler::SimHandler(QObject *parent) : QObject(parent)
{
    qDebug() << "Sim handler created!";
    motion_event = false;
    motion_type = 0;
}

void SimHandler::on_setup_finished(QString dir, QString sce, int ofs)
{
    vrep_dir = dir;
    scene_file = sce;

    qDebug() << "starting v-rep thread";
    vrep_thread = new QThread;
    vrep_api = new vrapi(&open_close_gripper,&motion_type,&motion_event,&vrep_data,0,ofs);

    vrep_api->moveToThread(vrep_thread);
    connect(vrep_api, SIGNAL(error(QString)),this,SLOT(errorString(QString)));

    connect(vrep_thread, SIGNAL(started()),vrep_api,SLOT(process()));

    connect(vrep_api, SIGNAL(finished()), vrep_thread, SLOT(quit()));
    connect(vrep_api, SIGNAL(finished()), vrep_api, SLOT(deleteLater()));
    connect(vrep_thread, SIGNAL(finished()), vrep_thread, SLOT(deleteLater()));

    connect(vrep_api, SIGNAL(vrep_stream(float*,int)),this,SLOT(on_stream_from_vrep(float*,int)));

    vrep_thread->start();

    qDebug() << "starting v-rep thread";
    QString appDIR = QCoreApplication::applicationDirPath();

    //QString command = "vrep -gferst " + sim_file;
    QString command = "vrep -s -q -g" + appDIR + " " + scene_file;
    qDebug() << command;
    QDir::setCurrent(vrep_dir);
    if ( ! QProcess::startDetached(command) )
    {
        QMessageBox info;
        info.setText("Cannot find vrep.exe in specified folder!");
        info.setWindowTitle("Bad situation");
        info.exec();
        qDebug() << "Cannot find vrep.exe in specified folder!";
    }
    QDir::setCurrent(appDIR);

    qDebug() << "v-rep started";
}

void SimHandler::on_sim_stop()
{
    vrep_thread->terminate();
    vrep_thread->wait(1000);
    qDebug() << "wait done";
    delete vrep_thread;
    delete vrep_api;
}

void SimHandler::on_motion_event_change(bool b)
{
    motion_event = b;
}

void SimHandler::on_gripper_action(bool action)
{
    open_close_gripper = action;
}

void SimHandler::on_velocities_changed(double * data, int mode)
{   //add 'relative to' in signal args
    if (mode == 0) //it's realtive to world
    {
        //vrep_data.relative_to_object = vrep_data.frames.at(0);
        motion_type = 0;
    } else if (mode == 1) //it's relative to gripper
    {
        //vrep_data.relative_to_object = vrep_data.frames.at(1);
        motion_type = 1;
    }
    int dt = vrep_data.velocity.dt;
    vrep_data.velocity.linear[0] = (data[0]/1000.0)*dt*0.001;
    vrep_data.velocity.linear[1] = (data[1]/1000.0)*dt*0.001;
    vrep_data.velocity.linear[2] = (data[2]/1000.0)*dt*0.001;
    vrep_data.velocity.angular[0] = (data[3]/1000.0)*dt*0.001;
    vrep_data.velocity.angular[1] = (data[4]/1000.0)*dt*0.001;
    vrep_data.velocity.angular[2] = (data[5]/1000.0)*dt*0.001;

}

void SimHandler::on_stream_from_vrep(float * sdat,int time)
{
    emit stream_from_vrep(sdat,time);
}
