#ifndef SIMHANDLER_H
#define SIMHANDLER_H

#include <QObject>

#include "vrapi.h"
#include "simdata.h"

class SimHandler : public QObject
{
    Q_OBJECT
public:
    explicit SimHandler(QObject *parent = 0);

signals:
    //void error
    void stream_from_vrep(float*,int);

public slots:
    void on_setup_finished(QString dir, QString sce, int ofs);

    void on_velocities_changed(double *,int);

    void on_motion_event_change(bool);

    void on_gripper_action(bool);

    void on_sim_stop();

    void on_stream_from_vrep(float*,int);

private:
    vrapi* vrep_api;
    QThread* vrep_thread;

    QString vrep_dir;
    QString scene_file;

    simData vrep_data;
    bool motion_event;
    bool open_close_gripper;
    int motion_type;    //0 - relative to base; 1 - relative to tip
};

#endif // SIMHANDLER_H
