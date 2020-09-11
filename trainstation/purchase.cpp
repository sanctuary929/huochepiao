#include "purchase.h"
#include "ui_purchase.h"

purchase::purchase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::purchase)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("购票");
}

purchase::~purchase()
{
    delete ui;
}
