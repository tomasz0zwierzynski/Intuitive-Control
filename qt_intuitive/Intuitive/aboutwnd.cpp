#include "aboutwnd.h"
#include "ui_aboutwnd.h"

aboutWnd::aboutWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutWnd)
{
    ui->setupUi(this);

}

aboutWnd::~aboutWnd()
{
    delete ui;
}

void aboutWnd::on_pushButton_clicked()
{
    this->close();
}
