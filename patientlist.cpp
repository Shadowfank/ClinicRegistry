 #include "patientlist.h"
#include "ui_patientlist.h"

patientlist::patientlist(QWidget *parent /*class MainWindow *_previous*/) :
    QWidget(parent), /*previous(_previous),*/
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
}
/*void patientlist::on_pushButton_6_clicked()
{
    hide();
    previous->show();
}
*/
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

}
