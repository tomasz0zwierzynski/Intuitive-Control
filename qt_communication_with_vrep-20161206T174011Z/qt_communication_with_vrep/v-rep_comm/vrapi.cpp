#include "vrapi.h"

extern "C" {
    #include "remoteApi/extApi.h"
}

#include "simdata.h"

#include <QDebug>
#include <QThread>
#include <QFile>
#include <QByteArray>
#include <QCoreApplication>
#include <QMessageBox>
#include <QMutex>

vrapi::vrapi(bool* me,simData * vrep_d, QObject *parent, int ofs) : QObject(parent),
    offsleep(ofs)
{
    simD = vrep_d;
    motion_event = me;
}

void vrapi::process()
{
    //Waiting some time to give v-rep chance to start simulation
    //TODO: Make check for file modiefied recently, so you now when to connect.
    QThread::sleep(offsleep);


    qDebug() << "Process() started...";
    qDebug() << "Reading portNb from file";
    getPortNbFromFile();
    qDebug() << portNb;

    qDebug() << "simxStart() calling...";
       clientID=simxStart((simxChar*)"127.0.0.1",portNb,true,true,2000,5);
           if (clientID!=-1)
           {
               qDebug() << "simxStarted()";
               //Initializing
               qDebug() << "Recieving handles and writing into structure";
               this->simQGetAllHandles();
               //Setting up default relative frame as base frame.
                      /*  int hand[6];
                        for (int i=0;i<6;i++)
                        {
                            simxGetObjectHandle(clientID,(const simxChar*)"Q2#",hand + i,simx_opmode_blocking);
                            qDebug() << i << ": From QGetAllHandles: " << simD->Q.at(i).handle;
                            qDebug() << i << ": From simxGetObjHnd: " << hand[i];
                        }
                        */
                        /****** Handles are correctly received ************/

               qDebug() << "Setting up default relative frame as base frame";
               simD->relative_to_object = simD->frames.at(1);
               //Starting data streaming from v-rep.
               qDebug() << "Init Streams";
               this->simQInitializeStream();
               //First read that initializes values in structures.
               QThread::msleep(100);
               qDebug() << "Read Streams";
               this->simQReadFromStream();
               qDebug() << "Stream red.";

               while (simxGetConnectionId(clientID)!=-1)
               {
                   //locker.lock();

                   this->simQReadFromStream();

                if (*motion_event == true)
                   //locker.unlock();
                {
                   this->simQProcessMotion();

                   //this->simQSetDummyPositionOrientation(&simD->target);
                   //qDebug() << "TARGET TIP: [ " << simD->target.position[0] << " , " << simD->target.position[1] << " , " << simD->target.position[2] << " ]";
                   //qDebug() << "TIP: [ " << simD->tip.position[0] << " , " << simD->tip.position[1] << " , " << simD->tip.position[2] << " ]";
                   this->simQSetDummyPositionOrientation(&simD->target);
                }

                   QThread::msleep(simD->velocity.dt);
               }
               simxFinish(clientID);
           }
}

void vrapi::getPortNbFromFile()
{
    //Getting v-rep extAPI server port number
    QFile dfile(QCoreApplication::applicationDirPath() + "//last_serv_parameters.txt");
    if (!dfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox info;
        info.setText("Cannot open parameters file. Try to set more delay time in settings.");
        info.setWindowTitle("Error");
        info.exec();
    }
    int i=1;
    while(!dfile.atEnd())
    {
        if (i==1)
        {
            QString temp = QString::fromLatin1(dfile.readLine());
            portNb = temp.toInt();
        }
        i++;
    }
}

void vrapi::simQInitializeStream()
{
    int rel = simD->relative_to_object;
    locker.lock();
    //Starting stream from v-rep
    //Stream from acts position and force
    for (int i=0;i<3;i++)
    {
        simxGetJointPosition(clientID,simD->Act.at(i).handle,const_cast<float*>(&(simD->Act.at(i).position)),simx_opmode_streaming);
        simxGetJointForce(clientID,simD->Act.at(i).handle,const_cast<float*>(&(simD->Act.at(i).force)),simx_opmode_streaming);
    }
    //Stream from Qs
    for (int i=0;i<6;i++)
    {
        simxGetJointPosition(clientID,simD->Q.at(i).handle,const_cast<float*>(&(simD->Q.at(i).position)),simx_opmode_streaming);
        simxGetJointForce(clientID,simD->Q.at(i).handle,const_cast<float*>(&(simD->Q.at(i).force)),simx_opmode_streaming);
    }
    //Stream from Tip-Target
    simxGetObjectPosition(clientID,simD->tip.handle,rel,simD->tip.position,simx_opmode_streaming);
    simxGetObjectPosition(clientID,simD->target.handle,rel,simD->target.position,simx_opmode_streaming);
    locker.unlock();
}

bool vrapi::simQReadFromStream()
{
    bool is_everything_ok = true;
    int rel = simD->relative_to_object;
    locker.lock();
    //Starting stream from v-rep
    //Stream from acts position and force
    for (int i=0;i<3;i++)
    {
        //if(simxGetJointPosition(clientID,simD->Act.at(i).handle,const_cast<float*>(&(simD->Act.at(i).position)),simx_opmode_buffer) != 0) is_everything_ok=false;
        simxGetJointPosition(clientID,simD->Act.at(i).handle,const_cast<float*>(&(simD->Act.at(i).position)),simx_opmode_buffer);
        //if(simxGetJointForce(clientID,simD->Act.at(i).handle,const_cast<float*>(&(simD->Act.at(i).force)),simx_opmode_buffer)  != 0) is_everything_ok=false;
        simxGetJointForce(clientID,simD->Act.at(i).handle,const_cast<float*>(&(simD->Act.at(i).force)),simx_opmode_buffer);
    }
    //Stream from Qs
    for (int i=0;i<6;i++)
    {
        //if(simxGetJointPosition(clientID,simD->Q.at(i).handle,const_cast<float*>(&(simD->Q.at(i).position)),simx_opmode_buffer) != 0) is_everything_ok=false;
        simxGetJointPosition(clientID,simD->Q.at(i).handle,const_cast<float*>(&(simD->Q.at(i).position)),simx_opmode_buffer);
        //if(simxGetJointForce(clientID,simD->Q.at(i).handle,const_cast<float*>(&(simD->Q.at(i).force)),simx_opmode_buffer) != 0) is_everything_ok=false;
        simxGetJointForce(clientID,simD->Q.at(i).handle,const_cast<float*>(&(simD->Q.at(i).force)),simx_opmode_buffer);
    }
    //Stream from Tip-Target
    //if(simxGetObjectPosition(clientID,simD->tip.handle,rel,simD->tip.position,simx_opmode_buffer) != 0) is_everything_ok=false;
    simxGetObjectPosition(clientID,simD->tip.handle,rel,simD->tip.position,simx_opmode_buffer);
    //if(simxGetObjectPosition(clientID,simD->target.handle,rel,simD->target.position,simx_opmode_buffer) != 0) is_everything_ok=false;
    simxGetObjectPosition(clientID,simD->target.handle,rel,simD->target.position,simx_opmode_buffer);
    locker.unlock();
    return is_everything_ok;
}

void vrapi::simQProcessMotion()
{
    int dt = simD->velocity.dt;
    for (int i=0;i<3;i++)
    {
        simD->target.position[i]=simD->target.position[i]+simD->velocity.linear[i]*dt;
        simD->target.orientation[i]=simD->target.orientation[i]+simD->velocity.angular[i]*dt;
    }
}

void vrapi::simQSetDummyPositionOrientation(vrepDummy *dum)
{
    simxSetObjectPosition(clientID,dum->handle,simD->relative_to_object,dum->position,simx_opmode_oneshot);
    simxSetObjectOrientation(clientID,dum->handle,simD->relative_to_object,dum->orientation,simx_opmode_oneshot);
}

void vrapi::simQGetAllHandles()
{
    //getting handles
    locker.lock();
    simxGetObjectHandle(clientID,(const simxChar*)"Q1#",const_cast<int*>(&(simD->Q.at(0).handle)),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"Q2#",const_cast<int*>(&(simD->Q.at(1).handle)),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"Q3#",const_cast<int*>(&(simD->Q.at(2).handle)),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"Q4#",const_cast<int*>(&(simD->Q.at(3).handle)),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"Q5#",const_cast<int*>(&(simD->Q.at(4).handle)),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"Q6#",const_cast<int*>(&(simD->Q.at(5).handle)),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"A1f#",const_cast<int*>(&(simD->Act.at(0).handle)),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"A2f#",const_cast<int*>(&(simD->Act.at(1).handle)),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"A3f#",const_cast<int*>(&(simD->Act.at(2).handle)),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"base_d#",const_cast<int*>(&(simD->frames.at(0))),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"link6_d#",const_cast<int*>(&(simD->frames.at(1))),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"IK_tip#",&(simD->tip.handle),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"IK_target#",&(simD->target.handle),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"BaxterGripper_closeJoint#",&(simD->gripper.motorHandle),simx_opmode_blocking);
    locker.unlock();
}

/*
void vrapi::simQinitializeTarget()
{
    float orien[3];
    float pos[3];
    int obj;
    int rel;
    obj = simD->handle.Target();
    rel = simD->handle.Base();
    //simxGetObjectPosition(clientID,obj,rel,pos,simx_opmode_oneshot);
    //simxGetObjectOrientation(clientID,obj,rel,orien,simx_opmode_oneshot);
    pos[0]= 0.8f;
    pos[1]= 0;
    pos[2]= 0.445f;
    orien[0]= 0;
    orien[1]= 0;
    orien[2]= 0;

    locker.lock();
    simD->target.handle = obj;
    simD->target.relative_to_object = rel;
    for (int i=0;i<3;i++)
    {
        simD->target.position[i] = pos[i];
        simD->target.orientation[i] = orien[i];
    }
    locker.unlock();
}
*/
