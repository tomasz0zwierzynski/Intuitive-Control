#include "setwnd.h"
#include "ui_setwnd.h"

setWnd::setWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setWnd)
{
    ui->setupUi(this);
}

setWnd::~setWnd()
{
    delete ui;
}

void setWnd::on_pushButton_3_clicked()
{
    this->close();
}
