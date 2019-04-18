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
    initStyle();
    if(ture != nullptr){ this->tur = *ture; qDebug() << "tur" << this->tur.name << " : "<< this->tur.img; } else{ qDebug() << "tur = nullptr";}
    this->position = 0;
    this->yorPos = 0;
    this->lenghtList = 0;
    ui->setupUi(this);

}

FormListTravel::~FormListTravel()
{
    delete ui;
}

void FormListTravel::initStyle()
{
    setWindowIcon(QIcon(":/icon.png"));
}

void FormListTravel::on_saveBatn_clicked()
{

    if(!imgSlot.isNull() && !ui->nameEdit->text().isEmpty() && !ui->routEdit->toPlainText().isEmpty() && !ui->reportEdit->toPlainText().isEmpty()){

        if(yorPos == listCart.length()){
        Cart newCart(imgSlot,ui->nameEdit->text(),ui->routEdit->toPlainText(),ui->reportEdit->toPlainText());
        this->listCart.push_back(newCart);
        qDebug() << "new " << newCart.name;
        yorPos = listCart.length();
        qDebug()<<" edit your position:" <<yorPos;}else{
            listCart[yorPos].img = imgSlot;
            listCart[yorPos].name = ui->nameEdit->text();
            listCart[yorPos].route = ui->routEdit->toPlainText();
            listCart[yorPos].node = ui->reportEdit->toPlainText();
        }
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
        //int heightStillHave = printer_rect.height();
        //int lastsize = 0;
//======================= data main form ========================
        if(!tur.img.isNull()){
        QTextDocument doc;
        doc.setDefaultFont(QFont("Helvetica", 20));
        doc.setPageSize(printer_rect.size());
        doc.setPlainText("\t"+this->tur.name +"\n\n" +
                         "Маршрут Вашего Тура : " +this->tur.route +":\n\n" );
        QRect docRect = QRect(QPoint(0,0), doc.size().toSize());
        QRect photoRect =  QRect(QPoint(0,0), this->tur.img.size());

        painter.resetMatrix();
        painter.translate(300,100);
        doc.drawContents(&painter,docRect);
        painter.translate(0,docRect.height());
        painter.drawPixmap(photoRect,this->tur.img,photoRect);
        printer.newPage();
        printer_rect = printer.pageRect();
        painter.resetMatrix();
       // painter.translate(-300,(-1)*(photoRect.height() + docRect.height()));
        }

//===============================================================
        //int sizePage = 0;
        for (auto iter = listCart.begin(); iter != listCart.end(); iter++)
            {
                    QTextDocument nametext;
                    nametext.setDefaultFont(QFont("Helvetica", 14));
                    nametext.setPageSize(printer_rect.size());
                    nametext.setPlainText("\n \t \t  " + iter->name + "\n");
                    QRect nametextRect = QRect(QPoint(0,0), nametext.size().toSize());
                    QTextDocument text;
                    text.setDefaultFont(QFont("Helvetica", 14));
                    text.setPageSize(printer_rect.size());
                    text.setPlainText("\n \t Описание поездкит:\n \t \t " + iter->node + "\n \n \n  \t Как добраться:\n \t \t" + iter->route + "\n");
                    QRect textRect = QRect(QPoint(0,0), text.size().toSize());
                    QRect imgRect =  QRect(QPoint(0,0), iter->img.size());

                    painter.translate(0,80);
                    nametext.drawContents(&painter,nametextRect);
                    painter.translate(200,nametextRect.height() + 10);
                    painter.drawPixmap(imgRect,iter->img,imgRect);
                    painter.translate(-200,imgRect.height()+10);
                    text.drawContents(&painter, textRect);


                    //sizePage = textRect.height() + (imgRect.height() + 10) + (nametextRect.height() + 10) + 80;
                    //qDebug() << "size_t :"<<sizePage;
                    printer.newPage();
                    painter.resetMatrix();
                    //очистка
                    //on_clearBtn_clicked()

            }

        QMessageBox::information(this,"Name Search:", "TravelGide.pdf create!!");
        close();

    }else{
        QMessageBox::information(this,"Save:", "пустоту не сохранишь!");
    }
}


//QPainter painter(this);
//painter.setPen(Qt::yellow);
//painter.drawText(0, 20, "One");
//painter.setPen(Qt::red);
//painter.drawText(QFontMetrics(painter.font()).size(Qt::TextSingleLine, "One ").width(), 20, "Two");

void FormListTravel::on_clearBtn_clicked()
{
    ui->imgSlot->clear();
    ui->nameEdit->clear();
    ui->routEdit->clear();
    ui->reportEdit->clear();
}

void FormListTravel::on_leftBtn_clicked()
{
    qDebug()<<"your position:" <<yorPos;
    if(listCart.length() != 0){
        if(yorPos != 0 && yorPos <= listCart.length() ){
            yorPos --;
            qDebug()<<" edit your position:" <<yorPos;
            ui->imgSlot->setPixmap(listCart[yorPos].img);
            imgSlot = listCart[yorPos].img;
            ui->nameEdit->setText(listCart[yorPos].name);
            ui->routEdit->setText(listCart[yorPos].route);
            ui->reportEdit->setText(listCart[yorPos].node);
        }
        if(yorPos > listCart.length()){
             yorPos --;
             qDebug()<<" edit your position:" <<yorPos;
        }
    }
}

void FormListTravel::on_rightBtn_clicked()
{
    qDebug()<<"your position:" <<yorPos;
    if(listCart.length() != 0){
        if(yorPos == listCart.length()  -1){
            yorPos ++;
            qDebug()<<" edit your position:" <<yorPos;
            ui->imgSlot->clear();
            ui->imgSlot->setText("Добавте картинку ");
            ui->nameEdit->clear();
            ui->routEdit->clear();
            ui->reportEdit->clear();
        }
        if(yorPos < listCart.length()-1){
            yorPos ++;
            qDebug()<<" edit your position:" <<yorPos;
            ui->imgSlot->setPixmap(listCart[yorPos].img);
            imgSlot = listCart[yorPos].img;
            ui->nameEdit->setText(listCart[yorPos].name);
            ui->routEdit->setText(listCart[yorPos].route);
            ui->reportEdit->setText(listCart[yorPos].node);
        }

    }
}
