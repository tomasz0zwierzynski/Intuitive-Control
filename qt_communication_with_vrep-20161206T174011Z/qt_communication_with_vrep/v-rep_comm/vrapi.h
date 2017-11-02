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
    explicit vrapi(bool* me,simData * vrep_d, QObject *parent = 0, int ofs = 5);

signals:
    void finished();
    void error(QString err);

public slots:
    void process();


private:
    int portNb;
    int clientID;

    QMutex locker;

    simData *simD;

    bool * motion_event;

    const int offsleep;

    float ik_target_vel[3];

    void simQGetAllHandles();
    //void simQinitializeTip();
    //void simQinitializeTarget();
    void simQInitializeStream();
    bool simQReadFromStream();
    void simQProcessMotion();
    void simQSetDummyPositionOrientation(vrepDummy *);
    void getPortNbFromFile();


};

#endif // VRAPI_H
