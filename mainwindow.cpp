#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, class patientlist *s_, bool _mode, int _patientID) :
    QMainWindow(parent), s(s_), patientID(_patientID), mode(_mode),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(mode)
    {
        database db;
        QSqlQuery query =  QSqlQuery(db.r_db());
        QString surname, fname, thname, region, city, street, house, apartment, phone_number, name_doctor;
        QDate birth_day, datecome;
        QTime timecome;
        bool sex;

        query.prepare("select `patients`.`id`,`surname`, `fname`, `thname`, `birth_day`, `datecome`, `timecome`, `sex`, `region`, `city`, `street`, `house`, `apartment`, `phone_number`, `name_doctor` from `patients` where `patients`.`id` = :id;");
        query.bindValue(":id",patientID);
        query.exec();
        while(query.next())
        {
            surname = query.value(1).toString();
            fname= query.value(2).toString();
            thname= query.value(3).toString();
            birth_day= query.value(4).toDate();
            datecome= query.value(5).toDate();
            timecome= query.value(6).toTime();
            sex= query.value(7).toBool();
            region= query.value(8).toString();
            city= query.value(9).toString();
            street= query.value(10).toString();
            house= query.value(11).toString();
            apartment= query.value(12).toString();
            phone_number= query.value(13).toString();
            name_doctor= query.value(14).toString();
        }
        qDebug()<<query.lastError()<<surname;

        ui->sname->setText(surname);
        ui->name->setText(fname);
        ui->tname->setText(thname);
        ui->b_day->setDate(birth_day);
        ui->date_come->setDate(datecome);
        ui->time_come->setTime(timecome);
        ui->sex_->setCurrentIndex(sex);
        ui->region_->setText(region);
        ui->city_->setText(city);
        ui->street_->setText(street);
        ui->house_->setText(house);
        ui->apartment_->setText(apartment);
        ui->phone_number_->setText(phone_number);
        ui->name_doctor_->setText(name_doctor);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    database db;
    QString surname, fname, thname, region, city, street, house, apartment, phone_number, name_doctor;
    QDate birth_day, datecome;
    QTime timecome;
    bool sex;

    surname=ui->sname->text();
    fname=ui->name->text();
    thname=ui->tname->text();
    birth_day=ui->b_day->date();
    datecome=ui->date_come->date();
    timecome=ui->time_come->time();
    sex =(bool) ui->sex_->currentIndex();
    region=ui->region_->text();
    city=ui->city_->text();
    street=ui->street_->text();
    house=ui->house_->text();
    apartment=ui->apartment_->text();
    phone_number=ui->phone_number_->text();
    name_doctor=ui->name_doctor_->text();

    QSqlQuery query =  QSqlQuery(db.r_db());
    query.prepare("insert into patients (`id`, `surname`, `fname`, `thname`, `birth_day`, `datecome`, `timecome`, `sex`, `region`, `city`, `street`, `house`, `apartment`, `phone_number`, `name_doctor`)"
               "values (NULL,:surname,:fname,:thname,:birth_day,:datecome,:timecome,:sex,:region,:city,:street,:house,:apartment, :phone_number, :name_doctor)");
    query.bindValue(":surname",surname);
    query.bindValue(":fname",fname);
    query.bindValue(":thname",thname);
    query.bindValue(":birth_day",birth_day);
    query.bindValue(":datecome",datecome);
    query.bindValue(":timecome",timecome);
    query.bindValue(":sex",sex);
    query.bindValue(":region",region);
    query.bindValue(":city",city);
    query.bindValue(":street",street);
    query.bindValue(":house",house);
    query.bindValue(":apartment",apartment);
    query.bindValue(":phone_number",phone_number);
    query.bindValue(":name_doctor",name_doctor);

    if (query.exec()){
        QMessageBox::information(this, tr("Збереження"), tr("Збережено"),QMessageBox::Ok);
        s->getpatient();
    }
    else
        QMessageBox::critical(this, tr("Помилка"), query.lastError().text());
}

void MainWindow::on_pushButton_2_clicked()
{
    d = new doctorlist(0,this);
    d->setFixedSize(d->size());
    d->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    s = new patientlist();
    s->setFixedSize(s->size());
    s->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    database db;
    QString surname, fname, thname, region, city, street, house, apartment, phone_number, name_doctor;
    QDate birth_day, datecome;
    QTime timecome;
    bool sex;

    surname=ui->sname->text();
    fname=ui->name->text();
    thname=ui->tname->text();
    birth_day=ui->b_day->date();
    datecome=ui->date_come->date();
    timecome=ui->time_come->time();
    sex =(bool) ui->sex_->currentIndex();
    region=ui->region_->text();
    city=ui->city_->text();
    street=ui->street_->text();
    house=ui->house_->text();
    apartment=ui->apartment_->text();
    phone_number=ui->phone_number_->text();
    name_doctor=ui->name_doctor_->text();

    QSqlQuery query =  QSqlQuery(db.r_db());
    query.prepare("replace into patients (`id`, `surname`, `fname`, `thname`, `birth_day`, `datecome`, `timecome`, `sex`, `region`, `city`, `street`, `house`, `apartment`, `phone_number`, `name_doctor`)"
               "values (:id,:surname,:fname,:thname,:birth_day,:datecome,:timecome,:sex,:region,:city,:street,:house,:apartment, :phone_number, :name_doctor)");
    query.bindValue(":id",patientID);
    query.bindValue(":surname",surname);
    query.bindValue(":fname",fname);
    query.bindValue(":thname",thname);
    query.bindValue(":birth_day",birth_day);
    query.bindValue(":datecome",datecome);
    query.bindValue(":timecome",timecome);
    query.bindValue(":sex",sex);
    query.bindValue(":region",region);
    query.bindValue(":city",city);
    query.bindValue(":street",street);
    query.bindValue(":house",house);
    query.bindValue(":apartment",apartment);
    query.bindValue(":phone_number",phone_number);
    query.bindValue(":name_doctor",name_doctor);

    if(query.exec()){
        QMessageBox::information(0,"Редагування даних","Дані оновлені!",QMessageBox::Ok);
        qDebug() << query.lastError() << "\n" << query.lastQuery();
        if(s)
        s->getpatient();
}
    else
          QMessageBox::critical(this, tr("Помилка"), query.lastError().text());
}
