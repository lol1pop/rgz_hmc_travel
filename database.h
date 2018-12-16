#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

class Database
{
    QSqlDatabase db;

public:
    Database();
    static Database& getInstance() {
        static Database instance;
        return instance;
    }
    void initDataBase();
    void createDataBase();
    static void createNodeAdventure(QString name,
                             QString country,
                             QString route,
                             QString list_things,
                             int lasting,
                             QString trans,
                             QString wether,
                             QByteArray photo,
                             QString link);

protected:
    void sqlQuery(QString _newquery);
    void sqlQuery(QSqlQuery query);

};

#endif // DATABASE_H

//QSqlDatabase::removeDatabase("sales");
