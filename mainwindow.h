#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql/QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void initalComponents();

private slots:
    void on_updateBtn_clicked();

    void on_addBtn_clicked();

    void on_searchBtn_clicked();

    void on_removeBtn_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_putBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
