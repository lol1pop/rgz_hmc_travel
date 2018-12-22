#ifndef TREELISTHANDLER_H
#define TREELISTHANDLER_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

class treeListHandler: public QObject
{
    Q_OBJECT
public:
    treeListHandler();
    static QJsonObject parseJson(QString);
    static QJsonObject editJson(QString, QString, QString);
    static QJsonObject insertToJson(QString, QString, QString);
    static QJsonObject insertToJson(QString, QString);
    static QJsonObject removeFromJson(QString, QString);
};

#endif // TREELISTHANDLER_H
