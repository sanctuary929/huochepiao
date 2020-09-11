#include "restticket.h"
#include "ui_restticket.h"

restticket::restticket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::restticket)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("余票查询");
}

restticket::~restticket()
{
    delete ui;
}
