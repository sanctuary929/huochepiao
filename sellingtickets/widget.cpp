#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("欢迎");
    connect(&w1,&buy::Mysignal_1,this,&Widget::deal1);
    connect(&w3,&resttickets::Mysignal_2,this,&Widget::deal2);
    connect(&w2,&information::Mysignal_3,this,&Widget::deal3);
    connect(&w4,&refund::Mysignal_4,this,&Widget::deal4);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_b_clicked()
{
    this->hide();
    w1.show();
}

void Widget::on_i_clicked()
{
    this->hide();
    w2.show();
}
void Widget::deal1()
{
    w1.hide();
    this->show();
}

void Widget::on_rest_clicked()
{
    this->hide();
    w3.show();
}
void Widget::deal2()
{
    this->show();
    w3.hide();
}
void Widget::deal3()
{
    this->show();
    w2.hide();
}

void Widget::on_re_clicked()
{
    this->hide();
    w4.show();
}
void Widget::deal4()
{
    this->show();
    w4.hide();
}
