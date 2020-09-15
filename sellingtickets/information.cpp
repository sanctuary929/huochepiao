#include "information.h"
#include "ui_information.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QPushButton>

information::information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("车票信息查询");
    ui->start->hide();
    ui->price->hide();
    ui->name2->hide();
    ui->ID2->hide();
    ui->end->hide();
    ui->start_->hide();
    ui->end_->hide();
    ui->ID2_->hide();
    ui->name2_->hide();
    ui->price_->hide();
    //设置返回
    connect(ui->back,&QPushButton::clicked,this,&information::sendSlot_3);
}

information::~information()
{
    delete ui;
}

void information::on_t_clicked()
{
    idstr=ui->ID_->text();
    namestr=ui->name_->text();
    QFile file4;
    file4.setFileName("../wenjianming");
    bool isok2=file4.open(QIODevice::ReadOnly);
    if(true==isok2)
    {
        QTextStream stream1 (&file4);
        stream1.setCodec("UTF-8");
        stream1>>filename[0];
        file4.close();
    }
    filename[1]="../passenger-information";
    while (filename[0]!=filename[1])
    {
        filename[1]=filename[1]+"1";
        QFile file5;
        file5.setFileName(filename[1]);
        bool isok3=file5.open(QIODevice::ReadOnly);
        if (true==isok3)
        {
            QTextStream stream3 (&file5);
            stream3.setCodec("UTF-8");
            stream3>>stratstr>>endstr>>idstr1>>namestr2>>cost;
            file5.close();
        }
        if (idstr==idstr1)
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
    {   ui->start->show();
        ui->name2->show();
        ui->ID2->show();
        ui->end->show();
        ui->price->show();
        ui->start_->show();
        ui->end_->show();
        ui->ID2_->show();
        ui->name2_->show();
        ui->price_->show();
        ui->start_->setText(stratstr);
        ui->end_->setText(endstr);
        ui->ID2_->setText(idstr1);
        ui->name2_->setText(namestr2);
        ui->price_->setText(cost);
    }
    else  QMessageBox::about(this,"错误","对不起，没有该乘客信息");
    flag=0;
}

void information::sendSlot_3()
{
    emit Mysignal_3();
    ui->start_->setText("");
    ui->end_->setText("");
    ui->ID2_->setText("");
    ui->name2_->setText("");
    ui->price_->setText("");
    ui->ID_->setText("");
    ui->name_->setText("");
    ui->start_->hide();
    ui->price_->hide();
    ui->name2_->hide();
    ui->ID2_->hide();
    ui->end_->hide();
    ui->start->hide();
    ui->end->hide();
    ui->ID2->hide();
    ui->name2->hide();
    ui->price->hide();

}
