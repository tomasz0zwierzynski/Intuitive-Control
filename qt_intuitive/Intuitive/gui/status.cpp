#include "status.h"
#include <QStatusBar>

#include <QDebug>

Status::Status(QStatusBar *sb, QObject *parent) : QObject(parent)
{
    statusBar = sb;
    statusLabelLeft = new QLabel("Left");
    statusLabelMid = new QLabel("Mid");
    statusLabelRight = new QLabel("Right");
    //statusBar->addPermanentWidget(statusLabelLeft);
    //statusBar->addPermanentWidget(statusLabelMid);
    statusBar->addPermanentWidget(statusLabelRight);

}

void Status::errorOccured(QString err)
{
    //qDebug() << err;
    statusLabelRight->setStyleSheet("QLabel { color : red; }");
    statusLabelRight->setText(err);
}

void Status::informationOccured(QString info)
{
    //qDebug() << info;
    statusLabelRight->setStyleSheet("QLabel { color : blue; }");
    statusLabelRight->setText(info);
}
