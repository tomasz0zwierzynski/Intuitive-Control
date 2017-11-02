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
    this->tipB = zeroPoint;
    this->targetB = zeroPoint;
    this->tipL = zeroPoint;
    this->targetL = zeroPoint;
    vrepVelocity zeroSpeed = {{0,0,0},{0,0,0},5};
    this->velocity = zeroSpeed;
    vrepGripper zeroGrip = {0,0};
    this->gripper = zeroGrip;
    this->base_frame = 0;
    this->link6_frame = 0;
}
