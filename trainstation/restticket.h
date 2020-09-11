#ifndef RESTTICKET_H
#define RESTTICKET_H

#include <QMainWindow>

namespace Ui {
class restticket;
}

class restticket : public QMainWindow
{
    Q_OBJECT

public:
    explicit restticket(QWidget *parent = nullptr);
    ~restticket();

private:
    Ui::restticket *ui;
};

#endif // RESTTICKET_H
