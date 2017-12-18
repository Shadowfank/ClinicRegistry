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
    explicit adddoctor(QWidget *parent = 0);
    ~adddoctor();

private slots:
    void on_pushButton_clicked();

private:
    Ui::adddoctor *ui;
    class adddoctor *d;
};

#endif // ADDDOCTOR_H
