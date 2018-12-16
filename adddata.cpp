#include "adddata.h"
#include "ui_adddata.h"

AddData::AddData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddData)
{
    ui->setupUi(this);
}

AddData::~AddData()
{
    delete ui;
}

void AddData::on_loadBtn_clicked()
{
    QPixmap img = bufImg = ImgWork::loadImg(180,220);
    ui->imgSlot->setPixmap( img );
}

void AddData::on_addBtn_clicked()
{
    if(initEdit()){
        Database::createNodeAdventure( name,
                                       country,
                                       route,
                                       list_things,
                                       lasting,
                                       trans,
                                       wether,
                                       photo,
                                       link);
    }

    this->close();
}

bool AddData::initEdit()
{
     name = ui->lineEdit->text();
     country = ui->lineEdit_2->text();
     route = ui->lineEdit_3->text();
     list_things = ui->textEdit->toPlainText();
     lasting = ui->lineEdit_4->text().toInt();
     trans = ui->lineEdit_5->text();
     wether = ui->lineEdit_6->text();
     photo = ImgWork::setImg(bufImg);
     link = ui->lineEdit_7->text();

     return true;
}
