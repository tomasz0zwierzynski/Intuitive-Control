/*  Class:          SNapi "snapi.cpp"
 *  Description:    Details of class implementation. See "snapi.h"
 */

/* Includes & defines */
#include "3Dmouse/snapi.h"

#include "windows.h"                        //to handle named pipes
#include <QDebug>
#include <QThread>
#include <QProcess>
#include <QCoreApplication>
#include <QByteArray>

#define BUFFER_SIZE 64                      //definition of named pipe buffer size


/*  Function:    Constructor function
 *  Description: Initializes constant values, sets interuption request to false,
 *               creating QProcess instance (but not starting program yet) and
 *               creating named pipe to communicate with external api.
 */
SNapi::SNapi(QObject *parent) : QObject(parent),
            g_szPipeName(L"\\\\.\\Pipe\\ComChanel"),
            prog_dir(QCoreApplication::applicationDirPath()),
            prog_name("//mapi")
{
    interuption_is_requested = false;
    this->CreateNamedPipeEx();

    ext_api = new QProcess(this);
    prog_args.append("none");
}


/*  Function:    Destructor function
 *  Description: Closing named pipe and deleting QProcess instance.
 */
SNapi::~SNapi()
{
    CloseHandle(hPipe);
    delete ext_api;
}


/*  Function:    Main Thread Process Loop
 *  Description: This function is called once when thread is started. It
 *               executing external api program, connecting to it through
 *               named pipe and reading data in infinite loop.
 *
 *               If interuption is needed and thread should finish, it can
 *               break off inifinite loop by checking interuption_is_requested
 *               flag. Note that ReadFileEx() function is a blocking function
 *               so if data stop incoming from client (external api), thread
 *               never end normally.
 *
 *               TODO: Add timeout to ReadFileEx() function somehow to prevent
 *               blocking interuption request.
 */
void SNapi::process()
{
   // qDebug() << "Thread started...";
    emit info("Subthread (SNapi object) started...");
    //qDebug() << "Waiting for client to connect... ";
    emit info("Waiting for client to connect...");

    ext_api->start(prog_dir + prog_name, prog_args);    //Starting external api
    this->ConnectNamedPipeEx();                         //Connect to the client

    while(true)                                         //Infinite processing loop
    {
        if (interuption_is_requested)
        {
            //If something is needed to be done before ending thread
            //ext_api->kill();
            //break;

            //not implemented yet.
        }else{
                int read_result = ReadFileEx();         //Recieving data from client

                //When function do not returns 1 then error occured
                if(!(read_result == 1))
                {
                    //emit error signal and recieve error code
                    emit error("Error occured while reading from the client: " + QString::number(read_result));

                    //suspend thread for 300 ms
                    QThread::msleep(300);
                }

                //when ReadFileEx() succeeded emit signal that new data have to be handled
                emit data_arrived(this->data_out);
         }
      }

    //emit signal when thread finished job
    emit finished();
}


/*  Function:    Request Thread To Stop
 *  Description: Setting up interuption_is_requested flag.
 */
void SNapi::RequestThreadToStop()
{
    qDebug() << "Setting interupted_is_requested = true";
    this->interuption_is_requested = true;
}


/*  Function:    Accessor To External API
 *  Description: Returning pointer to external API process instance.
 */
QProcess * SNapi::getExtProcess() const
{
   return ext_api;
}


/*  Function:    Starting Named Pipe
 *  Description: Function used to create named pipe based on CreateNamePipe()
 *               function from "windows.h". Retrieving windows handle to this
 *               pipe.
 *               Function returns false when sth goes wrong. Error code written
 *               in debugger.
 *
 *               TODO: pass error code further.
 */
bool SNapi::CreateNamedPipeEx()
 {
     this->hPipe = CreateNamedPipe(
                   this->g_szPipeName.c_str(),  // pipe name
                   PIPE_ACCESS_DUPLEX,          // read/write access
                   PIPE_TYPE_MESSAGE |          // message type pipe
                   PIPE_READMODE_MESSAGE |      // message-read mode
                   PIPE_WAIT,                    // blocking mode
                   PIPE_UNLIMITED_INSTANCES,    // max. instances
                   BUFFER_SIZE,                 // output buffer size
                   BUFFER_SIZE,                 // input buffer size
                   NMPWAIT_USE_DEFAULT_WAIT,    // client time-out
                   NULL);                       // default security attribute

     if (INVALID_HANDLE_VALUE == hPipe)
     {
         //qDebug() << "Error while creating the communication pipe: " << GetLastError();
         emit error("Error while creating the communication pipe: " + QString::number(GetLastError()));
          return false;  //Error
     }
     else
     {
          //qDebug() << "CreateNamedPipe() was successful.";
          emit info("CreateNamedPipe() was successful.");
          return true;
     }
 }


/*  Function:    Connect To The Client
 *  Description: Function used to connect to the client through named pipe.
 *               Function returns false when sth goes wrong. Error code written
 *               in debugger.
 *
 *               TODO: pass error code further.
 */
 bool SNapi::ConnectNamedPipeEx()
 {
     BOOL bClientConnected = ConnectNamedPipe(this->hPipe, NULL);
     if (FALSE == bClientConnected)
      {
         //qDebug() << "Error occurred while connecting to the client: " << GetLastError();
         emit error("Error occurred while connecting to the client: " + QString::number(GetLastError()));
         return false;
      }
      else
      {
         //qDebug() << "ConnectNamedPipe() was successful.";
          emit info("ConnectNamedPipe() was successful.");
         return true;
      }
 }


 /*  Function:    Read Data From Client
  *  Description: Function awaits for new data transmited through named pipe
  *               and saves that data to data_out string.
  *
  *               Function returns 1 when everything goes right and ErrorCode
  *               when error occurs.
  */
 int SNapi::ReadFileEx()
 {
     char szBuffer[BUFFER_SIZE];
     DWORD cbBytes;

     BOOL bResult = ReadFile(
                 this->hPipe,           // handle to pipe
                 szBuffer,              // buffer to receive data
                 sizeof(szBuffer),      // size of buffer
                 &cbBytes,              // number of bytes read
                 (DWORD) NULL);         // not overlapped I/O

     if ( (!bResult) || (0 == cbBytes))
     {
         //qDebug() << "Error occurred while reading from the client: " << GetLastError();
         emit error("Error occurred while reading from the client: " + QString::number(GetLastError()));
         return GetLastError();
     }
     else
     {
         //qDebug() << "ReadFile() was successful.";
     }

     QString data_in_str(szBuffer);
     data_out = data_in_str;

     return 1;
 }
