#ifndef PATIENTLIST_H
#define PATIENTLIST_H
#include "mainwindow.h"
#include "database.h"
#include <QWidget>

namespace Ui {
class patientlist;
}

class patientlist : public QWidget
{
    Q_OBJECT

public:
    explicit patientlist(QWidget *parent = 0);
    ~patientlist();
    void getpatient();

private slots:

private:
    Ui::patientlist *ui;
    database db;
    QSqlQueryModel *model;
};

#endif // PATIENTLIST_H
