#ifndef MWND_H
#define MWND_H

#include <QMainWindow>
#include "gui/status.h"
#include "gui/rawdatagroup.h"
#include "gui/hgui.h"
#include "gui/vstream.h"
#include "3Dmouse/mousehandler.h"
#include "vrep/setup.h"
#include "vrep/simhandler.h"
#include "setwnd.h"
#include "graphwnd.h"
#include "aboutwnd.h"

namespace Ui {
class mWnd;
}

class mWnd : public QMainWindow
{
    Q_OBJECT

public:
    explicit mWnd(QWidget *parent = 0);
    ~mWnd();

    void closeEvent (QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void getAllUIhandles();
public slots:
    void startSimulation();
    void stopSimulation();

    void restartApplication();

signals:
    void switchFramePressed(bool);
    void lockAxePressed(int);

private slots:
    void on_actionStop_simulation_triggered();

    void on_actionRestart_Application_triggered();

    void on_actionClose_Application_triggered();

    void on_setup_finished();

    void on_actionSettings_triggered();

    void on_actionRun_simulation_triggered();

    void on_actionShow_graphs_triggered();

    void on_actionAbout_triggered();

private:
    Ui::mWnd *ui;
    hGUI guih;
    setWnd *setW;
    graphWnd *graphW;
    aboutWnd *aboutW;

    MouseHandler * handle_mouse;
    SimHandler * handle_vrep;

    Setup * init;
    Status * status;
    RawDataGroup * inlabels;
    vstream * stream;

};

#endif // MWND_H
