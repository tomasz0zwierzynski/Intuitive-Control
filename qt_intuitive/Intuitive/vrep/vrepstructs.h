#ifndef VREPSTRUCTS_H
#define VREPSTRUCTS_H

struct vrepJoint
{
   int handle;
   float position;
   float force;
};

struct vrepDummy
{
   int handle;
   float position[3];
   float orientation[3];
};

struct vrepVelocity
{
   float linear[3];
   float angular[3];
   int dt;
};

struct vrepGripper
{
   int motorHandle;
   int attachPointHandle;
   //int
   // . . .
};

#endif // VREPSTRUCTS_H
