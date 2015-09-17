#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //������ʾ
    ui->setupUi(this);
    this->move((QApplication::desktop()->width() - this->width())/2,
               (QApplication::desktop()->height() - this->height())/100);
    //this->setModal(true);
    //�������ڴ�С
    this->resize( QSize( 900, 675 ));
    QPixmap background = QPixmap(":/imagefile/res/background.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(background));
    this->setPalette(palette);
//    //�Ʒְ�
//    QPixmap markboard = QPixmap(":/imagefile/res/Markboard.png").scaled(ui->Boardlabel->size());
//    ui->Boardlabel->setPixmap(markboard);

}

MainWindow::~MainWindow()
{
    delete ui;
}
