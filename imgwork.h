#ifndef IMGWORK_H
#define IMGWORK_H

#include <QObject>
#include <QDebug>
#include <QPixmap>
#include <QFileDialog>
#include <QAbstractItemModel>
#include <QLabel>


class ImgWork: public QObject
{
    Q_OBJECT
public:
    ImgWork();
    static QPixmap loadImg(QString, int, int);
    static QPixmap loadImg(int, int);
    static QPixmap loadImg(QString);
    static QByteArray setImg(QPixmap);
    static void placeImgLable(QByteArray, QLabel*);

};

#endif // IMGWORK_H
