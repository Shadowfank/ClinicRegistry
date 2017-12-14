#include "adddoctor.h"
#include "ui_adddoctor.h"

adddoctor::adddoctor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adddoctor)
{
    ui->setupUi(this);
}

adddoctor::~adddoctor()
{
    delete ui;
}
