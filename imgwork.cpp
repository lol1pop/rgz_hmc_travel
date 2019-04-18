#include "imgwork.h"
#include <QBuffer>

ImgWork::ImgWork()
{

}

QPixmap ImgWork::loadImg(QString path, int hiath, int with)
{
    QPixmap img = QPixmap(path);
    if(hiath != 0 && with !=0){
        QSize PicSize(hiath, with);
        img = img.scaled(PicSize,Qt::KeepAspectRatio);
    }
    return img;
}

QPixmap ImgWork::loadImg(int hiath, int with)
{
    QString path = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.png *.jpg *.jpeg");
    qDebug() << "ImgWork::loadImg:: path img: " << path;
    QPixmap img = QPixmap(path);
    if(hiath != 0 && with !=0){
        QSize PicSize(hiath, with);
        img = img.scaled(PicSize,Qt::KeepAspectRatio);
    }
    return img;
}

QByteArray ImgWork::setImg(QPixmap img)
{
    if(!img.isNull()){
    QByteArray inByteArray;                             // Создаём объект QByteArray для сохранения изображения
    QBuffer inBuffer( &inByteArray );                   // Сохранение изображения производим через буффер
    inBuffer.open( QIODevice::WriteOnly );              // Открываем буффер
    img.save( &inBuffer, "png" );
    return inByteArray;
    }
    return nullptr;
}

void ImgWork::placeImgLable(QByteArray inByteArray, QLabel *label)
{
        QPixmap outPixmap = QPixmap();
        outPixmap.loadFromData(inByteArray);
        label->setScaledContents( true );
        label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        label->setPixmap(outPixmap);
}
