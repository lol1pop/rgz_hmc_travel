#ifndef TREEJSON_H
#define TREEJSON_H

#include <QTreeWidgetItem>
#include <QAbstractItemModel>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QList>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class TreeJson
{
public:
    TreeJson();
    static QList<QTreeWidgetItem *> jsonInTreeView(QJsonObject root);
    static void fillCboxCategories(Ui::MainWindow* _ui,QJsonObject root);
};

#endif // TREEJSON_H
