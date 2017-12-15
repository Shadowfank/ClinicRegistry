#ifndef DOCTORLIST_H
#define DOCTORLIST_H
#include "adddoctor.h"
#include <QWidget>

namespace Ui {
class doctorlist;
}

class doctorlist : public QWidget
{
    Q_OBJECT

public:
    explicit doctorlist(QWidget *parent = 0);
    ~doctorlist();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::doctorlist *ui;
    adddoctor *a;
};

#endif // DOCTORLIST_H
