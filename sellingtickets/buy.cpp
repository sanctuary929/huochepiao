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
    //设置返回
    connect(ui->back,&QPushButton::clicked,this,&buy::sendSlot_1);
    ui->label->hide();
}

buy::~buy()
{
    delete ui;
}

void buy::on_confirm_clicked()
{
    //初始化
    min1=10;
    flag1=0;
    flag2=0;
    j=0;
    startstr=ui->start_->text();
    endstr=ui->end_->text();
    namestr=ui->name_->text();
    idstr=ui->ID_->text();
    for (int k=0;k<10;k++)
    {
        seat[k]=10;
    }
    //判断有无输入的起点站和终点站
    for (j=0;j<10;j++) {
        if (startstr==station[j]) flag1=1;
        if (endstr==station[j]) flag2=1;
    }
    if (flag1==1&&flag2==0)
        QMessageBox::about(this,"错误","对不起，终点站输入有误，请检查后重新输入");
    if (flag1==0&&flag2==1)
        QMessageBox::about(this,"错误","对不起，起点站输入有误，请检查后重新输入");
    if (flag1==0&&flag2==0)
        QMessageBox::about(this,"错误","对不起，起点站和终点站输入有误，请检查后重新输入");
    //判断是否输入姓名和身份证号
    if (idstr=="")
        QMessageBox::about(this,"错误","请输入身份证号！");
    if (namestr=="")
        QMessageBox::about(this,"错误","请输入姓名！");
    if (flag1==1&&flag2==1&&idstr!=""&&namestr!="")
    {
        //计算票价
        for (j=0;j<10;j++) {
            if (startstr==station[j]) a1=j;
            if (endstr==station[j]) a2=j;
        }
    cost=0;
    for (j=a1;j<a2;j++) {
        cost=cost+distance[j];
    }
    QFile file5;
    file5.setFileName("../yupiao");
    bool isok5 = file5.open(QIODevice::ReadOnly);
    if (true==isok5)
    {
        QTextStream stream5 (&file5);
        stream5.setCodec("UTF-8");
        stream5>>min1;
    if (min1==0)
        QMessageBox::about(this,"余票为0","对不起，票已售清");
    else
    {
    j=0;
    QString pricestr=QString::number(cost,10);
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
        stream1<<startstr<<" "<<endstr<<" "<<idstr<<" "<<namestr<<" "<<pricestr;
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
    QMessageBox::about(this,"购票成功","您已成功购票，祝您旅途愉快");
    ui->label->show();
    ui->label->setText(pricestr);
    }
    file5.close();
    }
    else
    QMessageBox::about(this,"error","请先查询余票，谢谢");
    }

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
