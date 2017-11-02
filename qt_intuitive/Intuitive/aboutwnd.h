#ifndef ABOUTWND_H
#define ABOUTWND_H

#include <QWidget>

namespace Ui {
class aboutWnd;
}

class aboutWnd : public QWidget
{
    Q_OBJECT

public:
    explicit aboutWnd(QWidget *parent = 0);
    ~aboutWnd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::aboutWnd *ui;
};

#endif // ABOUTWND_H
