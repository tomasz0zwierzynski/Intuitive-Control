#ifndef STATUS_H
#define STATUS_H

#include <QObject>
#include <QString>
#include <QStatusBar>
#include <QLabel>

class Status : public QObject
{
    Q_OBJECT
public:
    explicit Status(QStatusBar *sb,QObject *parent = 0);

signals:

public slots:
    void errorOccured(QString err);
    void informationOccured(QString info);

private:
    QStatusBar *statusBar;
    QLabel *statusLabelLeft;
    QLabel *statusLabelRight;
    QLabel *statusLabelMid;
    //QString like logs or smth...
};

#endif // STATUS_H
