#pragma comment(lib,"User32.lib")
#include "mainwindow.h"
#include <QApplication>
#include "database.h"
#include "imgwork.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Database db;
    db.initDataBase();
    db.createDataBase();
    /*(QString name,
       QString country,
       QString route,
       QString list_things,
       int lasting,
       QString trans,
       QString wether,
       QByteArray photo,
       QString link)*/
    QString list;
    list = R"({
           "list": [
               {
                   "одежда": [
                       {
                           "футболка": "not_put"
                       },
                       {
                           "шорты": "not_put"
                       },
                       {
                           "джинсы": "not_put"
                       },
                       {
                           "кепка": "not_put"
                       },
                       {
                           "купальник": "not_put"
                       }
                   ]
               },
               {
                   "обувь": [
                       {
                           "кроссовки": "not_put"
                       }
                   ]
               }
           ]
       }   )";
    db.createNodeAdventure("Вино и виноград","Абхазия","Новосибирск-Абхазия",list,14,"самолет","солнечно",ImgWork::setImg(ImgWork::loadImg("C:/Users/cplfa/Pictures/10424487.jpg",0,0)),"qweqwe");
    list = R"({
           "list": [
               {
                   "одежда": [
                       {
                           "футболка": "not_put"
                       },
                       {
                           "джинсы": "not_put"
                       },
                       {
                           "кофта": "not_put"
                       },
                       {
                           "шорты": "not_put"
                       }
                   ]
               },
               {
                   "обувь": [
                       {
                           "сандали": "not_put"
                       },
                       {
                           "кроссовки": "not_put"
                       }
                   ]
               }
           ]
       })";
    db.createNodeAdventure("Музыка и танцы","Аргентина","Новосибирск-Москва-Аргентина",list,10,"машина","ветренно",ImgWork::setImg(ImgWork::loadImg("C:/Users/cplfa/Pictures/FUuMd10EBls.jpg",0,0)),"arey");
    list = R"({
           "list": [
               {
                   "одежда": [
                       {
                           "пуховик": "not_put"
                       },
                       {
                           "джинсы": "put"
                       },
                       {
                           "колготки": "sale"
                       },
                       {
                           "кофта": "sale"
                       }
                   ]
               },
               {
                   "обувь": [
                       {
                           "валенки": "put"
                       },
                       {
                           "ботинки": "put"
                       }
                   ]
               }
           ]
       })";
    db.createNodeAdventure("Морепродукты и сухофрукты","Вьетнам","Иркутск-Вьетнам",list,8,"самолет-автобус","облачно", ImgWork::setImg(ImgWork::loadImg("C:/Users/cplfa/Pictures/s150102.jpg",0,0)),"arty");
   /*  db.createNodeAdventure("Вода и солнцу","Греция","Санкт-Петербург - Греция","sgj",16,"поезд","солнечно","sgjhf");
    db.createNodeAdventure("Солнце и песок","Египет","Томск-Египет","sgj",24,"самолет","дождь","dgjf");
    db.createNodeAdventure("Пицца и паста","Италия","Москва-Италия","sgj",6,"самолет-корабль","солнечно","sfgdh");
    db.createNodeAdventure("Кухня и шоппинг","Кипр","ОАЭ-Кипр","sjg",19,"самолет","облачно","ERTSAY");
    db.createNodeAdventure("Цирки и фестивали","Монако","Москва-Монако","sj",12,"машина-самолет-поезд;","гроза","");
    db.createNodeAdventure("Тюльпаны","Нидерланды","Улан-Удэ - Нидерланды","shjf",14,"самолет-поезд","град","FKJ");
    db.createNodeAdventure("Мажор тур","ОАЭ","Москва-ОАЭ","fggfgd",15,"самолет","туман","sgfh");
    db.createNodeAdventure("Замки","Польша,","Албания-Польша","ddhgskj",10,"машина","роса","vm,h");
    db.createNodeAdventure("Фрукты","Турция","Новосибирск-Турция","sdhf",8,"самолет","солнечно","SHTR");
    db.createNodeAdventure("Морепродукты","Тайланд","Владивосток-Тайланд","sghf",12,"машина-самолет","облачно","ikgufl");
    db.createNodeAdventure("Бонжур","Франция","Австрия-Франция","kj",11,"поезд-машина","смерч","lhk");
    db.createNodeAdventure("Мясо и пиво","Чехия","Москва-Чехия","fh",16,"самолет","сухие грозы","mzxh");*/





    MainWindow w;
    w.show();
    return a.exec();
}
