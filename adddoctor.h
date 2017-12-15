#ifndef ADDDOCTOR_H
#define ADDDOCTOR_H
#include "database.h"
#include <QWidget>
#include <QMessageBox>

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
};

#endif // ADDDOCTOR_H
