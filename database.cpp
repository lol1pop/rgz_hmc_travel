#include "database.h"

Database::Database()
{


}

void Database::initDataBase(){
    QString dbName("travledb.db");
    QFile::remove( dbName );
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    db.setUserName("root");
    db.setPassword("toor");
    db.open();
}
void Database::createDataBase(){
    if(!db.open())
        qDebug()<<"error open";

     QSqlQuery qry;
     QString cteate_table_adventure = "CREATE TABLE adventure("
                                      "trevel_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                      "name TEXT,"
                                      "country TEXT,"
                                      "route TEXT,"
                                      "list_things TEXT,"
                                      "lasting INEGER,"
                                      "trans TEXT,"
                                      "wether TEXT,"
                                      "photo BLOB,"
                                      "link TEXT);";

     if(!qry.exec(cteate_table_adventure))
         qDebug()<<"error create table dbo.Adventure";
}

void Database::sqlQuery(QString _newquery){
    QSqlQuery query;
    try {
        query.exec(_newquery);
    } catch (...)
    {
        qDebug() << "Exception, uncorrect query." << _newquery;
    }

}
void Database::sqlQuery(QSqlQuery query){
    try {
        query.exec();
    } catch (...)
    {
        qDebug() << "Exception, uncorrect query." << query.lastQuery();
    }

}

void Database::createNodeAdventure(QString name,
                                   QString country,
                                   QString route,
                                   QString list_things,
                                   int lasting,
                                   QString trans,
                                   QString wether,
                                   QByteArray photo,
                                   QString link){
    QSqlQuery query;
    query.prepare("INSERT INTO adventure (name, country, route, list_things, lasting, trans, wether, photo, link) "
                     "VALUES (:Name, :Country,:Route, :ListThings, :Lasting, :Trans, :Wether, :Photo, :Link)");
    query.bindValue(":Name", name);
    query.bindValue(":Country", country);
    query.bindValue(":Route", route);
    query.bindValue(":ListThings", list_things);
    query.bindValue(":Lasting", lasting);
    query.bindValue(":Trans", trans);
    query.bindValue(":Wether", wether);
    query.bindValue(":Photo", photo);
    query.bindValue(":Link", link);
    if(query.exec()){
    qDebug() << "Succsesfull." << query.lastQuery();}else {
        qDebug() << "ERROR::Exception, uncorrect query." << query.lastQuery();
    }
}
