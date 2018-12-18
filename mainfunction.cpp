#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QTreeView>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

void viewDataBase(Ui::MainWindow* _ui){
    /*QSqlQuery query;
    if(query.exec("SELECT * FROM adventure")){
    qDebug() << "Succsesfull." << query.lastQuery();
    query.next();
    qDebug() << "value(0):" << query.value(0).toString() << " value(1):" << query.value(1).toString();
    }else {
        qDebug() << "ERROR::Exception, uncorrect query." << query.lastQuery();
    }*/

    QSqlTableModel *tableModel;
    tableModel = new QSqlTableModel();
    tableModel->setTable("adventure");
    tableModel->select();
    _ui->tableView->setModel(tableModel);
    _ui->tableView->setColumnHidden (0,true);
    _ui->tableView->setColumnHidden (1,true);
    _ui->tableView->setColumnHidden (4,true);
    _ui->tableView->setColumnHidden (3,true);
    _ui->tableView->setColumnHidden (8,true);

}
void initComboBox(Ui::MainWindow* _ui){
    QList<QString> list;
    list << "country" << "lasting" <<"trans"<<"wether";
    _ui->searchBox->addItems(list);
}

int searchComboBox(Ui::MainWindow* _ui){
    switch (_ui->searchBox->currentIndex()) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 5;
    case 4:
        return 6;
    case 5:
        return 7;
    default:
        return 0;
    }
}

void simulatedClik(){

}

QJsonObject parsefilejson(){
    // QString val = R"_({"list":[{"categoryname":"одежда","stuff":[{"name":"футболка","status":"not_put"},{"name":"шорты","status":"not_put"},{"name":"джинсы","status":"not_put"},{"name":"кепка","status":"not_put"},{"name":"купальник","status":"not_put"}]},{"categoryname":"обувь","stuff":[{"name":"кроссовки","status":"not_put"}]}]})_";
     QString val;
      QFile file;
      file.setFileName("test.json");
      file.open(QIODevice::ReadOnly | QIODevice::Text);
      val = file.readAll();
      file.close();
      //qWarning() << val;
      QJsonDocument document = QJsonDocument::fromJson(val.toUtf8());
    return document.object();;
}

QJsonObject parsefilejson(QString val){
    // QString val = R"_({"list":[{"categoryname":"одежда","stuff":[{"name":"футболка","status":"not_put"},{"name":"шорты","status":"not_put"},{"name":"джинсы","status":"not_put"},{"name":"кепка","status":"not_put"},{"name":"купальник","status":"not_put"}]},{"categoryname":"обувь","stuff":[{"name":"кроссовки","status":"not_put"}]}]})_";
    QJsonDocument document = QJsonDocument::fromJson(val.toUtf8());
    return document.object();;
}

void initTreeView(Ui::MainWindow* _ui,QString val ){
   _ui->treeWidget->clear();
   QList<QTreeWidgetItem *> listitems;
   QJsonObject root ;
   _ui->treeWidget->setColumnCount(2);
   if(val != ""){
       root = parsefilejson(val);
   }else{
      root = parsefilejson();
   }

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

                        }}
                         listitems.push_back(item);
                   }
               }
           }
           _ui->treeWidget->addTopLevelItems(listitems);
}
