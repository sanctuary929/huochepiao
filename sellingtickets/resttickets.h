#ifndef RESTTICKETS_H
#define RESTTICKETS_H

#include <QDialog>
#include <QString>

namespace Ui {
class resttickets;
}

class resttickets : public QDialog
{
    Q_OBJECT

public:
    explicit resttickets(QWidget *parent = nullptr);
    ~resttickets();
    void sendSlot_2();

private slots:
    void on_search_clicked();

signals:
    void Mysignal_2();

private:
    Ui::resttickets *ui;
    QString station[11]={"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10"};
    int seat[10]={10,10,10,10,10,10,10,10,10,10};
    int distance [9]={30,40,50,60,70,60,50,40,30};
    QString stratstr,endstr,stratstr1,endstr1;
    QString filename[2];
    int i=0,a1,a2,a3,a4,min1,cost1=0,flag1=0,flag2=0;
};

#endif // RESTTICKETS_H
