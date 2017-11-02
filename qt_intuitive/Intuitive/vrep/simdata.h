#ifndef SIMDATA_H
#define SIMDATA_H

#include <QVector>
#include "vrepstructs.h"

class simData
{
public:
    simData();
    QVector<vrepJoint> Q;
    QVector<vrepJoint> Act;
    vrepDummy tipB;
    vrepDummy tipL;
    vrepDummy targetB;
    vrepDummy targetL;
    vrepVelocity velocity;
    vrepGripper gripper;
    int base_frame;
    int link6_frame;
};

#endif // SIMDATA_H
