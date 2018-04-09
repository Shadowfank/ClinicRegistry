#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "mainwindow.h"
#include <QCryptographicHash>
#include "database.h"
#include "doctorlist.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_login_Button_clicked();

    void on_Guest_Button_clicked();

    void on_show_pass_toggled(bool checked);

    void on_lineEdit_password_returnPressed();

    void on_pushButton_clicked();

private:
    Ui::login *ui;
    MainWindow  *mainWindow;
    database db;
    doctorlist *d;
};

#endif // LOGIN_H
