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
    void CorrectColums();
    void getpatient();

private slots:

    void on_pushButton_4_clicked();

    void on_psearch_Button_clicked();

    void on_tablePatients_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::patientlist *ui;
    database db;
    //class MainWindow *previous;
    QSqlQueryModel *model;
    int patientid;
    class MainWindow  *mainWindow;
    class patientlist *s;
};

#endif // PATIENTLIST_H
