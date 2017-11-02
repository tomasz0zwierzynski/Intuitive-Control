#ifndef VSTREAM_H
#define VSTREAM_H

#include <QObject>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVector>

class vstream : public QObject
{
    Q_OBJECT
public:
    explicit vstream(QTreeWidget * tv,QObject *parent = 0);

signals:

public slots:
    void on_new_data(float*,int);

private:
    float deviation;
    void calculateDeviation(float,float,float,float,float,float);

    QTreeWidget * treeView;
    QTreeWidgetItem * qPosHead;
    QTreeWidgetItem * qForHead;
    QTreeWidgetItem * aPosHead;
    QTreeWidgetItem * aForHead;
    QTreeWidgetItem * tipPosHead;
    QTreeWidgetItem * tipOriHead;
    QTreeWidgetItem * tarPosHead;
    QTreeWidgetItem * tarOriHead;
    QTreeWidgetItem * deviationHead;
    QVector<QTreeWidgetItem*> qPosItm;
    QVector<QTreeWidgetItem*> qForItm;
    QVector<QTreeWidgetItem*> aPosItm;
    QVector<QTreeWidgetItem*> aForItm;
    QVector<QTreeWidgetItem*> tipPos;
    QVector<QTreeWidgetItem*> tipOri;
    QVector<QTreeWidgetItem*> tarPos;
    QVector<QTreeWidgetItem*> tarOri;

};

#endif // VSTREAM_H
