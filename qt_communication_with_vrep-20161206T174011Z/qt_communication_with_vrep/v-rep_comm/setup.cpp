#include "setup.h"
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QProcess>
#include <QCoreApplication>
#include <QDebug>

Setup::Setup(QObject *parent) : QObject(parent)
{
        qDebug() << "Setup created!";
}

void Setup::start_setuping()
{
     qDebug() << "Starting setup!";
    //Acquaring directories from file

    app_path = QCoreApplication::applicationDirPath();
    QFile setting_file_open(app_path + "//settings.set");
    if (setting_file_open.open(QIODevice::ReadOnly))
    {
        QString raw_settings = QString::fromStdString(setting_file_open.readAll().toStdString());
        int temp = raw_settings.indexOf("&");
        vrep_dir = raw_settings.mid(0,temp);
        raw_settings.remove(0,temp+1);
        temp = raw_settings.indexOf("&");
        scene_file = raw_settings.mid(0,temp);
        raw_settings.remove(0,temp+1);
        temp = raw_settings.indexOf("&");
        seconds = raw_settings.mid(0,temp).toInt();
        //qDebug() << seconds;
        emit setup_finished(vrep_dir,scene_file,seconds);
    }else{
        QMessageBox info;
        info.setText("Cannot find settings file. Configuration program will run...");
        info.setWindowTitle("Information");
        info.exec();
        QProcess setting_app;
        setting_app.start(app_path + "//settings");
        if (!setting_app.waitForFinished(-1))
        {
            info.setText("Cannot run settings.exe. Program will terminate!");
            info.setWindowTitle("Gigantic error");
            info.exec();
            emit setup_failed();
        }
        setting_file_open.open(QIODevice::ReadOnly);
        QString raw_settings = QString::fromStdString(setting_file_open.readAll().toStdString());
        int temp = raw_settings.indexOf("&");
        vrep_dir = raw_settings.mid(0,temp);
        raw_settings.remove(0,temp+1);
        temp = raw_settings.indexOf("&");
        scene_file = raw_settings.mid(0,temp);
        raw_settings.remove(0,temp+1);
        temp = raw_settings.indexOf("&");
        seconds = raw_settings.mid(0,temp).toInt();
        qDebug() << "emitting setup_finished...";
        emit setup_finished(vrep_dir,scene_file,seconds);
    }
}

/*
Setup::raw_settings_import()
{

}
*/
