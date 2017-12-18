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
    d = new adddoctor();
    d->setFixedSize(d->size());
    d->show();
}

void doctorlist::getdoctor()
{
    QSqlQuery query = QSqlQuery(db.r_db());
    model = new QSqlQueryModel();
    query.prepare("select `id`, `surname`, `fname`, `thname`, `specialty`, `day`, `time_1`, `time_2` from doctors");
    query.exec();
    model->setQuery(query);
    ui->tableDoctors->setModel(model);
}
