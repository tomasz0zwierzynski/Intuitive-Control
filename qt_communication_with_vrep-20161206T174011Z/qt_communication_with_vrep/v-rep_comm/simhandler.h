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
public slots:
    void on_setup_finished(QString dir, QString sce, int ofs);

    void on_velocities_changed(double *,int);

    void on_motion_event_change(bool);

private:
    vrapi* vrep_api;
    QThread* vrep_thread;

    QString vrep_dir;
    QString scene_file;

    simData vrep_data;
    bool motion_event;
};

#endif // SIMHANDLER_H
