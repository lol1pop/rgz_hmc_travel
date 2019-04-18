#pragma comment(lib,"User32.lib")
#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include "database.h"
#include "imgwork.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QFile file(":/style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());
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
//    QString list;
//    list = R"({"list":[{"одежда":[{"футболка":"not_put"},{"шорты":"not_put"},{"джинсы":"not_put"},{"кепка":"not_put"},{"купальник":"not_put"}]},{"обувь":[{"кроссовки":"not_put"}]}]})";
//    db.createNodeAdventure("Путешествие в историю","Испания","Мадрид-Барселона-Ибица",list,24,"самолет","солнечно",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Ispan.jpg",0,0)),"www");
//    list = R"({"list":[{"одежда":[{"футболка":"not_put"},{"джинсы":"not_put"},{"кофта":"not_put"},{"шорты":"not_put"}]},{"обувь":[{"сандали":"not_put"},{"кроссовки":"not_put"}]}]})";
//    db.createNodeAdventure("Неизведанный мир","Австралия","Канберра-Сидней-Мельбурн",list,10,"машина","ветренно",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Avstraljpg.jpg.jpg",0,0)),"www");
//    list = R"({"list":[{"одежда":[{"пуховик":"not_put"},{"джинсы":"put"},{"колготки":"sale"},{"кофта":"sale"}]},{"обувь":[{"валенки":"put"},{"ботинки":"put"}]}]})";
//    db.createNodeAdventure("Морепродукты и сухофрукты","Вьетнам","Иркутск-Вьетнам",list,8,"самолет-автобус","облачно", ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Philip.jpg",0,0)),"www");


    db.createNodeAdventure("Путешествие в историю","Испания","Мадрид-Барселона-Ибица",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Ispan.jpg",0,0)),R"({"list":[{"одежда":[{"футболка":"not_put"},{"шорты":"not_put"},{"джинсы":"not_put"},{"кепка":"not_put"},{"купальник":"not_put"}]},{"обувь":[{"кроссовки":"not_put"}]}]})",24,"самолет","солнечно","www");

    db.createNodeAdventure("Неизведанный мир","Австралия","Канберра-Сидней-Мельбурн",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Avstraljpg.jpg",0,0)),R"({"list":[{"одежда":[{"футболка":"not_put"},{"кофта":"not_put"},{"шорты":"not_put"},{"джинсы":"not_put"}]},{"обувь":[{"кроссовки":"not_put"},{"сандали":"not_put"}]}]})",18,"самолет","засуха","www");

    db.createNodeAdventure("Удивительная и суровая Швеция","Швеция","Стокгольм-Лапландия-Копенгаген",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Shvec.jpg",0,0)),R"({"list":[{"одежда":[{"пуховик":"not_put"},{"джинсы":"not_put"},{"колготки":"not_put"},{"кофта":"not_put"}]},{"обувь":[{"ботинки":"not_put"},{"валенки":"not_put"}]}]})",15,"поезд","снегопад","www");

    db.createNodeAdventure("Художественное наследие","Нидерланды","Амстердам-Роттердам",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Niderl.jpg",0,0)),R"({"list":[{"одежда":[{"куртка":"not_put"},{"джинсы":"not_put"},{"футболка":"not_put"},{"джемпер":"not_put"}]},{"обувь":[{"кроссовки":"not_put"},{"ботфорты":"not_put"}]}]})",18,"самолет","засуха","www");

    db.createNodeAdventure("Тур по Вьетнаму","Вьетнам","Ханой-Хошимин-Мельбурн",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Vietnam.jpg",0,0)),R"({"list":[{"одежда":[{"футболка":"not_put"},{"шорты":"not_put"},{"купальник":"not_put"},{"парео":"not_put"}]},{"обувь":[{"кроссовки":"not_put"},{"сандали":"not_put"}]}]})",12,"самолет","зной","www");

    db.createNodeAdventure("Белоснежный песок и голубые воды","ОАЭ","Абу-Даби-Дубай",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/OA.jpg",0,0)),R"({"list":[{"одежда":[{"футболка":"not_put"},{"бриджы":"not_put"},{"купальник":"not_put"},{"поло":"not_put"}]},{"обувь":[{"шлепки":"not_put"},{"сандали":"not_put"}]}]})",17,"лайнер","солнечно","www");

    db.createNodeAdventure("Жемчужина Атлантики","Канада","Монреаль-Квебек-Оттава",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Canada.jpg",0,0)),R"({"list":[{"одежда":[{"куртка":"not_put"},{"шапка":"not_put"},{"свитер":"not_put"},{"штаны":"not_put"}]},{"обувь":[{"ботинки для сноуборда":"not_put"},{"ботинки зимние":"not_put"}]}]})",14,"самолет","снегопад","www");

    db.createNodeAdventure("Дворцы Нового времени и замки Средних веков","Чехия","Прага-Карловы Вары-Либерец",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Cheh.jpg",0,0)),R"({"list":[{"одежда":[{"куртка":"not_put"},{"футболка":"not_put"},{"джинсы":"not_put"},{"свитер":"not_put"}]},{"обувь":[{"сапоги":"not_put"},{"кроссовки":"not_put"}]}]})",20,"поезд","пасмурно","www");

    db.createNodeAdventure("В тропический рай Тайланда","Тайланд","Бангкок-Пхукет",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Thai.jpg",0,0)),R"({"list":[{"одежда":[{"купальник":"not_put"},{"футболка":"not_put"},{"шорты":"not_put"},{"парео":"not_put"}]},{"обувь":[{"сандали":"not_put"},{"кроссовки":"not_put"}]}]})",15,"самолет","солнечно","www");

    db.createNodeAdventure("Современная арабская музыка и кинопродукция","Египет","Каир-Гиза-Александрия",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Egypt.jpg",0,0)),R"({"list":[{"одежда":[{"бриджы":"not_put"},{"поло":"not_put"},{"джинсы":"not_put"},{"джемпер":"not_put"}]},{"обувь":[{"сандали":"not_put"},{"кроссовки":"not_put"}]}]})",18,"самолет","сухо","www");

    db.createNodeAdventure("Религиозное наследие","Армения","Ереван-Арарат",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Armen.jpg",0,0)),R"({"list":[{"одежда":[{"кофта":"not_put"},{"штаны":"not_put"},{"джинсы":"not_put"},{"куртка":"not_put"}]},{"обувь":[{"ботинки":"not_put"},{"кроссовки":"not_put"}]}]})",17,"поезд","снегопад","www");

    db.createNodeAdventure("Погружение в красочную природу","Новая Зеландия","Веллингтон-Окленд-Гамильтон",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Zeland.jpg",0,0)),R"({"list":[{"одежда":[{"футболка":"not_put"},{"штаны":"not_put"},{"свитер":"not_put"},{"джемпер":"not_put"}]},{"обувь":[{"полуботинки":"not_put"},{"кроссовки":"not_put"}]}]})",21,"пароход","солнечно","www");

    db.createNodeAdventure("Маленькое королевство Свазиленд","Свазиленд","Мбабане-Манзини",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Svazilend.jpg",0,0)),R"({"list":[{"одежда":[{"костюм":"not_put"},{"рубашка":"not_put"},{"поло":"not_put"},{"джемпер":"not_put"}]},{"обувь":[{"ботинки":"not_put"},{"сабо":"not_put"}]}]})",15,"самолет","ясно","www");

    db.createNodeAdventure("Государство на семи тысячах островов","Филиппины","Боракай-Миндоро",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Philip.jpg",0,0)),R"({"list":[{"одежда":[{"футболка":"not_put"},{"шорты":"not_put"},{"платье":"not_put"},{"сарафан":"not_put"}]},{"обувь":[{"сандали":"not_put"},{"тапочки":"not_put"}]}]})",19,"самолет","пасмурно","www");

    db.createNodeAdventure("Цари гробниц","Эфиопия","Аддис-Абеба",ImgWork::setImg(ImgWork::loadImg(":/tur/res/foto/Efiop.jpg",0,0)),R"({"list":[{"одежда":[{"футболка":"not_put"},{"шорты":"not_put"},{"майка":"not_put"},{"штаны":"not_put"}]},{"обувь":[{"сандали":"not_put"},{"кроссовки":"not_put"}]}]})",14,"самолет","туман","www");


    MainWindow w;
    w.show();
    return a.exec();
}
