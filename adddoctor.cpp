#include "adddoctor.h"
#include "ui_adddoctor.h"

adddoctor::adddoctor(QWidget *parent, class doctorlist *prev_) :
    QWidget(parent), prev(prev_),
    ui(new Ui::adddoctor)
{
    ui->setupUi(this);
}

adddoctor::~adddoctor()
{
    delete ui;
}

void adddoctor::on_pushButton_clicked()
{
    database db;
    QString surname, fname, thname, specialty, day;
    QTime time_1, time_2;

    surname=ui->sname->text();
    fname=ui->name->text();
    thname=ui->tname->text();
    specialty=ui->specialty_->text();
    day=ui->day_->currentText();
    time_1=ui->time_one->time();
    time_2=ui->time_two->time();

    QSqlQuery query =  QSqlQuery(db.r_db());
    query.prepare("insert into doctors (`id`, `surname`, `fname`, `thname`, `specialty`, `day`, `time_1`, `time_2`)"
               "values (NULL,:surname,:fname,:thname,:specialty,:day,:time_1,:time_2)");
    query.bindValue(":surname", surname);
    query.bindValue(":fname", fname);
    query.bindValue(":thname", thname);
    query.bindValue(":specialty", specialty);
    query.bindValue(":day", day);
    query.bindValue(":time_1", time_1);
    query.bindValue(":time_2", time_2);

    if (query.exec()){
        QMessageBox::information(this, tr("Збереження"), tr("Збережено"),QMessageBox::Ok);
    prev->getdoctor();
    }
    else
        QMessageBox::critical(this, tr("Помилка"), query.lastError().text());
}

void adddoctor::on_pushButton_2_clicked()
{
    database db;
    QString surname, fname, thname, specialty, day, id;
    QTime time_1, time_2;
    id=ui->id_->text();
    surname=ui->sname->text();
    fname=ui->name->text();
    thname=ui->tname->text();
    specialty=ui->specialty_->text();
    day=ui->day_->currentText();
    time_1=ui->time_one->time();
    time_2=ui->time_two->time();

    QSqlQuery query =  QSqlQuery(db.r_db());
    query.prepare("replace into doctors (`id`, `surname`, `fname`, `thname`, `specialty`, `day`, `time_1`, `time_2`)"
                  "values (:id,:surname,:fname,:thname,:specialty,:day,:time_1,:time_2)");
       query.bindValue(":id", id);
       query.bindValue(":surname", surname);
       query.bindValue(":fname", fname);
       query.bindValue(":thname", thname);
       query.bindValue(":specialty", specialty);
       query.bindValue(":day", day);
       query.bindValue(":time_1", time_1);
       query.bindValue(":time_2", time_2);

    if(query.exec()){
        QMessageBox::information(0,"Редагування даних","Дані оновлені!",QMessageBox::Ok);
        qDebug() << query.lastError() << "\n" << query.lastQuery();
        //prev->getdoctor();
}
    else
          QMessageBox::critical(this, tr("Помилка"), query.lastError().text());
}
