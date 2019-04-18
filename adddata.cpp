#include "adddata.h"
#include "ui_adddata.h"
#include <QMessageBox>
#include "adddatafunction.cpp"

AddData::AddData(QWidget *parent,std::function<void()> updateMAin) :
    QWidget(parent),
    ui(new Ui::AddData)
{
    setWindowIcon(QIcon(":/icon.png"));
    ui->setupUi(this);
    initalComponents();
    this->updatFun = updateMAin;

}

AddData::~AddData()
{
    delete ui;
}
void AddData::initalComponents()
{
    QString list("{\"list\": []}");
    initTreeView(ui, list);
}

void AddData::updateDataBase()
{
    updatFun();
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
                                       strJsonList,
                                       lasting,
                                       trans,
                                       wether,
                                       photo,
                                       link);
        updateDataBase();
         this->close();
    }

}

bool isHex(const QString &str){
  QRegExp reg("[0-9a-hA-H]+");
  return reg.indexIn(str) != -1;
}

bool AddData::initEdit()
{
    if( !ui->lineEdit->text().isEmpty()){name = ui->lineEdit->text();}else{
        QMessageBox::information(this,"Name:", "Заполните Иям!!");
        return false;}

    if( !ui->lineEdit_2->text().isEmpty()){country = ui->lineEdit_2->text();}else{
        QMessageBox::information(this,"country:", "Заполните Страну!!");
        return false;}

    if( !ui->lineEdit_3->text().isEmpty()){route = ui->lineEdit_3->text();}else{
        QMessageBox::information(this,"route:", "Заполните маршрут!!");
        return false;}

    if( !ui->lineEdit_4->text().isEmpty()){
        bool check;
        int hex = ui->lineEdit_4->text().toInt(&check, 16);
        if(check){lasting = hex;}else{
            QMessageBox::information(this,"lasting:", "Если по твоему это число то мне жаль тебя!!");
            return false;
        }
    }else{
        QMessageBox::information(this,"Name Search:", "Заполните Число дней!!");
        return false;}

    if( !ui->lineEdit_5->text().isEmpty()){ trans = ui->lineEdit_5->text();}else{
        QMessageBox::information(this,"transport:", "На какой карете попреш?!");
        return false;}

    if( !ui->lineEdit_6->text().isEmpty()){wether = ui->lineEdit_6->text();}else{
        QMessageBox::information(this,"wether:", "пойти что-ли самому глянуть что за окном ?!");
        return false;}

    if( !bufImg.isNull()){photo = ImgWork::setImg(bufImg);}else{
        QMessageBox::information(this,"photo:", "Подожди сейчас сам тебя сфоткую, ты этого хотел услышать?!");
        return false;}

    if( !ui->lineEdit_7->text().isEmpty()){link = ui->lineEdit_7->text();}else{
        QMessageBox::information(this,"link:", "Заполните все ссылку!!");
        return false;}


     return true;
}

void AddData::on_addCategoriesButton_clicked()
{
    if(!ui->categoriesEdit->text().isEmpty()){
        QString categori(ui->categoriesEdit->text());
        QJsonObject jsonList(treeListHandler::insertToJson(strJsonList,categori));
        QJsonDocument doc(jsonList);
        strJsonList = doc.toJson(QJsonDocument::Compact);
        initTreeView(ui, strJsonList);
    }else{
         QMessageBox::information(this,"categorie:", "да ты на до мной смешься!!");
    }
}

void AddData::on_addStaffButton_clicked()
{
    if(!ui->staffEdit->text().isEmpty()){
        QString categories(ui->insertBox->currentText());
        QString staff(ui->staffEdit->text());
        QJsonObject jsonList(treeListHandler::insertToJson(strJsonList,categories,staff));
        QJsonDocument doc(jsonList);
        strJsonList = doc.toJson(QJsonDocument::Compact);
        initTreeView(ui, strJsonList);

    }else{
         QMessageBox::information(this,"categorie:", "да ты на до мной смешься!!");
    }
}

void AddData::on_delSelBtn_clicked()
{
    try {
        QString keyDel(ui->treeWidget->currentItem()->text(0));
        QJsonObject jsonList(treeListHandler::removeFromJson(strJsonList,keyDel));
        QJsonDocument doc(jsonList);
        strJsonList = doc.toJson(QJsonDocument::Compact);
        initTreeView(ui, strJsonList);

    } catch (QString e) {
        QMessageBox::information(this,"categorie:", "Шота ты сломал и делаешь не правильно друг, глянь ка на это:" + e);
    }
}



void AddData::on_AddData_destroyed()
{

}
