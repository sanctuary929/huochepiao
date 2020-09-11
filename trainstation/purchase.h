#ifndef PURCHASE_H
#define PURCHASE_H

#include <QMainWindow>

namespace Ui {
class purchase;
}

class purchase : public QMainWindow
{
    Q_OBJECT

public:
    explicit purchase(QWidget *parent = nullptr);
    ~purchase();

private:
    Ui::purchase *ui;
};

#endif // PURCHASE_H
