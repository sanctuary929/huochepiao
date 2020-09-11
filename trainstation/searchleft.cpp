#include "searchleft.h"
#include "ui_searchleft.h"
#include "restticket.h"

searchleft::searchleft(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchleft)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("查询结果");
}

searchleft::~searchleft()
{
    delete ui;
}

void searchleft::on_pushButton_clicked()
{
    restticket *a = new restticket(this);
    a->show();
}
