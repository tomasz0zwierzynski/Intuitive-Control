/*  Class:          MouseHandler "mousehandler.cpp"
 *  Description:    Details of class implementation. See "mousehandler.h"
 */

/* Includes */
#include "3Dmouse/mousehandler.h"
#include <QThread>
#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include "3Dmouse/snapi.h"
#include "3Dmouse/mousedata.h"


/*  Function:    Constructor function
 *  Description: Creating child thread and SNapi instance to handle executing external api.
 *               Connecting signals and slots from child thread to main thread (this instance).
 *               Starting child thread execution and initializing MouseData instance.
 */
MouseHandler::MouseHandler(QObject *parent) : QObject(parent)
{
    mouse_thread = new QThread;
    mouseAPI = new SNapi();

    //Moving instance of SNapi to child thread
    mouseAPI->moveToThread(mouse_thread);

    //Error signal from child thread catched by this class
    connect(mouseAPI, SIGNAL(error(QString)),this,SLOT(errorString(QString)));
    connect(mouseAPI, SIGNAL(info(QString)),this, SLOT(infoString(QString)));

    //When starting thread let process() function exectute
    connect(mouse_thread, SIGNAL(started()),mouseAPI,SLOT(process()));

    //When child thread finishes quit child thread and delete SNapi instance and thread instance
    connect(mouseAPI, SIGNAL(finished()), mouse_thread, SLOT(quit()));
    connect(mouseAPI, SIGNAL(finished()), mouseAPI, SLOT(deleteLater()));
    connect(mouse_thread, SIGNAL(finished()), mouse_thread, SLOT(deleteLater()));

    //When signal from SNapi instance (from child thread) is emitted, handle that raw data
    connect(mouseAPI, SIGNAL(data_arrived(QString)), this, SLOT(handle_mouse_data(QString)));

    //Start child thread (so process() also starts)
    mouse_thread->start();

    //First MouseData write
    mouse_position_data.setData("00&0&0&0&0&0");

}


/*  Function:    Destructor function
 *  Description: Cleaning up stuff.
 */
MouseHandler::~MouseHandler()
{
    delete mouseAPI;
    delete mouse_thread;
}


/*  Function:    Handle New Mouse Data
 *  Description: Slot executed when new data arrives. Putting data into
 *               MouseData data type and emitting signal (to GUI) that data updated.
 */
void MouseHandler::handle_mouse_data(QString st)
{
    mouse_position_data.setData(st);
    //qDebug() << "handle_mouse_data occured!";
    //qDebug() << st;
    emit info_occured("Mouse data changed: " + st);

    emit data_updated(&mouse_position_data);
}


/*  Function:    Error String
 *  Description: Currently not used.
 *
 *               TODO: pass error string to GUI
 */
void MouseHandler::errorString(QString st)
{
    emit error_occured(st);
}

void MouseHandler::infoString(QString info)
{
    emit info_occured(info);
}


/*  Function:    Stop Handling Process
 *  Description: When sudden event occures (like application is closing), external
 *               process must be killed.
 *
 */
int MouseHandler::stopHandling()
{
    mouseAPI->getExtProcess()->kill();
    emit info_occured("mapi.exe process killed.");
    //qDebug() << "Process killed()";

    return 1;
}
