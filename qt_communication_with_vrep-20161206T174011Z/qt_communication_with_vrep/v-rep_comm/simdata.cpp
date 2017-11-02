#include "simdata.h"

#include <QVector>
#include "vrepstructs.h"

simData::simData()
{
    vrepJoint zeroJoint = {0,0,0};
    for (int i=0; i<6; i++)
        this->Q.append(zeroJoint);
    for (int i=0; i<3; i++)
        this->Act.append(zeroJoint);
    vrepDummy zeroPoint = {0,{0,0,0},{0,0,0}};
    this->tip = zeroPoint;
    this->target = zeroPoint;
    vrepVelocity zeroSpeed = {{0,0,0},{0,0,0},50};
    this->velocity = zeroSpeed;
    vrepGripper zeroGrip = {0,0};
    this->gripper = zeroGrip;

    this->relative_to_object = 0;
    this->frames.append(0);
    this->frames.append(0);
}
