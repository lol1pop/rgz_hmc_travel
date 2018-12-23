#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainfunction.cpp"
#include "adddata.h"
#include "imgwork.h"
#include "treejson.h"
#include <QTreeView>
#include <QJsonObject>
#include <QMessageBox>
#include "entities.h"

#pragma once
#include <functional>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);
    initalComponents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initalComponents()
{
    initStyle();
    initComboBox(ui);
    viewDataBase(ui);
    initTreeView(ui, "");
}

void MainWindow::initStyle()
{
    setWindowIcon(QIcon(":/icon.png"));
    ui->updateBtn->setIcon(QIcon(":/icon/res/icon/icon_(5).png"));
    ui->addBtn->setIcon(QIcon(":/icon/res/icon/iconbtn(2).png"));
    ui->delBtn->setIcon(QIcon(":/icon/res/icon/status(5).png"));
    ui->putBtn->setIcon(QIcon(":/icon/res/icon/status(2).png"));
    ui->saleBtn->setIcon(QIcon(":/icon/res/icon/status(1).png"));
    ui->unPutBtn->setIcon(QIcon(":/icon/res/icon/status(4).png"));
    ui->insertBtn->setIcon(QIcon(":/icon/res/icon/status(3).png"));
    ui->removeBtn->setIcon(QIcon(":/icon/res/icon/iconbtn(1).png"));
}

void MainWindow::updateBtn()
{
    viewDataBase(ui);

}

void MainWindow::on_updateBtn_clicked()
{
    FormInfo *info1 = new FormInfo(nullptr);
    info1->show();
}

void MainWindow::on_addBtn_clicked()
{
    AddData *ad = new AddData(nullptr, [&](){MainWindow::updateBtn();});
    ad->show();
}

void MainWindow::on_searchBtn_clicked()
{
    QAbstractItemModel *modl = ui->tableView->model();
    QSortFilterProxyModel proxy;
    proxy.setSourceModel(modl);
    proxy.setFilterKeyColumn(searchComboBox(ui));
    proxy.setFilterFixedString(ui->searchEdit->text());
    QModelIndex matchingIndex = proxy.mapToSource(proxy.index(0,0));
    if(matchingIndex.isValid()){
        ui->tableView->scrollTo(matchingIndex,QAbstractItemView::EnsureVisible);
        ui->tableView->selectRow(matchingIndex.row());
        ui->tableView->setStyleSheet("QTableView::item:selected{background-color: palette(highlight); color: palette(highlightedText);};");
                on_tableView_clicked(matchingIndex);
    } else {
         ui->tableView->selectionModel()->clearSelection();
        QMessageBox::information(this,"Name Search:", "Match not found!");
    }
}

void MainWindow::on_removeBtn_clicked()
{
   int row = ui->tableView->currentIndex().row();
   ui->tableView->model()->removeRow(row);

   ui->nameTravel->setText( "" );
   ui->routTravel->setText( "" );
   ui->imgSlot->clear();

   viewDataBase(ui);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QByteArray arr(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),8)).toByteArray());
    ImgWork::placeImgLable(arr, ui->imgSlot);
    QString list(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString());
    initTreeView(ui, list);
    ui->nameTravel->setText( ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString());
    ui->routTravel->setText( ui->tableView->model()->data(ui->tableView->model()->index(index.row(),3)).toString());
}


void MainWindow::editStatusTree(QString status)
{
    QString strJsonList(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString());
    QString keyEdit(ui->treeWidget->currentItem()->text(0));
    QJsonObject jsonList(editJson(strJsonList,keyEdit,status));
    QJsonDocument doc(jsonList);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    ui->tableView->model()->setData(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4),strJson);
}


void MainWindow::on_putBtn_clicked()
{
    if( ui->treeWidget->currentItem()->text(1) != "status"){
        ui->treeWidget->currentItem()->setBackgroundColor(0,QColor(29,120,29,127));
        ui->treeWidget->currentItem()->setBackgroundColor(1,QColor(29,120,29,127));
        ui->treeWidget->currentItem()->setText(1,"put");
        editStatusTree("put");}
}

void MainWindow::on_unPutBtn_clicked()
{
    if( ui->treeWidget->currentItem()->text(1) != "status"){
        ui->treeWidget->currentItem()->setBackgroundColor(0,QColor(255,0,0,127));
        ui->treeWidget->currentItem()->setBackgroundColor(1,QColor(255,0,0,127));
        ui->treeWidget->currentItem()->setText(1,"not_put");
        editStatusTree("not_put");}
}

void MainWindow::on_saleBtn_clicked()
{
    if( ui->treeWidget->currentItem()->text(1) != "status"){
        ui->treeWidget->currentItem()->setBackgroundColor(0,QColor(163,163,42,127));
        ui->treeWidget->currentItem()->setBackgroundColor(1,QColor(163,163,42,127));
        ui->treeWidget->currentItem()->setText(1,"sale");
        editStatusTree("sale");}
}


void MainWindow::on_insertBtn_clicked()
{
    if(!ui->lineEdit->text().isEmpty()){

        QString strJsonList(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString());
        QJsonObject jsonList(insertToJson(strJsonList,ui->lineEdit->text()));
        QJsonDocument doc(jsonList);
        QString strJson(doc.toJson(QJsonDocument::Compact));
        ui->tableView->model()->setData(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4),strJson);
        QString list(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString());
        ui->lineEdit->clear();
        initTreeView(ui, list);
    } else {
     if(!ui->insertEdit->text().isEmpty()){
    QString categories(ui->insertBox->currentText());
    QString staff(ui->insertEdit->text());
    QString strJsonList(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString());
    QJsonObject jsonList(insertToJson(strJsonList,categories,staff));
    QJsonDocument doc(jsonList);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    ui->tableView->model()->setData(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4),strJson);
    QString list(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString());
    initTreeView(ui, list);
     }else{
        QMessageBox::information(this,"add Tree","А Можно добовлять не пустоту?");
    }}

}

void MainWindow::on_delBtn_clicked()
{
    QString strJsonList(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString());
    QString keyDel(ui->treeWidget->currentItem()->text(0));
    QJsonObject jsonList(removeFromJson(strJsonList,keyDel));
    QJsonDocument doc(jsonList);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    ui->tableView->model()->setData(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4),strJson);
    QString list(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString());
    initTreeView(ui, list);
}

void MainWindow::on_cardTravelBtn_clicked()
{
    FormCardTraveler *fct = new FormCardTraveler();
    fct->show();
}

void MainWindow::on_listTravelBtn_clicked()
{


    if(ui->nameTravel->text().isEmpty() || ui->nameTravel->text() == "Название Поездки"){
        FormListTravel *flt = new FormListTravel();
        flt->show();
    }else{
    Tur tur;
    tur.name = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),1)).toString();
    tur.route =  ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),3)).toString();
    QByteArray inByteArray(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),8)).toByteArray());
    tur.img.loadFromData(inByteArray);
    FormListTravel *flt = new FormListTravel(nullptr,&tur);
    flt->show();}
}
