#include "patientlist.h"
#include "ui_patientlist.h"

patientlist::patientlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patientlist)
{
    ui->setupUi(this);
}

patientlist::~patientlist()
{
    delete ui;
}
