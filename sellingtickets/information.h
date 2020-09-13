#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>
#include <QString>

namespace Ui {
class information;
}

class information : public QDialog
{
    Q_OBJECT

public:
    explicit information(QWidget *parent = nullptr);
    ~information();
    void sendSlot_3();
private slots:
    void on_pushButton_clicked();

    void on_t_clicked();
signals:
    void Mysignal_3();

private:
    Ui::information *ui;
    QString idstr,namestr;
    QString idstr1,namestr2,stratstr,endstr,cost;
    QString filename[2];
    int flag=0;
};

#endif // INFORMATION_H
