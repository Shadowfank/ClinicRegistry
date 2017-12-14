#include "database.h"
database::database()
{

}
void database::connect()
{
db = QSqlDatabase::addDatabase("QMYSQL");
db.setHostName("localhost");
db.setDatabaseName("kyrsova");
db.setUserName("root");
db.setPassword("root");
if (!db.open())
    qDebug() << db.lastError().text();
else qDebug() << "Підключено";
}
QSqlDatabase database::r_db()
{
    return db;
}
bool database::log_in(QString _login, QString _pass)
{
    QSqlQuery query = QSqlQuery(db);

query.exec("select * from login where login='" + _login + "' and pass ='" + _pass + "';");

    bool i = 0;

    while(query.next()) i=true;

    if (i == 1) qDebug() << "Логін і пароль правильний !";

    return i;
}
