#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "database.h"
#include <QMessageBox>
#include <QMainWindow>
#include "doctorlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    doctorlist *d;
};

#endif // MAINWINDOW_H
