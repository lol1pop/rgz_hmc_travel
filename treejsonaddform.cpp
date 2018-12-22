#include "treejsonaddform.h"

TreeJsonAddForm::TreeJsonAddForm()
{

}

QList<QTreeWidgetItem *> TreeJsonAddForm::jsonInTreeView(QJsonObject root)
{
    QList<QTreeWidgetItem *> listitems;
    QJsonValue jv = root.value("list");
    if(jv.isArray()){
        QJsonArray ja = jv.toArray();
        for(int i = 0; i < ja.count(); i++){
            QJsonObject subtree = ja.at(i).toObject();
            for(auto key : subtree.keys() ){
                QTreeWidgetItem *item = new QTreeWidgetItem();
                item->setText(0, key);
                QJsonValue jvChild = subtree.value(key);
                if(jvChild.isArray()){
                    QJsonArray jaChild = jvChild.toArray();
                    for(int i = 0; i < jaChild.count(); i++){
                        QJsonObject subtreeChild = jaChild.at(i).toObject();
                        QTreeWidgetItem *child = new QTreeWidgetItem();
                        for(auto keyChild : subtreeChild.keys() ){
                            child->setText(0,keyChild);
                            QString val = subtreeChild.value(keyChild).toString();
                            item->addChild(child);
                        }

                    }
                }
                listitems.push_back(item);
            }
        }
    }
    return listitems;
}

void TreeJsonAddForm::fillCboxCategories(Ui::AddData *_ui, QJsonObject root)
{
    _ui->insertBox->clear();
    QJsonValue jv = root.value("list");
    if(jv.isArray()){
        QJsonArray ja = jv.toArray();
        for(int i = 0; i < ja.count(); i++){
            QJsonObject subtree = ja.at(i).toObject();
            for(auto key : subtree.keys() ){
                _ui->insertBox->addItem(key);
            }
        }
    }
}
