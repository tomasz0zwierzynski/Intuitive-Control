#include "mwnd.h"
#include "ui_mwnd.h"

#include <QMessageBox>
#include <QCloseEvent>
#include <QFile>
#include <QCoreApplication>
#include <QMessageBox>
#include <QDebug>
#include <QVector>
#include <QPointer>

#include "gui/status.h"
#include "gui/hgui.h"
#include "gui/vstream.h"
#include "3Dmouse/mousehandler.h"
#include "vrep/simhandler.h"
#include "vrep/setup.h"

#include "setwnd.h"
#include "graphwnd.h"
#include "aboutwnd.h"

extern "C" {
    #include "vrep/remoteApi/extApi.h"
}

mWnd::mWnd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mWnd)
{
    ui->setupUi(this);
    ui->actionShow_logs->setDisabled(true);
    ui->actionStop_simulation->setDisabled(true);
    ui->actionSettings->setDisabled(true);
    ui->actionShow_graphs->setDisabled(true);

    graphW = new graphWnd;

    //Creating Status object response for collectig logs and handle status bar.
    status = new Status(ui->statusBar);

    ui->tabWidget->setStyleSheet("background-color: #F0F0F0");

    //Na razie po prostu tworze ten obiekt, potem sie zrobi ze to bedzie w dialogu inicjalizacji.
    handle_mouse = new MouseHandler;

    connect(handle_mouse,SIGNAL(error_occured(QString)),status,SLOT(errorOccured(QString)));
    connect(handle_mouse,SIGNAL(info_occured(QString)),status,SLOT(informationOccured(QString)));

    //Creating control UI handle object
    getAllUIhandles();
    inlabels = new RawDataGroup(guih,this);
    connect(handle_mouse,SIGNAL(data_updated(MouseData*)),inlabels,SLOT(new_mouse_data(MouseData*)));

    //auto-start simulation
    //startSimulation();
}

void mWnd::startSimulation()
{
    qDebug() << "startSimulation()";

    handle_vrep = new SimHandler;
    init = new Setup;

    //Creating data streams from v-rep object
    ui->treeWidget->setEnabled(false);
    stream = new vstream(ui->treeWidget);
    connect(handle_vrep,SIGNAL(stream_from_vrep(float*,int)),stream,SLOT(on_new_data(float*,int)));
    connect(handle_vrep,SIGNAL(stream_from_vrep(float*,int)),graphW,SLOT(on_graph_data(float*,int)));

    //to laczenie polaczy wyjscie z przetworzonych danych z myszy do obiektu ustawiajacego predkosci
    //connect(this,SIGNAL(new_slider_data(double*,int)),handle_vrep,SLOT(on_velocities_changed(double*,int)));
    connect(init,SIGNAL(setup_failed()),this,SLOT(stopSimulation()));
    connect(init,SIGNAL(setup_finished(QString,QString,int)),handle_vrep,SLOT(on_setup_finished(QString,QString,int)));

    connect(init,SIGNAL(setup_finished(QString,QString,int)),init,SLOT(deleteLater()));

    connect(inlabels,SIGNAL(new_output_data(double*,int)),handle_vrep,SLOT(on_velocities_changed(double*,int)));
    connect(inlabels,SIGNAL(motion_type_changed(bool)),handle_vrep,SLOT(on_motion_event_change(bool)));
    connect(inlabels,SIGNAL(gripper_open_close(bool)),handle_vrep,SLOT(on_gripper_action(bool)));

    ui->actionShow_graphs->setEnabled(true);

    connect(init,SIGNAL(setup_finished(QString,QString,int)),this,SLOT(on_setup_finished()));
    init->start_setuping();
}

void mWnd::on_setup_finished()
{
    ui->actionSettings->setEnabled(true);
}

void mWnd::stopSimulation()
{
    /*
    qDebug() << "stopSimulation()";

    handle_vrep->on_sim_stop();
    qDebug() << "on_sim_stop() calling...";

    disconnect(inlabels,SIGNAL(new_output_data(double*,int)),handle_vrep,SLOT(on_velocities_changed(double*,int)));
    disconnect(inlabels,SIGNAL(motion_type_changed(bool)),handle_vrep,SLOT(on_motion_event_change(bool)));
    disconnect(inlabels,SIGNAL(gripper_open_close(bool)),handle_vrep,SLOT(on_gripper_action(bool)));

    handle_vrep->deleteLater();
    init->deleteLater();
    //delete handle_vrep;
    //delete init;
    */
}

void mWnd::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Close application question",
                                                                   "Do you really want to close and end current session?\n",
                                                                   QMessageBox::No | QMessageBox::Yes,
                                                                   QMessageBox::No);
       if (resBtn != QMessageBox::Yes) {
           event->ignore();
       } else {

             //qDebug() << "Calling stopHandlig()";
             int done=handle_mouse->stopHandling();
             //qDebug() << done;
           event->accept();
       }
}

mWnd::~mWnd()
{
    delete ui;
}

void mWnd::on_actionStop_simulation_triggered()
{
    stopSimulation();
}

void mWnd::restartApplication()
{
    QProcess::startDetached(QApplication::applicationFilePath());
    exit(12);
}

void mWnd::getAllUIhandles()
{
    QVector<hCtrGroup>axe;
    hCtrGroup temp[6];
    temp[0].gB_axes = ui->gB_X;
    temp[1].gB_axes = ui->gB_Y;
    temp[2].gB_axes = ui->gB_Z;
    temp[3].gB_axes = ui->gB_A;
    temp[4].gB_axes = ui->gB_B;
    temp[5].gB_axes = ui->gB_C;

    temp[0].lab_value = ui->lab_X;
    temp[1].lab_value = ui->lab_Y;
    temp[2].lab_value = ui->lab_Z;
    temp[3].lab_value = ui->lab_A;
    temp[4].lab_value = ui->lab_B;
    temp[5].lab_value = ui->lab_C;

    temp[0].pB_2x = ui->pB_X_2x;
    temp[1].pB_2x = ui->pB_Y_2x;
    temp[2].pB_2x = ui->pB_Z_2x;
    temp[3].pB_2x = ui->pB_A_2x;
    temp[4].pB_2x = ui->pB_B_2x;
    temp[5].pB_2x = ui->pB_C_2x;

    temp[0].pB_5x = ui->pB_X_5x;
    temp[1].pB_5x = ui->pB_Y_5x;
    temp[2].pB_5x = ui->pB_Z_5x;
    temp[3].pB_5x = ui->pB_A_5x;
    temp[4].pB_5x = ui->pB_B_5x;
    temp[5].pB_5x = ui->pB_C_5x;

    temp[0].pB_11 = ui->pB_X_11;
    temp[1].pB_11 = ui->pB_Y_11;
    temp[2].pB_11 = ui->pB_Z_11;
    temp[3].pB_11 = ui->pB_A_11;
    temp[4].pB_11 = ui->pB_B_11;
    temp[5].pB_11 = ui->pB_C_11;

    temp[0].pB_lock = ui->pB_X_lock;
    temp[1].pB_lock = ui->pB_Y_lock;
    temp[2].pB_lock = ui->pB_Z_lock;
    temp[3].pB_lock = ui->pB_A_lock;
    temp[4].pB_lock = ui->pB_B_lock;
    temp[5].pB_lock = ui->pB_C_lock;

    temp[0].vS_value = ui->vS_X;
    temp[1].vS_value = ui->vS_Y;
    temp[2].vS_value = ui->vS_Z;
    temp[3].vS_value = ui->vS_A;
    temp[4].vS_value = ui->vS_B;
    temp[5].vS_value = ui->vS_C;

    for (int i=0;i<6;i++)
    {
        axe.append(temp[i]);
    }
    guih.axes = axe;

    guih.cB_enable = ui->cB_enable;
    guih.gB_adv = ui->gB_adv;
    guih.gB_control = ui->gB_control;
    guih.gB_in = ui->gB_in;
    guih.gB_relativity = ui->gB_relativity;
    guih.label_left = ui->label_raw_left;
    guih.label_right = ui->label_raw_right;

    QVector<QLabel*>tempLab;
    tempLab.append(ui->label_raw_x);
    tempLab.append(ui->label_raw_y);
    tempLab.append(ui->label_raw_z);
    tempLab.append(ui->label_raw_a);
    tempLab.append(ui->label_raw_b);
    tempLab.append(ui->label_raw_c);

    guih.label_raw = tempLab;

    guih.pB_all_2x = ui->pB_gen_2x;
    guih.pB_all_5x = ui->pB_gen_5x;
    guih.pB_all_11 = ui->pB_gen_11;
    guih.pB_all_lock_ABC = ui->pB_gen_lock_ABC;
    guih.pB_all_lock_XYZ = ui->pB_gen_lock_XYZ;
    guih.vS_all = ui->vS_gen;

    guih.rB_base = ui->rB_base;
    guih.rB_tip = ui->rB_tip;

    guih.label_all = ui->lab_gen;
}

void mWnd::on_actionRestart_Application_triggered()
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Restart application question",
                                                                   "Do you really want to restart application?\n",
                                                                   QMessageBox::No | QMessageBox::Yes,
                                                                   QMessageBox::No);
       if (resBtn == QMessageBox::Yes)
       {
        //qDebug() << "Calling stopHandlig()";
             int done=handle_mouse->stopHandling();
             //qDebug() << done;
     this->restartApplication();
       }
}

void mWnd::on_actionClose_Application_triggered()
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Close application question",
                                                                   "Do you really want to close and end current session?\n",
                                                                   QMessageBox::No | QMessageBox::Yes,
                                                                   QMessageBox::No);
       if (resBtn != QMessageBox::Yes) {
           //
       } else {

             //qDebug() << "Calling stopHandlig()";
             int done=handle_mouse->stopHandling();
             //qDebug() << done;
           exit(1);
       }
}

void mWnd::on_actionSettings_triggered()
{
    //QPointer<setWnd> dialog = new setWnd;
    //dialog->show();
    //if (dialog) dialog->show();
    QProcess::startDetached(QCoreApplication::applicationDirPath() + "//settings");

}

void mWnd::on_actionRun_simulation_triggered()
{
    startSimulation();
    ui->actionRun_simulation->setDisabled(true);
}

void mWnd::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_0)
    {
        if(ui->rB_base->isChecked())
            ui->rB_tip->toggle();
        else
            ui->rB_base->toggle();
    }
    if (event->key() == Qt::Key_1)
        ui->pB_A_lock->toggle();
    if (event->key() == Qt::Key_2)
        ui->pB_B_lock->toggle();
    if (event->key() == Qt::Key_3)
        ui->pB_C_lock->toggle();
    if (event->key() == Qt::Key_4)
        ui->pB_X_lock->toggle();
    if (event->key() == Qt::Key_5)
        ui->pB_Y_lock->toggle();
    if (event->key() == Qt::Key_6)
        ui->pB_Z_lock->toggle();

}

void mWnd::on_actionShow_graphs_triggered()
{
    graphW->show();
}

void mWnd::on_actionAbout_triggered()
{
    aboutW = new aboutWnd;
    aboutW->show();
}
