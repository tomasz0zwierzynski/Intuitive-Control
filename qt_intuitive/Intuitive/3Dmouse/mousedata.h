#ifndef MOUSEDATA_H
#define MOUSEDATA_H

/*  Class:          MouseData "mousedata.h"
 *  Description:    Data Type containing functions to transform raw data from 3D mouse
 *                  into seperate fields.
 *
 */

#include <QString>

class MouseData
{
public:

    MouseData();
    MouseData(QString);

                                            //Some accessors
    int getTX() const;                      //translation on X
    int getTY() const;                      //translation on Y
    int getTZ() const;                      //translation on Z
    int getRX() const;                      //rotation by X
    int getRY() const;                      //rotation by Y
    int getRZ() const;                      //rotation by Z
    int getDT() const;                      //event type occured
    int getLBS() const;                     //left button state
    int getRBS() const;                     //right button state

    void setData(QString);                  //set fields from raw data
    void setData(int[6]);                   //set axis values from vector

private:

    void convertString(QString);            //function transforming raw data into values

    //1 - motion event occured; 0 - zero event; 2 - L button pressed; 3 - L button released; 4 - R button pressed; 5 - R button released
    int data_type;

    int values[6];                          //Tx,Ty,Tz,Rx,Ry,Rz
    int left_button_state;                  // = 0 means released; = 1 means pressed
    int right_button_state;                 //= 0 means released; = 1 means pressed
};

#endif // MOUSEDATA_H
