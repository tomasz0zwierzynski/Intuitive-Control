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
    vrepDummy tip;
    vrepDummy target;
    vrepVelocity velocity;
    vrepGripper gripper;
    int relative_to_object;
    QVector<int> frames;
};

#endif // SIMDATA_H
