#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //居中显示
    ui->setupUi(this);
    this->move((QApplication::desktop()->width() - this->width())/2,
               (QApplication::desktop()->height() - this->height())/100);
    //this->setModal(true);
    //背景窗口大小
    this->resize( QSize( 900, 675 ));
    QPixmap background = QPixmap(":/imagefile/res/background.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(background));
    this->setPalette(palette);
//    //计分板
//    QPixmap markboard = QPixmap(":/imagefile/res/Markboard.png").scaled(ui->Boardlabel->size());
//    ui->Boardlabel->setPixmap(markboard);

}

MainWindow::~MainWindow()
{
    delete ui;
}
