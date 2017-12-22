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
    query.prepare("select `surname`, `fname`, `thname`, `birth_day`, `datecome`, `timecome`, `sex`, `region`, `city`, `street`, `house`, `apartment`, `phone_number`, `name_doctor` from patients");
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

void patientlist::on_pushButton_4_clicked()
{

}

void patientlist::on_pushButton_clicked()
{
    database db;
    QString surname;
    QSqlQuery query;
    model = new QSqlQueryModel();
    query.prepare("SELECT * FROM doctors WHERE surname like '%"+ui->patient_search->text()+"%'");
    query.exec();
    qDebug()<<query.lastError();
    model->setQuery(query);
    ui->tablePatients->setModel(model);
}
