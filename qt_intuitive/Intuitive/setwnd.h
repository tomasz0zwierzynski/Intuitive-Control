#ifndef SETWND_H
#define SETWND_H

#include <QWidget>

namespace Ui {
class setWnd;
}

class setWnd : public QWidget
{
    Q_OBJECT

public:
    explicit setWnd(QWidget *parent = 0);
    ~setWnd();

private slots:
    void on_pushButton_3_clicked();

signals:
    void SaveAndRestart();

private:
    Ui::setWnd *ui;
};

#endif // SETWND_H
