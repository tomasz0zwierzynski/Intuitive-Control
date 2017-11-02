#include "mwnd.h"
#include <QApplication>
#include <QFile>
#include <QCoreApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile mapi_exe(QCoreApplication::applicationDirPath() + "//mapi.exe");
    if (!mapi_exe.exists())
    {
       QMessageBox::critical(0, "Fatal Error!","Cannot find mapi.exe in application dir, application will terminate!",QMessageBox::Ok);
       return 0;
    }

    mWnd w;
    w.show();

    return a.exec();
}
