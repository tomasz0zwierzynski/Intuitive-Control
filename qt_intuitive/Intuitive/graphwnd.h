#ifndef GRAPHWND_H
#define GRAPHWND_H

#include <QWidget>
#include <QVector>
#include <QCloseEvent>
//#include "gui/qcustomplot.h"
#include "qcustomplot.h"

namespace Ui {
class graphWnd;
}

class graphWnd : public QWidget
{
    Q_OBJECT

public:
    explicit graphWnd(QWidget *parent = 0);
    ~graphWnd();

public slots:
    void on_graph_data(float *,int);
    void closeEvent(QCloseEvent *event);

private slots:
    void on_comboBox_change(int);

    void on_pB_draw_clicked();

private:
    Ui::graphWnd *ui;
    double first_time;
    bool was_first_time;

    int currentComboBoxItemSelected;
    //int currentPlotDisplayed;

    bool enabled_data_stream[30];
    bool turned_on;

    QVector<double>dat[30];
    QVector<double>t;
    QVector<double>deviation;

};

#endif // GRAPHWND_H
