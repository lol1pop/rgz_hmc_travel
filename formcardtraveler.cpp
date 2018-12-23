#include "formcardtraveler.h"
#include "ui_formcardtraveler.h"

#include "imgwork.h"
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QPoint>
#include <QMessageBox>

#include "mainwindow.h"


FormCardTraveler::FormCardTraveler(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCardTraveler)
{
    initStyle();
    ui->setupUi(this);
}

FormCardTraveler::~FormCardTraveler()
{
    delete ui;
}

void FormCardTraveler::initStyle()
{
    setWindowIcon(QIcon(":/icon.png"));

   // ui->pushButton->setIcon(QIcon(":/icon/res/icon/icon_(4).png"));
   //   ui->addPhotoBtn->setIcon(QIcon(":/icon/res/icon/icon_(6).png"));
//    ui->addImgBtn->setIcon(QIcon(":/icon/res/icon/icon_(6).png"));
//    ui->addImgBtn_2->setIcon(QIcon(":/icon/res/icon/icon_(6).png"));
}

void FormCardTraveler::on_addPhotoBtn_clicked()
{
    QPixmap img = photoSlot = ImgWork::loadImg(140,160);
    ui->yourPhoto->setPixmap( img );
}

void FormCardTraveler::on_addImgBtn_clicked()
{
    QPixmap img = imgSlot = ImgWork::loadImg(230,230);
    ui->imgSlot->setPixmap( img );
}

void FormCardTraveler::on_addImgBtn_2_clicked()
{
     QPixmap img = img2Slot = ImgWork::loadImg(230,230);
     ui->imgSlot_2->setPixmap( img );
}

void FormCardTraveler::on_pushButton_clicked()
{

    if(!ui->lineEdit->text().isEmpty() &&
       !ui->lineEdit_2->text().isEmpty()  &&
       !ui->lineEdit_3->text().isEmpty() &&
       !ui->textEdit->toPlainText().isEmpty() &&
       !photoSlot.isNull() &&
       !imgSlot.isNull() &&
       !img2Slot.isNull()){
    QPrinter printer;
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("travelCatd.pdf");
    QPainter painter(&printer);
    QRect printer_rect(printer.pageRect());

    QTextDocument doc;
    doc.setDefaultFont(QFont("Helvetica", 14));
    doc.setPageSize(printer_rect.size());
    doc.setPlainText(ui->label_2->text() +":\n" +
                     ui->lineEdit->text() +"\n" +
                     ui->label_3->text() +":\n" +
                     ui->lineEdit_2->text() +"\n" +
                     ui->label_4->text() +":\n" +
                     ui->lineEdit_3->text() +"\n" );
    QRect docRect = QRect(QPoint(0,0), doc.size().toSize());

    QTextDocument text;
    text.setDefaultFont(QFont("Helvetica", 14));
    text.setPageSize(printer_rect.size());
    text.setPlainText(ui->label->text() +":\n" + ui->textEdit->toPlainText());
    QRect textRect = QRect(QPoint(0,0), text.size().toSize());

    QRect photoRect =  QRect(QPoint(0,0), photoSlot.size());
    QRect imgRect =  QRect(QPoint(0,0), imgSlot.size());
    QRect img2Rect =  QRect(QPoint(0,0), img2Slot.size());

    painter.resetMatrix();
    painter.translate(100,50);
    painter.drawPixmap(photoRect,photoSlot,photoRect);
    painter.translate(photoRect.width() + 10,0);
    doc.drawContents(&painter,docRect);
    painter.translate((-1)*(photoRect.width() + 10),imgRect.height() + 50);
    painter.drawPixmap(imgRect,imgSlot,imgRect);
    painter.translate(imgRect.width() + 50,0);
    painter.drawPixmap(img2Rect,img2Slot,img2Rect);
    painter.translate((-1)*(imgRect.width() + 50) ,img2Rect.height() + 50);
    text.drawContents(&painter, textRect);
    QMessageBox::information(this,"Name Search:", "TravelCard.pdf create!!");

    close();
    }else{
         QMessageBox::information(this,"Name Search:", "Заполните все поля!!");
    }

}
