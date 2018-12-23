#include "forminfo.h"
#include "ui_forminfo.h"

FormInfo::FormInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormInfo)
{
    ui->setupUi(this);
}

FormInfo::~FormInfo()
{
    delete ui;
}
