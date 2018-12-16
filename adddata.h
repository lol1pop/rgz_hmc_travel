#ifndef ADDDATA_H
#define ADDDATA_H

#include <QWidget>
#include <QFileDialog>
#include <QtDebug>
#include "imgwork.h"
#include "database.h"
#include "mainwindow.h"
namespace Ui {
class AddData;
}

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

public:
    explicit AddData(QWidget *parent = nullptr);
    ~AddData();

private slots:
    void on_loadBtn_clicked();

    void on_addBtn_clicked();
private:
    bool initEdit();

};

#endif // ADDDATA_H
