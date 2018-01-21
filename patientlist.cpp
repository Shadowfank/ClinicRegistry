 #include "patientlist.h"
#include "ui_patientlist.h"

patientlist::patientlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patientlist)
{
    ui->setupUi(this);
    getpatient();
}

patientlist::~patientlist()
{
    delete ui;
}

void patientlist::getpatient()
{
    QSqlQuery query = QSqlQuery(db.r_db());
    model = new QSqlQueryModel();
    query.prepare("select `id`,`surname`, `fname`, `thname`, `birth_day`, `datecome`, `timecome`, `sex`, `region`, `city`, `street`, `house`, `apartment`, `phone_number`, `name_doctor` from patients");
    query.exec();
    model->setQuery(query);
    ui->tablePatients->setModel(model);
    model->setQuery(query);
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Прізвище"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ім'я"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("По-батькові"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Дата народження"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Дата явки"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Час явки"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Стать"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Область"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Місто"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Вулиця"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Дім"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("Квартира"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("Тел. номер"));
    model->setHeaderData(14, Qt::Horizontal, QObject::tr("Ім'я лікаря"));
    ui->tablePatients->setModel(model);
    ui->tablePatients->setColumnWidth(0,30);
    ui->tablePatients->setColumnWidth(4,110);
    ui->tablePatients->setColumnWidth(5,67);
    ui->tablePatients->setColumnWidth(6,67);
    ui->tablePatients->setColumnWidth(11,40);
    ui->tablePatients->setColumnWidth(12,60);
    ui->tablePatients->setColumnWidth(13,110);
    ui->tablePatients->setColumnWidth(14,190);
}

void patientlist::on_tablePatients_clicked(const QModelIndex &index)
{
    QModelIndex n = QModelIndex(index.sibling(index.row(),0));
    patientid = n.data().toInt();
}
void patientlist::on_pushButton_4_clicked()
{
    database db;
    QSqlQuery query;
    query.prepare("Delete from patients where id=:id");
    query.bindValue(":id",patientid);

    if (query.exec()){
        QMessageBox::information(this, tr("Видалення"), tr("Видалено"),QMessageBox::Ok);
        getpatient();
        qDebug()<<query.lastError();
    }
    else
        QMessageBox::critical(this, tr("Помилка"), query.lastError().text());
}
void patientlist::on_psearch_Button_clicked()
{
    database db;
    QString surname;
    QSqlQuery query;
    model = new QSqlQueryModel();
    query.prepare("SELECT * FROM patients WHERE surname like '%"+ui->patient_search->text()+"%'");
    query.exec();
    qDebug()<<query.lastError();
    model->setQuery(query);
    ui->tablePatients->setModel(model);
}

void patientlist::on_pushButton_2_clicked()
{
    database db;
    QString surname;
    QSqlQuery query;
    model = new QSqlQueryModel();
    query.prepare("select * from patients order by surname");
    query.exec();
    qDebug()<<query.lastError();
    model->setQuery(query);
    ui->tablePatients->setModel(model);
}

void patientlist::on_pushButton_3_clicked()
{
    database db;
    QString surname;
    QSqlQuery query;
    model = new QSqlQueryModel();
    query.prepare("select * from patients order by surname desc");
    query.exec();
    qDebug()<<query.lastError();
    model->setQuery(query);
    ui->tablePatients->setModel(model);
}

void patientlist::on_pushButton_5_clicked()
{
    mainWindow = new MainWindow(0, this, true, patientid);
    mainWindow->setFixedSize(mainWindow->size());
    mainWindow->show();
}

void patientlist::on_pushButton_6_clicked()
{
    mainWindow = new MainWindow(this);
    hide();
    mainWindow->setFixedSize(mainWindow->size());
    mainWindow->show();
}

void patientlist::on_pushButton_7_clicked()
{
    //s = new patientlist();
    mainWindow = new MainWindow(this);
    mainWindow->setFixedSize(mainWindow->size());
    mainWindow->show();
}
