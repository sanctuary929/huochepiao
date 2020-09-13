#ifndef REFUND_H
#define REFUND_H

#include <QDialog>
#include <QString>

namespace Ui {
class refund;
}

class refund : public QDialog
{
    Q_OBJECT

public:
    explicit refund(QWidget *parent = nullptr);
    ~refund();
    void sendslot4 ();

signals:
    void Mysignal_4 ();

private slots:
    void on_confirm_clicked();

private:
    Ui::refund *ui;
    QString startstr,endstr,idstr,namestr;
    QString idstr1,namestr1;
    QString filename[2],filename1;
    int flag=0;
    int flag1=0;
};

#endif // REFUND_H
