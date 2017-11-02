#ifndef VRAPI_H
#define VRAPI_H

#include "simdata.h"

#include <QObject>
#include <QString>
#include <QMutex>

class vrapi : public QObject
{
    Q_OBJECT
public:
    explicit vrapi(bool * oc,int * mt,bool* me,simData * vrep_d, QObject *parent, int ofs);

signals:
    void finished();
    void error(QString err);

    void vrep_stream(float *,int);

public slots:
    void process();


private:
    int portNb;
    int clientID;

    QMutex locker;

    simData *simD;
    bool * motion_event;
    int * motion_type;
    bool * open_close_gripper;

    const int offsleep;

    float ik_target_vel[3];

    void simQGetAllHandles();
    void simQInitializeStream();
    bool simQReadFromStream();
    void simQProcessMotion(int);
    void simQSetDummyPositionOrientation(int);
    void getPortNbFromFile();

    void prepareStreamArray(float*);

};

#endif // VRAPI_H
