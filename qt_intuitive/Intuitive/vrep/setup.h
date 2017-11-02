#ifndef SETUP_H
#define SETUP_H

#include <QObject>

class Setup : public QObject
{
    Q_OBJECT
public:
    explicit Setup(QObject *parent = 0);

signals:
    void setup_finished(QString,QString,int);
    void setup_failed();

public slots:
    void start_setuping();

private:
    QString vrep_dir;
    QString scene_file;
    QString app_path;
    int seconds;

    //void raw_settings_import();
    //TODO: custom v-rep objects names
};

#endif // SETUP_H
