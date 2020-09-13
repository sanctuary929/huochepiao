#include "resttickets.h"
#include "ui_resttickets.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>
#include <QString>

resttickets::resttickets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resttickets)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("查询余票");
    ui->price_->hide();
    ui->rest->hide();
    ui->rest_->hide();
    ui->price->hide();
    connect(ui->back,&QPushButton::clicked,this,&resttickets::sendSlot_2);
}

resttickets::~resttickets()
{
    delete ui;
}

void resttickets::on_search_clicked()
{
    filename[0]="../passenger-information";
    QFile file1;
    file1.setFileName("../wenjianming");
    bool isok1=file1.open(QIODevice::ReadOnly);
    if (true==isok1)
    {
        QTextStream stream1 (&file1);
        stream1.setCodec("UTF-8");
        stream1>>filename[1];
        file1.close();
    }
    if    (filename[1]!="")
    {
    while (filename[0]!=filename[1])
    {
        filename[0]=filename[0]+"1";
        QFile file2;
        file2.setFileName(filename[0]);
        bool isok2=file2.open(QIODevice::ReadOnly);
        if (true==isok2)
        {
            QTextStream stream2 (&file2);
            stream2.setCodec("UTF-8");
            stream2>>stratstr>>endstr;
            file2.close();
        }
        i=0;
        while (i<10)
        {
            if (station[i]==stratstr) a1=i;
            if (station[i]==endstr)  a2=i;
            i++;
        }
        i=a1;
        while (i<=a2)
        {
            seat[i]=seat[i]-1;
            i++;
        }
        i=0;
    }
    }
    stratstr1=ui->start_->text();
    endstr1=ui->end_->text();
    i=0;
    while (i<10) {
        if (station[i]==stratstr1) flag1=1;
        if (station[i]==endstr1) flag2=1;
        i++;
    }
    i=0;
    if (flag1==0&&flag2==1)
        QMessageBox::about(this,"错误","对不起，没有该起点站");
    if (flag1==1&&flag2==0)
        QMessageBox::about(this,"错误","对不起，没有该终点站");
    if (flag1==0&&flag2==0)
        QMessageBox::about(this,"错误","对不起，没有该起点站和终点站");
    if (stratstr1=="")
        QMessageBox::about(this,"错误","对不起，车站不能为空");
    if (endstr1=="")
        QMessageBox::about(this,"错误","对不起，车站不能为空");
    if (flag1==1&&flag2==1&&stratstr1!=""&&endstr1!="")
    {
    while (i<10)
    {
        if (stratstr1==station[i]) a3=i;
        if (endstr1==station[i]) a4=i;
        i++;
    }
    min1=seat[a3];
    i=a3;
    while (i<=a4)
    {
        if (seat[i]<=min1) min1=seat[i];
        i++;
    }
    i=a3;
    while (i<a4)
    {
        cost1=cost1+distance[i];
        i++;
    }
    i=0;
    QString min11=QString::number(min1,10);
    QString cost11=QString::number(cost1,10);
    ui->rest->show();
    ui->rest_->show();
    ui->price->show();
    ui->price_->show();
    ui->rest_->setText(min11);
    ui->price_->setText(cost11);
}
    flag1=0;
    flag2=0;
    for (int i=0;i<10;i++)
    {
        seat[i]=10;
    }
}

void resttickets::sendSlot_2()
{
    emit Mysignal_2();
    ui->start_->setText("");
    ui->end_->setText("");
    ui->rest->hide();
    ui->rest_->hide();
    ui->price->hide();
    ui->price_->hide();
}
