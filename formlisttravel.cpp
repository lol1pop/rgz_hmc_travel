#include "formlisttravel.h"
#include "ui_formlisttravel.h"
#include <QDebug>
#include <QList>
#include "imgwork.h"
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QPoint>
#include <QMessageBox>


FormListTravel::FormListTravel(QWidget *parent, Tur* ture) :
    QWidget(parent),
    ui(new Ui::FormListTravel)
{
    if(ture != nullptr){ this->tur = *ture; qDebug() << "tur" << this->tur.name << " : "<< this->tur.img; } else{ qDebug() << "tur = nullptr";}
    this->position = 0;
    this->lenghtList = 0;
    ui->setupUi(this);

}

FormListTravel::~FormListTravel()
{
    delete ui;
}

void FormListTravel::on_saveBatn_clicked()
{
    if(!imgSlot.isNull() && !ui->nameEdit->text().isEmpty() && !ui->routEdit->toPlainText().isEmpty() && !ui->reportEdit->toPlainText().isEmpty()){
        Cart newCart(imgSlot,ui->nameEdit->text(),ui->routEdit->toPlainText(),ui->reportEdit->toPlainText());
        this->listCart.push_back(newCart);
        qDebug() << "new " << newCart.name;
    }else{
         QMessageBox::information(this,"Save:", "Заполните все поля!!");
    }

    qDebug()<< "old len: "<<lenghtList;
    lenghtList = listCart.length();
    qDebug()<< "new len: "<<lenghtList;
}

void FormListTravel::on_addImg_clicked()
{
    imgSlot = ImgWork::loadImg(300,260);
    ui->imgSlot->setPixmap(imgSlot);
}

void FormListTravel::on_editBtn_clicked()
{
    if(listCart.length() != 0){

        QPrinter printer;
        printer.setOrientation(QPrinter::Landscape);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName("travelGuide.pdf");
        QPainter painter(&printer);
        QRect printer_rect(printer.pageRect());
        int heightStillHave = printer_rect.height();
//======================= data main form ========================
        QTextDocument doc;
        doc.setPageSize(printer_rect.size());
        doc.setPlainText("\t\t\t"+this->tur.name +"\n\n" +
                         "Маршрут Вашего Тура : " +this->tur.route +":\n\n" );
        QRect docRect = QRect(QPoint(0,0), doc.size().toSize());
        QRect photoRect =  QRect(QPoint(0,0), this->tur.img.size());

        painter.resetMatrix();
        painter.translate(100,50);
        doc.drawContents(&painter,docRect);
        painter.translate(0,docRect.height());
        painter.drawPixmap(photoRect,this->tur.img,photoRect);


//===============================================================

//        QTextDocument text;
//        text.setPageSize(printer_rect.size());
//        text.setPlainText("");
//        QRect textRect = QRect(QPoint(0,0), text.size().toSize());
//        QRect imgRect =  QRect(QPoint(0,0), imgSlot.size());

//        painter.translate((-1)*(photoRect.width() + 10),imgRect.height() + 50);
//        painter.drawPixmap(imgRect,imgSlot,imgRect);
//        painter.translate(imgRect.width() + 50,0);
//        painter.drawPixmap(img2Rect,img2Slot,img2Rect);
//        painter.translate((-1)*(imgRect.width() + 50) ,img2Rect.height() + 50);
//        text.drawContents(&painter, textRect);



        QMessageBox::information(this,"Name Search:", "TravelGide.pdf create!!");
        close();

    }else{
        QMessageBox::information(this,"Save:", "пустоту не сохранишь!");
    }
}
