#include "refund.h"
#include "ui_refund.h"
#include <QPushButton>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

refund::refund(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::refund)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("退票");
    connect(ui->back,&QPushButton::clicked,this,&refund::sendslot4);
}

refund::~refund()
{
    delete ui;
}

void refund::sendslot4()
{
    emit Mysignal_4();
}

void refund::on_confirm_clicked()
{
    idstr1=ui->ID_->text();
    namestr1=ui->name_->text();
    if (idstr1=="")
        QMessageBox::about(this,"错误","身份证不能为空！");
    if (namestr1=="")
        QMessageBox::about(this,"错误","姓名不能为空");
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
            stream2>>startstr>>endstr>>idstr>>namestr;
            file2.close();
        }
        if (idstr==idstr1)
        {
            flag=1;
            filename1=filename[0];
            break;
        }
    }
    if (flag==1)
    {
    QFile file3;
    file3.remove(filename1);
    QMessageBox::about(this,"退票","已成功退票");
    }
    else QMessageBox::about(this,"错误","无该乘客信息，无法退票");
    filename[0]="../passenger-information";
    while (filename[0]!=filename[1])
    {
       filename[0]=filename[0]+"1";
       QFile file4;
       file4.setFileName(filename[0]);
       bool isok4=file4.open(QIODevice::ReadOnly);
       if (true==isok4)
       {
           flag1=1;
           file4.close();
       }
    }
    QFile file5;
    if (flag1==0) file5.remove("../data");
    flag1=0;
    ui->ID_->setText("");
    ui->name_->setText("");
}
