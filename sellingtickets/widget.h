#ifndef WIDGET_H
#define WIDGET_H
#include "buy.h"
#include "information.h"
#include "refund.h"
#include "resttickets.h"


#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void deal1();
    void deal2();
    void deal3();
    void deal4();
private slots:
    void on_b_clicked();
    void on_i_clicked();
    void on_rest_clicked();
    void on_re_clicked();
private:
    Ui::Widget *ui;
    buy w1;
    information w2;
    resttickets w3;
    refund w4;
};
#endif // WIDGET_H
