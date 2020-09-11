#include "refund.h"
#include "ui_refund.h"

refund::refund(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::refund)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("退票");
}

refund::~refund()
{
    delete ui;
}
