#include "trans.h"
#include "ui_trans.h"

trans::trans(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trans)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->move((QApplication::desktop()->width() - this->width())/2,
               (QApplication::desktop()->height() - this->height())/2);
    QMovie* transpic=new QMovie(":/imagefile/res/tt.gif");
    ui->label->setMovie(transpic);
    transpic->start();
    ui->label->show();
}

trans::~trans()
{
    delete ui;
}

