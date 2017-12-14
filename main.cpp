#include "mainwindow.h"
#include "login.h"
#include "patientlist.h"
#include "doctorlist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.show();
    w.setFixedSize(w.size());

    return a.exec();
}
