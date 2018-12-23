#ifndef FORMCARDTRAVELER_H
#define FORMCARDTRAVELER_H

#include <QWidget>

namespace Ui {
class FormCardTraveler;
}

class FormCardTraveler : public QWidget
{
    Q_OBJECT

public:
    explicit FormCardTraveler(QWidget *parent = nullptr);
    ~FormCardTraveler();
    QPixmap photoSlot;
    QPixmap imgSlot;
    QPixmap img2Slot;
    void initStyle();

private slots:
    void on_addPhotoBtn_clicked();

    void on_addImgBtn_clicked();

    void on_addImgBtn_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::FormCardTraveler *ui;
};

#endif // FORMCARDTRAVELER_H
