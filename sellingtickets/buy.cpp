#include "buy.h"
#include "ui_buy.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QDebug>

buy::buy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buy)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("购票");
    connect(ui->back,&QPushButton::clicked,this,&buy::sendSlot_1);
    ui->label->hide();
}

buy::~buy()
{
    delete ui;
}

void buy::on_confirm_clicked()
{
    startstr=ui->start_->text();
    endstr=ui->end_->text();
    namestr=ui->name_->text();
    idstr=ui->ID_->text();
    while (j<10)
    {
        if (startstr==station[j]) flag1=1;
        if (endstr==station[j]) flag2=1;
        j++;
    }
    if (flag1==1&&flag2==0)
        QMessageBox::about(this,"错误","很抱歉，没有此终点站，请重新输入");
    if (flag1==0&&flag2==1)
        QMessageBox::about(this,"错误","很抱歉，没有此起点站，请重新输入");
    if (flag1==0&&flag2==0)
        QMessageBox::about(this,"错误","很抱歉，没有此起点站和终点站，请重新输入");
    if (idstr=="")
        QMessageBox::about(this,"错误","身份证不能为空！");
    if (namestr=="")
        QMessageBox::about(this,"错误","姓名不能为空！");
    if (flag1==1&&flag2==1&&idstr!=""&&namestr!="")
    {
    j=0;
    while (j<10)
    {
    if (startstr==station[j]) a1=j;
    if (endstr==station[j]) a2=j;
    j++;
    }
    j=a1;
    while (j<a2)
    {
        cost=cost+distance[j];
        j++;
    }
    j=0;
    QString cost1=QString::number(cost,10);
    QFile file3;
    file3.setFileName("../wenjianming");
    bool isOK2=file3.open(QIODevice::ReadOnly);
    if (true==isOK2)
    {
        QTextStream stream3 (&file3);
        stream3.setCodec("UTF-8");
        stream3>>filename[0];
        file3.close();
    }
    else filename[0]="../passenger-information";

    QFile file1;
    filename[1]=filename[0]+"1";
    file1.setFileName(filename[1]);
    bool isOk=file1.open(QIODevice::WriteOnly);
    if (true==isOk)
    {
        QTextStream stream1 (&file1);
        stream1.setCodec("UTF-8");
        stream1<<startstr<<" "<<endstr<<" "<<idstr<<" "<<namestr<<" "<<cost1;
        file1.close();
    }
    QFile file2;
    file2.setFileName("../wenjianming");
    bool isOK1=file2.open(QIODevice::WriteOnly);
    if (true==isOK1)
    {
        QTextStream stream2 (&file2);
        stream2.setCodec("UTF-8");
        stream2<<filename[1];
        file2.close();
    }
    QMessageBox::about(this,"成功买票","您已成功买票，谢谢");
    ui->label->show();
    ui->label->setText(cost1);
    }
    flag1=0;
    flag2=0;
    j=0;
    ui->start_->setText("");
    ui->end_->setText("");
    ui->name_->setText("");
    ui->ID_->setText("");
    ui->label->setText("");
}
void buy::sendSlot_1()
{
    emit Mysignal_1();
}
