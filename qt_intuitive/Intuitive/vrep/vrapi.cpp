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

vrapi::vrapi(bool * oc, int * mt,bool* me,simData * vrep_d, QObject *parent = 0, int ofs = 5) : QObject(parent),
    offsleep(ofs)
{
    simD = vrep_d;
    motion_event = me;
    motion_type = mt;
    open_close_gripper = oc;
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

    int counterek=0;

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
/*
                  qDebug() << *motion_event;
                  qDebug() << *motion_type;
                  qDebug() << "TARGET rel TO BASE: [ " << simD->targetB.position[0] << " , " << simD->targetB.position[1] << " , " << simD->targetB.position[2] << " ]";
                  qDebug() << "TARGET rel TO LINK6: [ " << simD->targetL.position[0] << " , " << simD->targetL.position[1] << " , " << simD->targetL.position[2] << " ]";
*/
                if (*motion_event == true)
                {
                   if (*motion_type == 0)
                   {
                       //Motion is relative to base frame
                       this->simQProcessMotion(0);
                       this->simQSetDummyPositionOrientation(0);

                   }else if (*motion_type == 1)
                   {
                       //Motion is relative to tip frame
                       this->simQProcessMotion(1);
                       this->simQSetDummyPositionOrientation(1);
                   }
                }
                    if (*open_close_gripper)
                        simxSetJointTargetVelocity(clientID,simD->gripper.motorHandle,0.03,simx_opmode_oneshot);
                    else
                        simxSetJointTargetVelocity(clientID,simD->gripper.motorHandle,-0.03,simx_opmode_oneshot);

                if(!(counterek%4))
                {
                    float data[30];
                    prepareStreamArray(data);
                    int simulationTime = simxGetLastCmdTime(clientID);;
                    emit vrep_stream(data,simulationTime);
                }
                counterek++;

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
    simxGetObjectPosition(clientID,simD->tipB.handle,simD->base_frame,simD->tipB.position,simx_opmode_streaming);
    simxGetObjectPosition(clientID,simD->targetB.handle,simD->base_frame,simD->targetB.position,simx_opmode_streaming);
    simxGetObjectOrientation(clientID,simD->tipB.handle,simD->base_frame,simD->tipB.orientation,simx_opmode_streaming);
    simxGetObjectOrientation(clientID,simD->targetB.handle,simD->base_frame,simD->targetB.orientation,simx_opmode_streaming);

    simxGetObjectPosition(clientID,simD->tipL.handle,simD->link6_frame,simD->tipL.position,simx_opmode_streaming);
    simxGetObjectPosition(clientID,simD->targetL.handle,simD->link6_frame,simD->targetL.position,simx_opmode_streaming);
    simxGetObjectOrientation(clientID,simD->tipL.handle,simD->link6_frame,simD->tipL.orientation,simx_opmode_streaming);
    simxGetObjectOrientation(clientID,simD->targetL.handle,simD->link6_frame,simD->targetL.orientation,simx_opmode_streaming);

    locker.unlock();
}

bool vrapi::simQReadFromStream()
{
    bool is_everything_ok = true;
    locker.lock();
    for (int i=0;i<3;i++)
    {
        simxGetJointPosition(clientID,simD->Act.at(i).handle,const_cast<float*>(&(simD->Act.at(i).position)),simx_opmode_buffer);
        simxGetJointForce(clientID,simD->Act.at(i).handle,const_cast<float*>(&(simD->Act.at(i).force)),simx_opmode_buffer);
    }
    //Stream from Qs
    for (int i=0;i<6;i++)
    {
        simxGetJointPosition(clientID,simD->Q.at(i).handle,const_cast<float*>(&(simD->Q.at(i).position)),simx_opmode_buffer);
        simxGetJointForce(clientID,simD->Q.at(i).handle,const_cast<float*>(&(simD->Q.at(i).force)),simx_opmode_buffer);
    }
    //Stream from Tip-Target

    simxGetObjectPosition(clientID,simD->tipB.handle,simD->base_frame,simD->tipB.position,simx_opmode_buffer);
    simxGetObjectPosition(clientID,simD->targetB.handle,simD->base_frame,simD->targetB.position,simx_opmode_buffer);
    simxGetObjectOrientation(clientID,simD->tipB.handle,simD->base_frame,simD->tipB.orientation,simx_opmode_buffer);
    simxGetObjectOrientation(clientID,simD->targetB.handle,simD->base_frame,simD->targetB.orientation,simx_opmode_buffer);

    simxGetObjectPosition(clientID,simD->tipL.handle,simD->link6_frame,simD->tipL.position,simx_opmode_buffer);
    simxGetObjectPosition(clientID,simD->targetL.handle,simD->link6_frame,simD->targetL.position,simx_opmode_buffer);
    simxGetObjectOrientation(clientID,simD->tipL.handle,simD->link6_frame,simD->tipL.orientation,simx_opmode_buffer);
    simxGetObjectOrientation(clientID,simD->targetL.handle,simD->link6_frame,simD->targetL.orientation,simx_opmode_buffer);

    locker.unlock();
    return is_everything_ok;
}

void vrapi::simQProcessMotion(int mot_type)
{

    int dt = simD->velocity.dt;
    if (mot_type == 0)
    {
        for (int i=0;i<3;i++)
        {
            simD->targetB.position[i]=simD->targetB.position[i]+simD->velocity.linear[i]*dt;
            simD->targetB.orientation[i]=simD->targetB.orientation[i]+simD->velocity.angular[i]*dt;
        }

    }else if (mot_type == 1){
        for (int i=0;i<3;i++)
        {
            simD->targetL.position[i]=simD->velocity.linear[i];
            simD->targetL.orientation[i]=simD->velocity.angular[i]*10;
        }
    }
    //qDebug() << "TARGET rel TO BASE: [ " << simD->targetB.position[0] << " , " << simD->targetB.position[1] << " , " << simD->targetB.position[2] << " ]";
    //qDebug() << "VEL: [ " << simD->velocity.linear[0] << " , " << simD->velocity.linear[1] << " , " << simD->velocity.linear[2] << " ]";
}

void vrapi::simQSetDummyPositionOrientation(int mot_type)
{
    simxPauseCommunication(clientID,1);
    if (mot_type == 0)
    {
        simxSetObjectPosition(clientID,simD->targetB.handle,simD->base_frame,simD->targetB.position,simx_opmode_oneshot);
        simxSetObjectOrientation(clientID,simD->targetB.handle,simD->base_frame,simD->targetB.orientation,simx_opmode_oneshot);

    }else if (mot_type == 1)
    {
        simxSetObjectPosition(clientID,simD->targetL.handle,simD->link6_frame,simD->targetL.position,simx_opmode_oneshot);
        simxSetObjectOrientation(clientID,simD->targetL.handle,simD->link6_frame,simD->targetL.orientation,simx_opmode_oneshot);

    }
    simxPauseCommunication(clientID,0);
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
    simxGetObjectHandle(clientID,(const simxChar*)"base_d#",const_cast<int*>(&(simD->base_frame)),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"IK_target#",const_cast<int*>(&(simD->link6_frame)),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"IK_tip#",&(simD->tipB.handle),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"IK_target#",&(simD->targetB.handle),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"IK_tip#",&(simD->tipL.handle),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"IK_target#",&(simD->targetL.handle),simx_opmode_blocking);
    simxGetObjectHandle(clientID,(const simxChar*)"BaxterGripper_closeJoint#",&(simD->gripper.motorHandle),simx_opmode_blocking);
    locker.unlock();
}

void vrapi::prepareStreamArray(float * array)
{
    for (int i=0;i<6;i++)
        array[i] = simD->Q.at(i).position;
    for (int i=0;i<6;i++)
        array[i+6] = simD->Q.at(i).force;
    for (int i=0;i<3;i++)
        array[i+6+6] = simD->Act.at(i).position;
    for (int i=0;i<3;i++)
        array[i+6+6+3] = simD->Act.at(i).force;
    for (int i=0;i<3;i++)
        array[i+6+6+3+3] = simD->tipB.position[i];
    for (int i=0;i<3;i++)
        array[i+6+6+3+3+3] = simD->tipB.orientation[i];
    for (int i=0;i<3;i++)
        array[i+6+6+3+3+3+3] = simD->targetB.position[i];
    for (int i=0;i<3;i++)
        array[i+6+6+3+3+3+3+3] = simD->targetB.orientation[i];
}
