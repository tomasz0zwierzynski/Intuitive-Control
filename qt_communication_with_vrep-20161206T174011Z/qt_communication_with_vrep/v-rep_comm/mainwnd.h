#ifndef MAINWND_H
#define MAINWND_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>

#include "simhandler.h"
#include "setup.h"


namespace Ui {
class MainWnd;
}

class MainWnd : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWnd(QWidget *parent = 0);
    ~MainWnd();

private slots:
    void on_sliders_update();

    void on_pushButton_clicked();

signals:
    void new_slider_data(double*,int);
    void motion_event(bool);

private:
    Ui::MainWnd *ui;
    SimHandler *handle_vrep;

    Setup *init;

    QString dir_vrep;
    QString sim_file;


    double fromSliderFunction(int);

};

#endif // MAINWND_H
