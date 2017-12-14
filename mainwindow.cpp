#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
        QMessageBox::critical(this, tr("Збереження"), tr("Збережено"));
    }
    else
        QMessageBox::critical(this, tr("Помилка"), query.lastError().text());
}
