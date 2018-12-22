#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "treejson.h"
#include <QTreeWidgetItem>
#include "jsonwork.cpp"




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
    _ui->tableView->setColumnHidden (3,true);
    _ui->tableView->setColumnHidden (4,true);
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
        return 2;
    case 1:
        return 5;
    case 2:
        return 6;
    case 3:
        return 7;
    default:
        return 0;
    }
}


void simulatedClik(){

}

void initTreeView(Ui::MainWindow* _ui,QString val ){
   _ui->treeWidget->clear();
   _ui->treeWidget->setColumnCount(2);
   _ui->treeWidget->header()->resizeSection(0,200);
   _ui->treeWidget->header()->resizeSection(1,60);

   QJsonObject root ;

   if(val != ""){
       root = parseJson(val);
   QList<QTreeWidgetItem *> listitems = TreeJson::jsonInTreeView(root);
   _ui->treeWidget->addTopLevelItems(listitems);
   TreeJson::fillCboxCategories(_ui,root);
   }
}


