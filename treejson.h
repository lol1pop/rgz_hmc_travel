#ifndef TREEJSON_H
#define TREEJSON_H
#include <QTreeView>
#include <QTreeWidgetItem>
#include <QAbstractItemModel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include <QList>
#include <QDebug>

class TreeJson
{
public:
    TreeJson();
    static QList<QTreeWidgetItem *> jsonInTreeView(QJsonObject root);
};

#endif // TREEJSON_H
