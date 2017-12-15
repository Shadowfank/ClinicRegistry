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

void doctorlist::on_pushButton_3_clicked()
{
    a = new adddoctor();
    a->setFixedSize(a->size());
    a->show();
}
