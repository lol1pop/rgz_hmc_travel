#ifndef FORMLISTTRAVEL_H
#define FORMLISTTRAVEL_H

#include <QWidget>
#include "entities.h"

namespace Ui {
class FormListTravel;
}

class FormListTravel : public QWidget
{
    Q_OBJECT

public:
    QList<Cart> listCart;
    Tur tur;
    QPixmap imgSlot;
    int lenghtList;
    int position;
    explicit FormListTravel(QWidget *parent = nullptr, Tur *ture = nullptr );
    ~FormListTravel();


private slots:
    void on_saveBatn_clicked();

    void on_addImg_clicked();

    void on_editBtn_clicked();

private:
    Ui::FormListTravel *ui;
};



#endif // FORMLISTTRAVEL_H
