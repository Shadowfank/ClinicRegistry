#include "doctorlist.h"
#include "ui_doctorlist.h"

doctorlist::doctorlist(QWidget *parent, class MainWindow *_prev) :
    QWidget(parent), prev(_prev),
    ui(new Ui::doctorlist)
{
    ui->setupUi(this);
    getdoctor();
//    ui->pushButton_3->setEnabled(0);
//    ui->pushButton_4->setEnabled(0);
//    ui->pushButton_5->setEnabled(0);
//    ui->pushButton_6->setEnabled(0);

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
    query.prepare("select `id`, `surname`, `fname`, `thname`, `specialty`, `day`, `time_1`, `time_2` from doctors");
    query.exec();
    model->setQuery(query);
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Прізвище"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ім'я"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("По-батькові"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Спеціальність"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("День"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("З"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("До"));
    ui->tableDoctors->setModel(model);
    ui->tableDoctors->hideColumn(0);
    ui->tableDoctors->setColumnWidth(0,20);
    ui->tableDoctors->setColumnWidth(6,40);
    ui->tableDoctors->setColumnWidth(7,38);

}

void doctorlist::on_tableDoctors_clicked(const QModelIndex &index)
{
    QModelIndex n = QModelIndex(index.sibling(index.row(),0));
    doctorid = n.data().toInt();
}

void doctorlist::on_pushButton_4_clicked()
{
database db;
QSqlQuery query;
query.prepare("Delete from doctors where id=:id");
query.bindValue(":id",doctorid);

if (query.exec()){
    QMessageBox::information(this, tr("Видалення"), tr("Видалено"),QMessageBox::Ok);
    getdoctor();
}
else
    QMessageBox::critical(this, tr("Помилка"), query.lastError().text());
}

void doctorlist::on_dsearch_Button_clicked()
{
    database db;
    QString surname;
    QSqlQuery query;
    model = new QSqlQueryModel();
    query.prepare("SELECT * FROM doctors WHERE surname like '%"+ui->doctor_search->text()+"%'");
    query.exec();
    //qDebug()<<query.lastError();
    model->setQuery(query);
    ui->tableDoctors->setModel(model);
}

void doctorlist::on_pushButton_6_clicked()
{
    hide();
    prev->show();
}

void doctorlist::on_pushButton_clicked()
{
    database db;
    QString surname;
    QSqlQuery query;
    model = new QSqlQueryModel();
    query.prepare("select * from doctors order by surname");
    query.exec();
    qDebug()<<query.lastError();
    model->setQuery(query);
    ui->tableDoctors->setModel(model);
}

void doctorlist::on_pushButton_2_clicked()
{
    database db;
    QString surname;
    QSqlQuery query;
    model = new QSqlQueryModel();
    query.prepare("select * from doctors order by surname desc");
    query.exec();
    qDebug()<<query.lastError();
    model->setQuery(query);
    ui->tableDoctors->setModel(model);
}
void doctorlist::on_pushButton_5_clicked()
{
    a = new adddoctor(0, this, true, doctorid);
    a->setFixedSize(a->size());
    a->show();
}
