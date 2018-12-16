#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainfunction.cpp"
#include "adddata.h"
#include "imgwork.h"

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
    initComboBox(ui);
    viewDataBase(ui);
}

void MainWindow::on_updateBtn_clicked()
{
   viewDataBase(ui);
}

void MainWindow::on_addBtn_clicked()
{
    AddData *ad = new AddData();
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
   viewDataBase(ui);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QByteArray arr = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),8)).toByteArray();
    ImgWork::placeImgLable(arr, ui->imgSlot);
}
