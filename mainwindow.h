#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "database.h"
#include <QMessageBox>
#include <QMainWindow>
#include "doctorlist.h"
#include "patientlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, class patientlist *s_ = 0, bool _mode = false, int _patientID = 0);
    ~MainWindow();
    void loadNameOfDocs();
    //getpatient();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    class doctorlist *d;
    class patientlist *s;
    QSqlQueryModel *model;
    bool mode;
    int patientID;
};

#endif // MAINWINDOW_H
