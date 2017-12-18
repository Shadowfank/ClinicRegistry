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
    query.prepare("select `id`, `surname`, `fname`, `thname`, `birth_day`, `datecome`, `timecome`, `sex`, `region`, `city`, `street`, `house`, `apartment`, `phone_number`, `name_doctor` from patients");
    query.exec();
    model->setQuery(query);
    ui->tablePatients->setModel(model);
}
