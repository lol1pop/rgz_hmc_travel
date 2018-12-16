#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

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
    _ui->tableView->setColumnHidden (4,true);
    _ui->tableView->setColumnHidden (8,true);

}
void initComboBox(Ui::MainWindow* _ui){
    QList<QString> list;
    list << "name" << "country" << "route" << "lasting" <<"trans"<<"wether";
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
