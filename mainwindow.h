#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql/QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include "database.h"
#include "formcardtraveler.h"
#include "formlisttravel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void editStatusTree(QString);
private:
    void initalComponents();

private slots:
    void on_updateBtn_clicked();

    void on_addBtn_clicked();

    void on_searchBtn_clicked();

    void on_removeBtn_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_putBtn_clicked();

    void on_unPutBtn_clicked();

    void on_saleBtn_clicked();

    void on_insertBtn_clicked();

    void on_delBtn_clicked();

    void on_cardTravelBtn_clicked();

    void on_listTravelBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
