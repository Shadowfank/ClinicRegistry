#ifndef ADDDOCTOR_H
#define ADDDOCTOR_H
#include "database.h"
#include <QWidget>
#include <QMessageBox>
#include "mainwindow.h"
#include "doctorlist.h"

namespace Ui {
class adddoctor;
}

class adddoctor : public QWidget
{
    Q_OBJECT

public:
    explicit adddoctor(QWidget *parent = 0, class doctorlist *prev_ = 0);
    ~adddoctor();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adddoctor *ui;
    class adddoctor *a;
    class doctorlist *prev;
};

#endif // ADDDOCTOR_H
