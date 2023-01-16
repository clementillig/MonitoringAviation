#include "placeholder.h"
#include "ui_placeholder.h"

PlaceHolder::PlaceHolder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlaceHolder)
{
    ui->setupUi(this);
}

PlaceHolder::~PlaceHolder()
{
    delete ui;
}
