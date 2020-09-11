#ifndef SEARCHLEFT_H
#define SEARCHLEFT_H

#include <QMainWindow>

namespace Ui {
class searchleft;
}

class searchleft : public QMainWindow
{
    Q_OBJECT

public:
    explicit searchleft(QWidget *parent = nullptr);
    ~searchleft();

private slots:
    void on_pushButton_clicked();

private:
    Ui::searchleft *ui;
};

#endif // SEARCHLEFT_H
