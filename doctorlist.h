#ifndef DOCTORLIST_H
#define DOCTORLIST_H
#include "adddoctor.h"
#include <QWidget>
#include "mainwindow.h"
#include "adddoctor.h"
#include "database.h"

namespace Ui {
class doctorlist;
}

class doctorlist : public QWidget
{
    Q_OBJECT

public:
    explicit doctorlist(QWidget *parent = 0, class MainWindow *_prev= 0);
    ~doctorlist();
    void getdoctor();

private slots:
    void on_pushButton_3_clicked();

   // void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_tableDoctors_clicked(const QModelIndex &index);

    void on_dsearch_Button_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::doctorlist *ui;
    class adddoctor *a;
    class MainWindow *prev;
    database db;
    QSqlQueryModel *model;
    int doctorid;
};

#endif // DOCTORLIST_H
