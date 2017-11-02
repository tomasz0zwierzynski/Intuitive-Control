#include "mainwnd.h"
#include "ui_mainwnd.h"

#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QProcess>
#include <QStringList>
#include <QDir>

#include "simhandler.h"
#include "setup.h"

extern "C" {
    #include "remoteApi/extApi.h"
}

//#include "extApi.h"

MainWnd::MainWnd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWnd)
{
    ui->setupUi(this);

    handle_vrep = new SimHandler;
    init = new Setup;

    //*********************
    //connect simhandler z oknem głownym
    connect(this,SIGNAL(new_slider_data(double*,int)),handle_vrep,SLOT(on_velocities_changed(double*,int)));

    connect(init,SIGNAL(setup_failed()),this,SLOT(close()));
    connect(init,SIGNAL(setup_finished(QString,QString,int)),handle_vrep,SLOT(on_setup_finished(QString,QString,int)));
    connect(init,SIGNAL(setup_finished(QString,QString)),init,SLOT(deleteLater()));

    connect(ui->vA,SIGNAL(valueChanged(int)),this,SLOT(on_sliders_update()));
    connect(ui->vB,SIGNAL(valueChanged(int)),this,SLOT(on_sliders_update()));
    connect(ui->vC,SIGNAL(valueChanged(int)),this,SLOT(on_sliders_update()));
    connect(ui->vX,SIGNAL(valueChanged(int)),this,SLOT(on_sliders_update()));
    connect(ui->vY,SIGNAL(valueChanged(int)),this,SLOT(on_sliders_update()));
    connect(ui->vZ,SIGNAL(valueChanged(int)),this,SLOT(on_sliders_update()));

    connect(this,SIGNAL(motion_event(bool)),handle_vrep,SLOT(on_motion_event_change(bool)));

    init->start_setuping();
}

MainWnd::~MainWnd()
{
    delete ui;
}

void MainWnd::on_sliders_update()
{
    //*************************
    double from_sliders[6];

    from_sliders[0] = fromSliderFunction(ui->vX->value());
    from_sliders[1] = fromSliderFunction(ui->vY->value());
    from_sliders[2] = fromSliderFunction(ui->vZ->value());
    from_sliders[3] = fromSliderFunction(ui->vA->value());
    from_sliders[4] = fromSliderFunction(ui->vB->value());
    from_sliders[5] = fromSliderFunction(ui->vC->value());

    if (from_sliders[0]+from_sliders[1]+from_sliders[2]+from_sliders[3]+from_sliders[4]+from_sliders[5]==0)
        emit motion_event(false);
    else
        emit motion_event(true);

    if (ui->radio_base->isChecked())
        emit new_slider_data(from_sliders,0);
    if (ui->radio_grip->isChecked())
        emit new_slider_data(from_sliders,1);

}

double MainWnd::fromSliderFunction(int val)
{
    return (0.12*val-6.0);
}

void MainWnd::on_pushButton_clicked()
{
    ui->vX->setValue(50);
    ui->vY->setValue(50);
    ui->vZ->setValue(50);
    ui->vA->setValue(50);
    ui->vB->setValue(50);
    ui->vC->setValue(50);
}
