#ifndef DATABASE_H
#define DATABASE_H
#include <QWidget>
#include <QString>
#include <QtSql>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlQuery>

class database
{
    QSqlDatabase db;
public:
    database();

    void connect();
    QSqlDatabase r_db();
    bool log_in(QString _login, QString _pass);

};

#endif // DATABASE_H
