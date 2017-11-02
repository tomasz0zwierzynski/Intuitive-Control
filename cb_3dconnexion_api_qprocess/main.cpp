/*
 *    Small structural program called from main app to handle 3dconnexion signals.
 */

/* Includes and defines */
#define _WIN32_WINNT 0x0502     /* Must be set to make 3Dconnexion SDK work properly */

#include "windows.h"            /* Used to produce windows application and stuff*/

#include <tchar.h>              /* Used to handle some strings*/
#include <string>
#include <fstream>              /* Used to write log file*/
#include <ctime>                /* Used to get current time*/

#include "spwmacro.h"           /* Common macros used by SpaceWare functions. */
#include "si.h"                 /* Required for any SpaceWare support within an app */
#include "siapp.h"              /* Required for siapp.lib symbols */

#pragma warning(disable:4700)   /* Preprocessor directive used in VisualStudio */

#define g_szPipeName _T("\\\\.\\Pipe\\ComChanel")
                                /* Defining name of the pipe used in communication */
#define BUFFER_SIZE 64          /* Pipe buffer size, 64 bytes is enough*/

using std::string;


/* Global variables used in program */
DWORD cbBytes;                  /* Number of bytes written when sending informations */
HANDLE hPipe;                   /* Handle to connection pipe */
BOOL bResult;                   /* Result of sending information to the server */

std::ofstream ofs;              /* Declaration of file stream */

char szBuffer[BUFFER_SIZE];     /*Data buffer to send data */

SiHdl devHdl;                   /* Handle to 3D Mouse Device */
SiOpenData oData;
WNDPROC wndProcOrig;

/* Declarations of used functions */
int   SbInit(HWND hwndC);
void  SbMotionEvent(SiSpwEvent *pEvent);
void  SbZeroEvent();
void  SbButtonPressEvent(int buttonnumber);
void  SbButtonReleaseEvent(int buttonnumber);
void  HandleDeviceChangeEvent(SiSpwEvent *pEvent);
void  clearBuffer(char *buffer, int buf_size);

/* Standard windows callback function */
LRESULT CALLBACK MyWndCBProc(
  HWND hwnd, UINT wm, WPARAM wParam, LPARAM lParam)
{
  SiSpwEvent     Event;    /* SpaceWare Event */
  SiGetEventData EData;    /* SpaceWare Event Data */

  /* initialize Window platform specific data for a call to SiGetEvent */
  SiGetEventWinInit(&EData, wm, wParam, lParam);

  /* check whether wm was a 3D mouse event and process it */
  SpwRetVal retval = SiGetEvent (devHdl, 0, &EData, &Event);

  if (retval == SI_IS_EVENT)
  {
    if (Event.type == SI_MOTION_EVENT)
    {
      SbMotionEvent(&Event);        /* process 3D mouse motion event */
    }
    else if (Event.type == SI_ZERO_EVENT)
    {
      SbZeroEvent();                /* process 3D mouse zero event */
    }
    else if (Event.type == SI_BUTTON_PRESS_EVENT)
    {
      SbButtonPressEvent(Event.u.hwButtonEvent.buttonNumber);  /* process button press event */
    }
    else if (Event.type == SI_BUTTON_RELEASE_EVENT)
    {
      SbButtonReleaseEvent(Event.u.hwButtonEvent.buttonNumber); /* process button release event */
    }
    else if (Event.type == SI_DEVICE_CHANGE_EVENT)
    {
      //SbHandleDeviceChangeEvent(&Event); /* process 3D mouse device change event */
      //currently unused
    }
  }

  return DefWindowProc(hwnd, wm, wParam, lParam);
}

int main (int argc, char * argv[]) {

  /* Retrieve console application main window using GetConsoleWindow() */
  HWND windowHandle = GetConsoleWindow() ; /*This function  cleverly "retrieves the window handle  used by the console associated with the calling process",   as msdn says */

  /* Retrieve current time and opening file to write log*/
  time_t now = time(0);
  std::string now_s(ctime(&now));

  /* Opening log file in append mode */
  ofs.open("3dconnexionAPI_log.txt",std::ofstream::out | std::ofstream::app );

  /* Writing header to log */
  ofs << "\n\n-------------------\n" << now_s << "\n";
  ofs << "Starting api...\n";

  /* Register a custom window class */
  WNDCLASSEX wcex;
  wcex.cbSize = sizeof(WNDCLASSEX);
  wcex.style      = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc  = MyWndCBProc;
  wcex.cbClsExtra    = 0;
  wcex.cbWndExtra    = 0;
  wcex.hInstance    = GetModuleHandle(NULL);
  wcex.hIcon      = NULL;
  wcex.hCursor    = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground  = (HBRUSH)(COLOR_BTNFACE+1);
  wcex.lpszMenuName  = NULL;
  wcex.lpszClassName  = "MyWindowClassName";
  wcex.hIconSm    =  NULL;
  RegisterClassEx(&wcex);

  /* Create a hidden window owned by our process and parented to the console window */
  HWND hWndChild = CreateWindow(wcex.lpszClassName, "3Dconnexion API", WS_OVERLAPPEDWINDOW | WS_MINIMIZE, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, wcex.hInstance, NULL);

  /* Initialise 3DxWare access / call to SbInit() */
  SbInit(hWndChild);

  /* Connecting to the server pipe*/
  hPipe = CreateFile(
          g_szPipeName,   // pipe name
          GENERIC_READ |  // read and write access
          GENERIC_WRITE,
          0,              // no sharing
          NULL,           // default security attributes
          OPEN_EXISTING,  // opens existing pipe
          0,              // default attributes
          NULL);          // no template file

  if (INVALID_HANDLE_VALUE == hPipe)
     {
         ofs << "Error occurred while connecting to the server: " << GetLastError() << "\n";
          //One might want to check whether the server pipe is busy
          //This sample will error out if the server pipe is busy
          //Read on ERROR_PIPE_BUSY and WaitNamedPipe() for that
          return 1;  //Error
     }
     else
     {
          ofs << "CreateFile() was successful.\n";
     }

  /* Implement message loop */
  int bRet;
  MSG msg;      /* incoming message to be evaluated */
  while(bRet = GetMessage(&msg, NULL, 0, 0 ))
  {
    if (bRet == -1){
      /* handle the error and possibly exit */
      return 0;
    }else{
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }
}

int SbInit(HWND hwndC)
{
  int res;                             /* result of SiOpen, to be returned  */

  /*init the SpaceWare input library */
  if (SiInitialize() == SPW_DLL_LOAD_ERROR)  {
    ofs << "Error: Could not load SiAppDll dll files\n";
  } else {
    ofs << "SiInitialize() done.\n";
  }

  SiOpenWinInit (&oData, hwndC);    /* init Win. platform specific data  */

  /* open data, which will check for device type and return the device handle to be used by this function */
  if ( (devHdl = SiOpen("3D connexion API settings", SI_ANY_DEVICE, SI_NO_MASK, SI_EVENT, &oData)) == NULL) {
    ofs << "SiOpen error: \n";
    SiTerminate();  /* called to shut down the SpaceWare input library */
    ofs << "SiTerminate() \n";
    res = 0;        /* could not open device */
    return res;
  }

  SiDeviceName pname;
  SiGetDeviceName (devHdl, &pname);

  SiSetUiMode(devHdl, SI_UI_ALL_CONTROLS); /* Config SoftButton Win Display */
  SiGrabDevice(devHdl, SPW_TRUE); /* PREVENTS OTHER APPLICATIONS FROM RECEIVING 3D CONNEXION DATA !!! */
  res = 1;        /* opened device succesfully */
  return res;
}

void clearBuffer(char *buffer, int buf_size)
{
    for (int i=0;i<buf_size;i++)
            buffer[i] = 0;
}

void  SbMotionEvent(SiSpwEvent *pEvent) {
  clearBuffer(szBuffer,(int) BUFFER_SIZE);
  char si_xx_c[6][128];
  /* Writing 3d mouse data into one whole string*/
  string si_tx(ltoa(pEvent->u.spwData.mData[SI_TX],si_xx_c[0],10));
  string si_ty(ltoa(pEvent->u.spwData.mData[SI_TY],si_xx_c[1],10));
  string si_tz(ltoa(pEvent->u.spwData.mData[SI_TZ],si_xx_c[2],10));
  string si_rx(ltoa(pEvent->u.spwData.mData[SI_RX],si_xx_c[3],10));
  string si_ry(ltoa(pEvent->u.spwData.mData[SI_RY],si_xx_c[4],10));
  string si_rz(ltoa(pEvent->u.spwData.mData[SI_RZ],si_xx_c[5],10));
  string whole = "1" + si_tx + "&" + si_ty + "&" + si_tz + "&" + si_rx + "&" + si_ry + "&" + si_rz;
  /* 1 on the front means motion event */
  strcpy(szBuffer,whole.c_str());

  /* Writing to the server */
  bResult = WriteFile(
        hPipe,                // handle to pipe
        szBuffer,             // buffer to write from
        strlen(szBuffer)+1,   // number of bytes to write, include the NULL
        &cbBytes,             // number of bytes written
        NULL);                // not overlapped I/O

     if ( (!bResult) || (strlen(szBuffer)+1 != cbBytes))
     {
          ofs << "Error occurred while writing to the server: " << GetLastError() <<"\n";
          CloseHandle(hPipe);
     }
     else
     {
          ofs << "WriteFile() was successful. \n" ;
     }
}
void  SbZeroEvent() {
  clearBuffer(szBuffer,(int) BUFFER_SIZE);
  /* 0 on the front means zero event */
  szBuffer[0] = '0';
  bResult = WriteFile(hPipe, szBuffer, strlen(szBuffer)+1, &cbBytes, NULL);

     if ( (!bResult) || (strlen(szBuffer)+1 != cbBytes))
     {
          ofs << "Error occurred while writing to the server: " << GetLastError() << "\n";
          CloseHandle(hPipe);
     }
     else
     {
          ofs << "WriteFile() was successful.\n" ;
     }

}
void  SbButtonPressEvent(int buttonnumber) {
  clearBuffer(szBuffer,(int) BUFFER_SIZE);
  if (buttonnumber == 8){
    szBuffer[0] = '2';
  } else if (buttonnumber == 7 ){
    szBuffer[0] = '4';
  }else{
    ofs << "Change button settings in 3Dconnexion properties:\nLeft button should be 'backView'\nRight button should be 'BottomView'\n";
    return;
  }

    bResult = WriteFile(hPipe, szBuffer, strlen(szBuffer)+1, &cbBytes, NULL);

     if ( (!bResult) || (strlen(szBuffer)+1 != cbBytes))
     {
          ofs << "Error occurred while writing to the server: " << GetLastError() << "\n";
          CloseHandle(hPipe);
     }
     else
     {
          ofs << "WriteFile() was successful.\n" ;
     }
}
void  SbButtonReleaseEvent(int buttonnumber) {

  clearBuffer(szBuffer,(int) BUFFER_SIZE);
  if (buttonnumber == 8){
    szBuffer[0] = '3';
  } else if (buttonnumber == 7 ){
    szBuffer[0] = '5';
  }else{
    ofs << "Change button settings in 3Dconnexion properties:\nLeft button should be 'backView'\nRight button should be 'BottomView'\n";
    return;
  }
    bResult = WriteFile(hPipe, szBuffer, strlen(szBuffer)+1, &cbBytes, NULL);

     if ( (!bResult) || (strlen(szBuffer)+1 != cbBytes))
     {
          ofs << "Error occurred while writing to the server: " << GetLastError() << "\n";
          CloseHandle(hPipe);
     }
     else
     {
          ofs << "WriteFile() was successful.\n" ;
     }
}
void  HandleDeviceChangeEvent(SiSpwEvent *pEvent) {
  ofs << "HandleDeviceChangeEvent : \n";
  //Currently unused
}
