#ifndef ENTITIES_H
#define ENTITIES_H

#include <QPixmap>
#include <QString>

class Cart {
public:
    QPixmap img;
    QString node;
    QString name;
    QString route;
    Cart(QPixmap nimg,
         QString nnode,
         QString nname,
         QString nroute){
         this->img = nimg;
         this->node = nnode;
         this->name = nname;
         this->route = nroute;
    }
};

class Tur {
public:
    QPixmap img;
    QString name;
    QString route;
};

#endif // ENTITIES_H
