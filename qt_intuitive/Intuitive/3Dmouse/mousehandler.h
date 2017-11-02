#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

/*  Class:          MouseHandler "mousehandler.h"
 *  Description:    Class provides tools to create child thread and passing
 *                  data from created thread to main thread through signals.
 */

/* Includes */
#include <QObject>
#include <QString>
#include <QStringList>
#include <QProcess>
#include <QTimer>
#include "3Dmouse/mousedata.h"
#include "3Dmouse/snapi.h"

class MouseHandler : public QObject
{
    Q_OBJECT
public:
    explicit MouseHandler(QObject *parent = 0);
    ~MouseHandler();

     int stopHandling();                        //function that breaks up connection
                                                //with 3D mouse through external api.

signals:
    void data_updated(MouseData*);              //signal emmited when new data occurs
                                                //and passing it in MouseData data type

    void error_occured(QString);
    void info_occured(QString);

public slots:
    void handle_mouse_data(QString);            //function that decoding data from
                                                //external api through SNapi class
                                                //and writing in into MouseData data
                                                //type

    void errorString(QString);                  //slot that handling error text when
                                                //occured

    void infoString(QString);

private:
    MouseData mouse_position_data;              //MouseData data type instance see "mousedata.h"

    SNapi* mouseAPI;                            //pointer to SNapi instance

    QThread* mouse_thread;                      //pointer to child thread

};

#endif // MOUSEHANDLER_H
