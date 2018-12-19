#include "treejson.h"

TreeJson::TreeJson()
{

}

QList<QTreeWidgetItem *>  TreeJson::jsonInTreeView(QJsonObject root)
{
    QList<QTreeWidgetItem *> listitems;
    QJsonValue jv = root.value("list");
    if(jv.isArray()){
        QJsonArray ja = jv.toArray();
        for(int i = 0; i < ja.count(); i++){
            QJsonObject subtree = ja.at(i).toObject();
            for(auto key : subtree.keys() ){
                qWarning() <<" >"<<key;
                QTreeWidgetItem *item = new QTreeWidgetItem();
                item->setText(0, key);
                item->setText(1, "status");
                QJsonValue jvChild = subtree.value(key);
                if(jvChild.isArray()){
                    QJsonArray jaChild = jvChild.toArray();
                    for(int i = 0; i < jaChild.count(); i++){
                        QJsonObject subtreeChild = jaChild.at(i).toObject();
                        QTreeWidgetItem *child = new QTreeWidgetItem();
                        for(auto keyChild : subtreeChild.keys() ){
                            child->setText(0,keyChild);
                            QString val = subtreeChild.value(keyChild).toString();
                            child->setText(1, val);
                            if(val == "not_put"){
                                child->setBackgroundColor(0, Qt::red);
                                child->setBackgroundColor(1, Qt::red);
                            }
                            if( val == "put"){
                                child->setBackgroundColor(0, Qt::green);
                                child->setBackgroundColor(1, Qt::green);
                            }
                            if( val == "sale"){
                                child->setBackgroundColor(0, Qt::yellow);
                                child->setBackgroundColor(1, Qt::yellow);
                            }
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
