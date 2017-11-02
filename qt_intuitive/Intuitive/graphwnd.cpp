#include "graphwnd.h"
#include "ui_graphwnd.h"

//#include "gui/qcustomplot.h"

#include "qcustomplot.h"
#include <QDebug>
#include <QVector>
#include <cmath>

graphWnd::graphWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graphWnd)
{
    ui->setupUi(this);
    was_first_time = false;
    currentComboBoxItemSelected = 0;
    turned_on = false;

    ui->horizontalScrollBar->setValue(100);
    ui->plot1->addGraph();
    ui->comboBox->addItem("Select graph...");
    ui->comboBox->addItem("All joints positions - f(t)");
    ui->comboBox->addItem("All joints forces - f(t)");
    ui->comboBox->addItem("All actuators positions - f(t)");
    ui->comboBox->addItem("All actuators forces - f(t)");
    ui->comboBox->addItem("Tip-Target position deviation - f(t)");
    ui->comboBox->addItem("Tip-Target position - XY plane");
    ui->comboBox->addItem("Tip-Target position - XZ plane");
    ui->comboBox->addItem("Tip-Target position - YZ plane");
    ui->comboBox->addItem("Q1 position");
    ui->comboBox->addItem("Q2 position");
    ui->comboBox->addItem("Q3 position");
    ui->comboBox->addItem("Q4 position");
    ui->comboBox->addItem("Q5 position");
    ui->comboBox->addItem("Q6 position");
    ui->comboBox->addItem("Q1 force");
    ui->comboBox->addItem("Q2 force");
    ui->comboBox->addItem("Q3 force");
    ui->comboBox->addItem("Q4 force");
    ui->comboBox->addItem("Q5 force");
    ui->comboBox->addItem("Q6 force");
    ui->comboBox->addItem("A1 position");
    ui->comboBox->addItem("A2 position");
    ui->comboBox->addItem("A3 position");
    ui->comboBox->addItem("A1 force");
    ui->comboBox->addItem("A2 force");
    ui->comboBox->addItem("A3 force");

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_change(int)));

}

graphWnd::~graphWnd()
{
    delete ui;
}

void graphWnd::on_graph_data(float * data, int time)
{
    static int stream_blocker=0;
    if (turned_on)
    {
        if (!was_first_time)
        {
            first_time = time/1000.0;
            was_first_time = true;
        }

        for (int i=0;i<6;i++)
            dat[i].append((data[i]*180)/M_PI);
        for (int i=6;i<30;i++)
            dat[i].append(data[i]);
        t.append(time/1000.0);
        double devia = sqrt(pow(data[18]-data[24],2)+ pow(data[19]-data[25],2)+ pow(data[20]-data[26],2));
        deviation.append(devia);

        int size_around = t.size() * sizeof(double) * 32;
        ui->label_3->setText("Size: " + QString::number(static_cast<int>(size_around/1024.0)) + "kB");

        if (currentComboBoxItemSelected==1){
            for (int i=0;i<6;i++)
                 ui->plot1->graph(i)->setData(t,dat[i]);

            if (ui->checkBox->isChecked())
                ui->plot1->xAxis->setRange(first_time,time/1000.0);
            else{
                double time_window = (double)ui->horizontalSlider->value();
                double time_min = time/1000.0 - time_window;
                if (time_min<0) time_min = 0;
                if (ui->horizontalScrollBar->value() == 100) ui->plot1->xAxis->setRange(time_min,time_min + time_window);
                else
                {
                   double slider_pos = (((double)ui->horizontalScrollBar->value())*time/1000.0)/100.0;
                   ui->plot1->xAxis->setRange(slider_pos - time_window,slider_pos);
                }
            }
            ui->plot1->yAxis->setRange(-180,180);
            ui->plot1->replot();

        }else if (currentComboBoxItemSelected==2){
            for (int i=0;i<6;i++)
                 ui->plot1->graph(i)->setData(t,dat[i+6]);
            if (ui->checkBox->isChecked())
                ui->plot1->xAxis->setRange(first_time,time/1000.0);
            else{
                double time_window = (double)ui->horizontalSlider->value();
                double time_min = time/1000.0 - time_window;
                if (time_min<0) time_min = 0;
                if (ui->horizontalScrollBar->value() == 100) ui->plot1->xAxis->setRange(time_min,time_min + time_window);
                else
                {
                   double slider_pos = (((double)ui->horizontalScrollBar->value())*time/1000.0)/100.0;
                   ui->plot1->xAxis->setRange(slider_pos - time_window,slider_pos);
                }
            }
            int vertical = ui->verticalScrollBar->value();
            ui->plot1->yAxis->setRange(-0.2*vertical,0.2*vertical);
            ui->plot1->replot();

        }else if (currentComboBoxItemSelected==3){
            for (int i=0;i<3;i++)
                 ui->plot1->graph(i)->setData(t,dat[i+6+6]);
            if (ui->checkBox->isChecked())
                ui->plot1->xAxis->setRange(first_time,time/1000.0);
            else{
                double time_window = (double)ui->horizontalSlider->value();
                double time_min = time/1000.0 - time_window;
                if (time_min<0) time_min = 0;
                if (ui->horizontalScrollBar->value() == 100) ui->plot1->xAxis->setRange(time_min,time_min + time_window);
                else
                {
                   double slider_pos = (((double)ui->horizontalScrollBar->value())*time/1000.0)/100.0;
                   ui->plot1->xAxis->setRange(slider_pos - time_window,slider_pos);
                }
            }
            int vertical = ui->verticalScrollBar->value();
            ui->plot1->yAxis->setRange(-0.002*vertical,0.002*vertical);
            ui->plot1->replot();
        }else if (currentComboBoxItemSelected==4){
            for (int i=0;i<3;i++)
                 ui->plot1->graph(i)->setData(t,dat[i+6+6+3]);
            if (ui->checkBox->isChecked())
                ui->plot1->xAxis->setRange(first_time,time/1000.0);
            else{
                double time_window = (double)ui->horizontalSlider->value();
                double time_min = time/1000.0 - time_window;
                if (time_min<0) time_min = 0;
                if (ui->horizontalScrollBar->value() == 100) ui->plot1->xAxis->setRange(time_min,time_min + time_window);
                else
                {
                   double slider_pos = (((double)ui->horizontalScrollBar->value())*time/1000.0)/100.0;
                   ui->plot1->xAxis->setRange(slider_pos - time_window,slider_pos);
                }
            }
            int vertical = ui->verticalScrollBar->value();
            ui->plot1->yAxis->setRange(-0.8*vertical,0.8*vertical);
            ui->plot1->replot();
        }else if (currentComboBoxItemSelected==5){
            ui->plot1->graph(0)->setData(t,deviation);
            if (ui->checkBox->isChecked())
                ui->plot1->xAxis->setRange(first_time,time/1000.0);
            else{
                double time_window = (double)ui->horizontalSlider->value();
                double time_min = time/1000.0 - time_window;
                if (time_min<0) time_min = 0;
                if (ui->horizontalScrollBar->value() == 100) ui->plot1->xAxis->setRange(time_min,time_min + time_window);
                else
                {
                   double slider_pos = (((double)ui->horizontalScrollBar->value())*time/1000.0)/100.0;
                   ui->plot1->xAxis->setRange(slider_pos - time_window,slider_pos);
                }
            }
            int vertical = ui->verticalScrollBar->value();
            ui->plot1->yAxis->setRange(-0.001*vertical,0.001*vertical);
            ui->plot1->replot();
        }else if (currentComboBoxItemSelected==6){
            if(!(stream_blocker%10))
            {
                ui->plot1->graph(0)->setData(dat[18],dat[19]);
                ui->plot1->graph(1)->setData(dat[24],dat[25]);
                ui->plot1->xAxis->setRange(-1.2,1.2);
                ui->plot1->yAxis->setRange(-1.2,1.2);
                ui->plot1->replot();
            }
            stream_blocker++;
        }else if (currentComboBoxItemSelected==7){
            if(!(stream_blocker%10))
            {
                ui->plot1->graph(0)->setData(dat[18],dat[20]);
                ui->plot1->graph(1)->setData(dat[24],dat[26]);
                ui->plot1->xAxis->setRange(-1.2,1.2);
                ui->plot1->yAxis->setRange(0,2.4);
                ui->plot1->replot();
            }
            stream_blocker++;
        }else if (currentComboBoxItemSelected==8){
            if(!(stream_blocker%10))
            {
                ui->plot1->graph(0)->setData(dat[19],dat[20]);
                ui->plot1->graph(1)->setData(dat[25],dat[26]);
                ui->plot1->xAxis->setRange(-1.2,1.2);
                ui->plot1->yAxis->setRange(0,2.4);
                ui->plot1->replot();
            }
            stream_blocker++;
        }else if (currentComboBoxItemSelected>=9&&currentComboBoxItemSelected<=14){
                 ui->plot1->graph(0)->setData(t,dat[currentComboBoxItemSelected-9]);
            if (ui->checkBox->isChecked())
                ui->plot1->xAxis->setRange(first_time,time/1000.0);
            else{
                double time_window = (double)ui->horizontalSlider->value();
                double time_min = time/1000.0 - time_window;
                if (time_min<0) time_min = 0;
                if (ui->horizontalScrollBar->value() == 100) ui->plot1->xAxis->setRange(time_min,time_min + time_window);
                else
                {
                   double slider_pos = (((double)ui->horizontalScrollBar->value())*time/1000.0)/100.0;
                   ui->plot1->xAxis->setRange(slider_pos - time_window,slider_pos);
                }
            }
            ui->plot1->yAxis->setRange(-180,180);
            ui->plot1->replot();
        }else if (currentComboBoxItemSelected>=15&&currentComboBoxItemSelected<=20){
                ui->plot1->graph(0)->setData(t,dat[currentComboBoxItemSelected-9]);
                if (ui->checkBox->isChecked())
                    ui->plot1->xAxis->setRange(first_time,time/1000.0);
                else{
                    double time_window = (double)ui->horizontalSlider->value();
                    double time_min = time/1000.0 - time_window;
                    if (time_min<0) time_min = 0;
                    if (ui->horizontalScrollBar->value() == 100) ui->plot1->xAxis->setRange(time_min,time_min + time_window);
                    else
                    {
                       double slider_pos = (((double)ui->horizontalScrollBar->value())*time/1000.0)/100.0;
                       ui->plot1->xAxis->setRange(slider_pos - time_window,slider_pos);
                    }
                }
                int vertical = ui->verticalScrollBar->value();
                ui->plot1->yAxis->setRange(-0.2*vertical,0.2*vertical);
                ui->plot1->replot();
        }else if (currentComboBoxItemSelected>=21&&currentComboBoxItemSelected<=23){
            ui->plot1->graph(0)->setData(t,dat[currentComboBoxItemSelected-9]);
            if (ui->checkBox->isChecked())
                ui->plot1->xAxis->setRange(first_time,time/1000.0);
            else{
                double time_window = (double)ui->horizontalSlider->value();
                double time_min = time/1000.0 - time_window;
                if (time_min<0) time_min = 0;
                if (ui->horizontalScrollBar->value() == 100) ui->plot1->xAxis->setRange(time_min,time_min + time_window);
                else
                {
                   double slider_pos = (((double)ui->horizontalScrollBar->value())*time/1000.0)/100.0;
                   ui->plot1->xAxis->setRange(slider_pos - time_window,slider_pos);
                }
            }
            int vertical = ui->verticalScrollBar->value();
            ui->plot1->yAxis->setRange(-0.002*vertical,0.002*vertical);
            ui->plot1->replot();

        }else if (currentComboBoxItemSelected>=24&&currentComboBoxItemSelected<=26){
            ui->plot1->graph(0)->setData(t,dat[currentComboBoxItemSelected-9]);
            if (ui->checkBox->isChecked())
                ui->plot1->xAxis->setRange(first_time,time/1000.0);
            else{
                double time_window = (double)ui->horizontalSlider->value();
                double time_min = time/1000.0 - time_window;
                if (time_min<0) time_min = 0;
                if (ui->horizontalScrollBar->value() == 100) ui->plot1->xAxis->setRange(time_min,time_min + time_window);
                else
                {
                   double slider_pos = (((double)ui->horizontalScrollBar->value())*time/1000.0)/100.0;
                   ui->plot1->xAxis->setRange(slider_pos - time_window,slider_pos);
                }
            }
            int vertical = ui->verticalScrollBar->value();
            ui->plot1->yAxis->setRange(-0.8*vertical,0.8*vertical);
            ui->plot1->replot();

        }
    }
}

void graphWnd::on_comboBox_change(int i)
{
    currentComboBoxItemSelected = i;
    if (i==1){
        ui->plot1->clearGraphs();
        for (int i=0;i<6;i++)
        {
             ui->plot1->addGraph();
             //ui->plot1->graph(i)->setData(t,dat[i]);
        }
        ui->plot1->graph(0)->setPen(QPen(Qt::red));
        ui->plot1->graph(0)->setName("Q1");
        ui->plot1->graph(1)->setPen(QPen(Qt::gray));
        ui->plot1->graph(1)->setName("Q2");
        ui->plot1->graph(2)->setPen(QPen(Qt::black));
        ui->plot1->graph(2)->setName("Q3");
        ui->plot1->graph(3)->setPen(QPen(Qt::blue));
        ui->plot1->graph(3)->setName("Q4");
        ui->plot1->graph(4)->setPen(QPen(Qt::green));
        ui->plot1->graph(4)->setName("Q5");
        ui->plot1->graph(5)->setPen(QPen(Qt::yellow));
        ui->plot1->graph(5)->setName("Q6");
        ui->plot1->legend->setVisible(true);
        ui->plot1->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("q[deg]");
    }else if (i==2){
        ui->plot1->clearGraphs();
        for (int i=0;i<6;i++)
             ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::red));
        ui->plot1->graph(0)->setName("Q1");
        ui->plot1->graph(1)->setPen(QPen(Qt::gray));
        ui->plot1->graph(1)->setName("Q2");
        ui->plot1->graph(2)->setPen(QPen(Qt::black));
        ui->plot1->graph(2)->setName("Q3");
        ui->plot1->graph(3)->setPen(QPen(Qt::blue));
        ui->plot1->graph(3)->setName("Q4");
        ui->plot1->graph(4)->setPen(QPen(Qt::green));
        ui->plot1->graph(4)->setName("Q5");
        ui->plot1->graph(5)->setPen(QPen(Qt::yellow));
        ui->plot1->graph(5)->setName("Q6");
        ui->plot1->legend->setVisible(true);
        ui->plot1->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("T[Nm]");
    }else if (i==3){
        ui->plot1->clearGraphs();
        for (int i=0;i<3;i++)
             ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::blue));
        ui->plot1->graph(0)->setName("A1");
        ui->plot1->graph(1)->setPen(QPen(Qt::red));
        ui->plot1->graph(1)->setName("A2");
        ui->plot1->graph(2)->setPen(QPen(Qt::green));
        ui->plot1->graph(2)->setName("A3");
        ui->plot1->legend->setVisible(true);
        ui->plot1->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("x[m]");
    }else if (i==4){
        ui->plot1->clearGraphs();
        for (int i=0;i<3;i++)
             ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::blue));
        ui->plot1->graph(0)->setName("A1");
        ui->plot1->graph(1)->setPen(QPen(Qt::red));
        ui->plot1->graph(1)->setName("A2");
        ui->plot1->graph(2)->setPen(QPen(Qt::green));
        ui->plot1->graph(2)->setName("A3");
        ui->plot1->legend->setVisible(true);
        ui->plot1->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("F[N]");
    }else if (i==5){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::blue));
        ui->plot1->graph(0)->setName("Tip-Target");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("D[m]");
    }else if (i==6){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::blue));
        ui->plot1->graph(0)->setName("Tip position (XY)");
        ui->plot1->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->plot1->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::blue, Qt::blue,1.2));
        ui->plot1->addGraph();
        ui->plot1->graph(1)->setPen(QPen(Qt::red));
        ui->plot1->graph(1)->setName("Target position (XY)");
        ui->plot1->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->plot1->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::red, Qt::red,1.2));
        ui->plot1->legend->setVisible(true);
        ui->plot1->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);
        ui->plot1->xAxis->setLabel("X[m]");
        ui->plot1->yAxis->setLabel("Y[m]");
    }else if (i==7){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::blue));
        ui->plot1->graph(0)->setName("Tip position (XZ)");
        ui->plot1->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->plot1->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::blue, Qt::blue,1.2));
        ui->plot1->addGraph();
        ui->plot1->graph(1)->setPen(QPen(Qt::red));
        ui->plot1->graph(1)->setName("Target position (XZ)");
        ui->plot1->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->plot1->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::red, Qt::red,1.2));
        ui->plot1->legend->setVisible(true);
        ui->plot1->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);
        ui->plot1->xAxis->setLabel("X[m]");
        ui->plot1->yAxis->setLabel("Z[m]");
    }else if (i==8){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::blue));
        ui->plot1->graph(0)->setName("Tip position (YZ)");
        ui->plot1->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->plot1->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::blue, Qt::blue,1.2));
        ui->plot1->addGraph();
        ui->plot1->graph(1)->setPen(QPen(Qt::red));
        ui->plot1->graph(1)->setName("Target position (YZ)");
        ui->plot1->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->plot1->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::red, Qt::red,1.2));
        ui->plot1->legend->setVisible(true);
        ui->plot1->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);
        ui->plot1->xAxis->setLabel("Y[m]");
        ui->plot1->yAxis->setLabel("Z[m]");
    }else if(i==9){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::red));
        ui->plot1->graph(0)->setName("Q1");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("q[deg]");
    }else if(i==10){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::gray));
        ui->plot1->graph(0)->setName("Q2");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("q[deg]");
    }else if(i==11){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::black));
        ui->plot1->graph(0)->setName("Q3");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("q[deg]");
    }else if(i==12){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::blue));
        ui->plot1->graph(0)->setName("Q4");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("q[deg]");
    }else if(i==13){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::green));
        ui->plot1->graph(0)->setName("Q5");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("q[deg]");
    }else if(i==14){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::yellow));
        ui->plot1->graph(0)->setName("Q6");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("q[deg]");
    }else if(i==15){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::red));
        ui->plot1->graph(0)->setName("Q1");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("T[Nm]");
    }else if(i==16){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::gray));
        ui->plot1->graph(0)->setName("Q2");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("T[Nm]");
    }else if(i==17){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::black));
        ui->plot1->graph(0)->setName("Q3");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("T[Nm]");
    }else if(i==18){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::blue));
        ui->plot1->graph(0)->setName("Q4");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("T[Nm]");
    }else if(i==19){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::green));
        ui->plot1->graph(0)->setName("Q5");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("T[Nm]");
    }else if(i==20){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::yellow));
        ui->plot1->graph(0)->setName("Q6");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("T[Nm]");
    }else if(i==21){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::blue));
        ui->plot1->graph(0)->setName("A1");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("x[m]");
    }else if(i==22){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::red));
        ui->plot1->graph(0)->setName("A2");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("x[m]");
    }else if(i==23){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::green));
        ui->plot1->graph(0)->setName("A3");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("x[m]");
    }else if(i==24){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::blue));
        ui->plot1->graph(0)->setName("A1");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("F[N]");
    }else if(i==25){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::red));
        ui->plot1->graph(0)->setName("A2");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("F[N]");
    }else if(i==26){
        ui->plot1->clearGraphs();
        ui->plot1->addGraph();
        ui->plot1->graph(0)->setPen(QPen(Qt::green));
        ui->plot1->graph(0)->setName("A3");
        ui->plot1->legend->setVisible(false);
        ui->plot1->xAxis->setLabel("t[s]");
        ui->plot1->yAxis->setLabel("F[N]");
    }
        turned_on = true;
}


void graphWnd::closeEvent(QCloseEvent *event)
{
    ui->plot1->clearGraphs();
    //ui->plot1->addGraph();
    //ui->plot1->graph(0)->addData(0,0);
    ui->plot1->replot();
    turned_on = false;
    ui->comboBox->setCurrentIndex(0);
    event->accept();
}

void graphWnd::on_pB_draw_clicked()
{
    for (int i=0;i<30;i++)
        dat[i].clear();
    t.clear();
    deviation.clear();
}
