#include "adddoctor.h"
#include "ui_adddoctor.h"

adddoctor::adddoctor(QWidget *parent, class doctorlist *prev_, bool _mode, int _docID) :
    QWidget(parent), prev(prev_), docID(_docID), mode(_mode),
    ui(new Ui::adddoctor)
{
    ui->setupUi(this);
    if (mode)
    {
        database db;
        QSqlQuery query =  QSqlQuery(db.r_db());
        QString surname, fname, thname, specialty, day;
        QTime time_1, time_2;


        query.prepare("select `doctors`.`id`,`surname`, `fname`, `thname`, `specialty`, `day`, `time_1`, `time_2` from `doctors` where `doctors`.`id` = :id;");
        query.bindValue(":id",docID);
        query.exec();
        while(query.next())
        {
            surname = query.value(1).toString();
            fname= query.value(2).toString();
            thname= query.value(3).toString();
            specialty= query.value(4).toString();
            day= query.value(5).toString();
            time_1= query.value(6).toTime();
            time_2= query.value(7).toTime();
        }
        qDebug()<<query.lastError()<<surname;

        ui->sname->setText(surname);
        ui->name->setText(fname);
        ui->tname->setText(thname);
        ui->specialty_->setText(specialty);
        ui->day_->setCurrentText(day);
        ui->time_one->setTime(time_1);
        ui->time_two->setTime(time_2);
        ui->pushButton->setEnabled(0);
    }
    else
        ui->pushButton_2->setEnabled(0);
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
    query.prepare("replace into doctors (`id`, `surname`, `fname`, `thname`, `specialty`, `day`, `time_1`, `time_2`)"
                  "values (:id,:surname,:fname,:thname,:specialty,:day,:time_1,:time_2)");
       query.bindValue(":id", docID);
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
        prev->getdoctor();
}
    else
          QMessageBox::critical(this, tr("Помилка"), query.lastError().text());
}
