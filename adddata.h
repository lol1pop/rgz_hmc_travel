#ifndef ADDDATA_H
#define ADDDATA_H

#include <QWidget>
#include "imgwork.h"
#include "database.h"
#include "mainwindow.h"
#pragma once
#include <functional>
#include <iostream>

namespace Ui {
class AddData;
}

typedef void(MainWindow::*t_updateMainFunc)();

class AddData : public QWidget
{
    Q_OBJECT

private:
    QPixmap bufImg;
    QString name;
    QString country;
    QString route;
    QString list_things;
    int lasting;
    QString trans;
    QString wether;
    QByteArray photo;
    QString link;
    Ui::AddData *ui;
    QString strJsonList;
    t_updateMainFunc updateMainFunc;
    std::function<void()> updatFun;

public:
    explicit AddData(QWidget *parent = nullptr,std::function<void()> = nullptr);
    ~AddData();

private slots:
    void on_loadBtn_clicked();
    void on_addBtn_clicked();
    void on_addCategoriesButton_clicked();
    void on_addStaffButton_clicked();
    void on_delSelBtn_clicked();
    void initalComponents();
    void updateDataBase();

    void on_AddData_destroyed();

private:
    bool initEdit();

};

#endif // ADDDATA_H
