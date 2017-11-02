#ifndef SNAPI_H
#define SNAPI_H

/*  Class:          SNapi "snapi.h"
 *  Description:    Class provides functions that handles creating
 *                  and communicationg with external api program
 *                  "mapi.exe".
 *
 *                  Communication is realized by named pipes through
 *                  windows.h functions.
 *
 *                  Instances of this class should run in another thread
 *                  because of blocking functions included.
 */

/* Includes */
#include "Windows.h"                    //to handle named pipes
#include <QObject>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <string>

/* Class declaration */
class SNapi : public QObject
{
    Q_OBJECT
public:
    explicit SNapi(QObject *parent = 0);
    ~SNapi();

    QProcess * getExtProcess() const;   //process accessor

signals:
    void finished();                    //signal emitted when thread
                                        //finishes process() function

    void error(QString err);            //signal emitted when sth goes
                                        //wrong
    void info(QString info);

    void data_arrived(QString);         //signal emitted when new data
                                        //arrives from client

public slots:
    void process();                     //function containing
                                        //main thread loop

    void RequestThreadToStop();         //used to request stopping
                                        //thread
private:
    HANDLE hPipe;                       //standard windows handle to
                                        //named pipe

    bool interuption_is_requested;      //boolean variable to request
                                        //stopping thread

    QProcess *ext_api;                  //pointer to QProcess (object
                                        //responsible for executing
                                        //external api

    const QString prog_dir;             //constant storing path to
                                        //external api folder

    const QString prog_name;            //constant storing name of
                                        //executable in case of different
                                        //name

    QStringList prog_args;              //Not used feature, to further
                                        //development, strings with args
                                        //passed to external api

    QString data_out;                   //string storing red data from
                                        //external api

    const std::wstring g_szPipeName;    //constant storing pipe name
                                        //which is created

    bool CreateNamedPipeEx();           //function that creates named pipe

    bool ConnectNamedPipeEx();          //function that connects
                                        //to the client (external api)

    int ReadFileEx();                   //blocking function that awaits
                                        //for data from external api
};

#endif // SNAPI_H
