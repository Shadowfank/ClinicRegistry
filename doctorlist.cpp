#include "doctorlist.h"
#include "ui_doctorlist.h"

doctorlist::doctorlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doctorlist)
{
    ui->setupUi(this);
}

doctorlist::~doctorlist()
{
    delete ui;
}
