#ifndef TREEJSONADDFORM_H
#define TREEJSONADDFORM_H

#include <QTreeWidgetItem>
#include <QAbstractItemModel>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QList>
#include <QDebug>
#include "adddata.h"
#include "ui_adddata.h"

class TreeJsonAddForm
{
public:
    TreeJsonAddForm();
    static QList<QTreeWidgetItem *> jsonInTreeView(QJsonObject root);
    static void fillCboxCategories(Ui::AddData* _ui,QJsonObject root);
};

#endif // TREEJSONADDFORM_H
