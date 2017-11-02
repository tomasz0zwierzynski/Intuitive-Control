#include "vstream.h"
#include <QDebug>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVector>

vstream::vstream(QTreeWidget * tv,QObject *parent) : QObject(parent)
{
    treeView = tv;

    treeView->setEnabled(true);
    treeView->setColumnCount(2);
    treeView->setHeaderLabels(QStringList() << "Variable" << "Value");

    //Creating headers for data table
    qPosHead = new QTreeWidgetItem(treeView);
    qPosHead->setText(0,"Q Joints Position");
    qPosHead->setText(1,"[ ]");
    treeView->addTopLevelItem(qPosHead);

    qForHead = new QTreeWidgetItem(treeView);
    qForHead->setText(0,"Q Joints Force");
    qForHead->setText(1,"[ ]");
    treeView->addTopLevelItem(qForHead);

    aPosHead = new QTreeWidgetItem(treeView);
    aPosHead->setText(0,"A Actuator Position");
    aPosHead->setText(1,"[ ]");
    treeView->addTopLevelItem(aPosHead);

    aForHead = new QTreeWidgetItem(treeView);
    aForHead->setText(0,"A Actuators Force");
    aForHead->setText(1,"[ ]");
    treeView->addTopLevelItem(aForHead);

    tipPosHead = new QTreeWidgetItem(treeView);
    tipPosHead->setText(0,"TIP position");
    tipPosHead->setText(1,"[ ]");
    treeView->addTopLevelItem(tipPosHead);

    tipOriHead = new QTreeWidgetItem(treeView);
    tipOriHead->setText(0,"TIP orientation");
    tipOriHead->setText(1,"[ ]");
    treeView->addTopLevelItem(tipOriHead);

    tarPosHead = new QTreeWidgetItem(treeView);
    tarPosHead->setText(0,"Target position");
    tarPosHead->setText(1,"[ ]");
    treeView->addTopLevelItem(tarPosHead);

    tarOriHead = new QTreeWidgetItem(treeView);
    tarOriHead->setText(0,"Target orientation");
    tarOriHead->setText(1,"[ ]");
    treeView->addTopLevelItem(tarOriHead);

    deviationHead = new QTreeWidgetItem(treeView);
    deviationHead->setText(0,"Tip-Target position deviation");
    treeView->addTopLevelItem(deviationHead);

    //Adding instances
    for (int i=0;i<6;i++)
    {
        qPosItm.append(new QTreeWidgetItem(qPosHead));
        qForItm.append(new QTreeWidgetItem(qForHead));

        qPosItm.at(i)->setText(0,"Q"+QString::number(i+1));
        qForItm.at(i)->setText(0,"Q"+QString::number(i+1));

    }
    for (int i=0;i<3;i++)
    {
        aPosItm.append(new QTreeWidgetItem(aPosHead));
        aForItm.append(new QTreeWidgetItem(aForHead));
        tipPos.append(new QTreeWidgetItem(tipPosHead));
        tipOri.append(new QTreeWidgetItem(tipOriHead));
        tarPos.append(new QTreeWidgetItem(tarPosHead));
        tarOri.append(new QTreeWidgetItem(tarOriHead));

        aPosItm.at(i)->setText(0,"A"+QString::number(i+1));
        aForItm.at(i)->setText(0,"A"+QString::number(i+1));
    }

    tipPos.at(0)->setText(0,"x");
    tipPos.at(1)->setText(0,"y");
    tipPos.at(2)->setText(0,"z");
    tipOri.at(0)->setText(0,"a");
    tipOri.at(1)->setText(0,"b");
    tipOri.at(2)->setText(0,"g");
    tarPos.at(0)->setText(0,"x");
    tarPos.at(1)->setText(0,"y");
    tarPos.at(2)->setText(0,"z");
    tarOri.at(0)->setText(0,"a");
    tarOri.at(1)->setText(0,"b");
    tarOri.at(2)->setText(0,"g");
}

void vstream::on_new_data(float * d,int time)
{
    //qDebug() << "Dane zostaly przekazane.";
    for(int i=0;i<6;i++)
    {
        qPosItm.at(i)->setText(1,QString::number((float)d[i],'g',6));
    }
    for (int i=0;i<6;i++)
    {
        qForItm.at(i)->setText(1,QString::number((float)d[i+6],'g',6));
    }
    for (int i=0;i<3;i++)
    {
        aPosItm.at(i)->setText(1,QString::number((float)d[i+6+6],'g',6));
    }
    for (int i=0;i<3;i++)
    {
        aForItm.at(i)->setText(1,QString::number((float)d[i+6+6+3],'g',6));
    }
    for (int i=0;i<3;i++)
    {
        tipPos.at(i)->setText(1,QString::number((float)d[i+6+6+3+3],'g',6));
    }
    for (int i=0;i<3;i++)
    {
        tipOri.at(i)->setText(1,QString::number((float)d[i+6+6+3+3+3],'g',6));
    }
    for (int i=0;i<3;i++)
    {
        tarPos.at(i)->setText(1,QString::number((float)d[i+6+6+3+3+3+3],'g',6));
    }
    for (int i=0;i<3;i++)
    {
        tarOri.at(i)->setText(1,QString::number((float)d[i+6+6+3+3+3+3+3],'g',6));
    }

    calculateDeviation(d[6+6+3+3+0],d[6+6+3+3+1],d[6+6+3+3+2],d[6+6+3+3+3+3+0],d[6+6+3+3+3+3+1],d[6+6+3+3+3+3+2]);
    deviationHead->setText(1,QString::number(deviation));

    //qDebug() << time;
}

void vstream::calculateDeviation(float x_t, float y_t, float z_t, float x_ta, float y_ta, float z_ta)
{
    deviation = sqrt((x_t-x_ta)*(x_t-x_ta) + (y_t-y_ta)*(y_t-y_ta) + (z_t-z_ta)*(z_t-z_ta));
}
