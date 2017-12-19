#include "doctorlist.h"
#include "ui_doctorlist.h"

doctorlist::doctorlist(QWidget *parent, class MainWindow *_prev) :
    QWidget(parent), prev(_prev),
    ui(new Ui::doctorlist)
{
    ui->setupUi(this);
    getdoctor();
}

doctorlist::~doctorlist()
{
    delete ui;
}

void doctorlist::on_pushButton_3_clicked()
{
    a = new adddoctor(0, this);
    a->setFixedSize(a->size());
    a->show();
}

void doctorlist::getdoctor()
{
    QSqlQuery query = QSqlQuery(db.r_db());
    model = new QSqlQueryModel();
    query.prepare("select `surname`, `fname`, `thname`, `specialty`, `day`, `time_1`, `time_2` from doctors");
    query.exec();
    model->setQuery(query);
    ui->tableDoctors->setModel(model);
}

void doctorlist::on_pushButton_6_clicked()
{
    hide();
    prev->show();
}

void doctorlist::on_pushButton_4_clicked()
{

}
