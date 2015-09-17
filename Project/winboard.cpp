#include "winboard.h"
#include "ui_winboard.h"

winboard::winboard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::winboard)
{
    ui->setupUi(this);
    QPixmap bkb = QPixmap(":/imagefile/res/CURmark.png").scaled(this->size());
    ui->bkg->setPixmap(bkb);
    ui->wintable->setStyleSheet(";;;background-color:transparent");
}

winboard::~winboard()
{
    delete ui;
}

void winboard::slotbdinfoReceived()
{
    for(int i=0;i<3;i++)
    {
        ui->wintable->setItem(i,0,new QTableWidgetItem(b_name[i]));
        ui->wintable->setItem(i,1,new QTableWidgetItem(b_cgscore[i]));
        if(temp_winornot[i]==1)ui->wintable->setItem(i,2,new QTableWidgetItem("Win"));
        else ui->wintable->setItem(i,2,new QTableWidgetItem("Lost"));
    }
}
