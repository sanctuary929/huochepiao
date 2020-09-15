#ifndef BUY_H
#define BUY_H

#include <QDialog>
#include <QString>

namespace Ui {
class buy;
}

class buy : public QDialog
{
    Q_OBJECT

public:
    explicit buy(QWidget *parent = nullptr);
    ~buy();
    void sendSlot_1();
private slots:
    void on_confirm_clicked();

    void on_back_clicked();

signals:
    void Mysignal_1();

private:
    Ui::buy *ui;
    QString startstr,endstr,namestr,idstr,pricestr;
    QString filename[2];
    QString station[11]={"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10"};
    int j=0,flag1=0,flag2=0,a1,a2,a3,a4,cost=0,min1;
    int distance[9]={10,20,30,40,50,60,70,80,90};
    int seat[10]={10,10,10,10,10,10,10,10,10,10};
};
#endif // BUY_H
