#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchleft.h"
#include "purchase.h"
#include "refund.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("欢迎");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   searchleft *a=new searchleft(this);
   a->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    purchase *b = new purchase(this);
    b->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    refund *c = new refund(this);
    c->show();
}
