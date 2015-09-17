#include "entry.h"
#include "ui_entry.h"

entry::entry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::entry)
{
    ui->setupUi(this);
    ui->code11->setEchoMode(QLineEdit::Password);
    ui->code21->setEchoMode(QLineEdit::Password);
    this->setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint);
    //this->setFixedSize(430,330);//������һ���໥�滻������Ϊ���޷����
    ui->name1->setFocus();
    this->move((QApplication::desktop()->width() - this->width())/2,
               (QApplication::desktop()->height() - this->height())/2);
    QPixmap entrybk = QPixmap(":/imagefile/res/entrytop.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(entrybk));
    this->setPalette(palette);
}

entry::~entry()
{
    delete ui;
}

void entry::on_sure_clicked()
{
    bool bname,bcode1,bcode2;
    QString name=ui->name1->text();
    QString code1=ui->code11->text();
    QString code2=ui->code21->text();
    int all=-1;
    if(name==0)
    {
        QMessageBox::warning(this,
                             tr("����"),
                             tr("�û�������Ϊ��"),
                             QMessageBox::Ok);
        bname=false;
    }
    else
    {
        if( name.length()<3 || name.length()>10 )
        {
            QMessageBox::warning(this,
                                 tr("����"),
                                 tr("������3-10λ��Ƿ��ŵ��û���"),
                                 QMessageBox::Ok);
            bname=false;
        }
        else
            bname=true;
    }
    if( code1==0 )
    {
        QMessageBox::warning(this,
                             tr("����"),
                             tr("���벻��Ϊ��"),
                             QMessageBox::Ok);
        bcode1=false;
    }
    else
    {
        if( code1.length()<6 || code1.length()>15 )
        {
            QMessageBox::warning(this,
                                 tr("����"),
                                 tr("������6-15λ����"),
                                 QMessageBox::Ok);
            bcode1=false;
        }
        else
            bcode1=true;
    }
    if(code2==0&&bcode1)
    {
        QMessageBox::warning(this,
                             tr("����"),
                             tr("���ٴ���������"),
                             QMessageBox::Ok);
        bcode2=false;
    }
    else if( bcode1 )
    {
        if( code1 != code2 )
        {
            QMessageBox::warning(this,
                                 tr("����"),
                                 tr("�������벻һ�£�����������"),
                                 QMessageBox::Ok);
            bcode2=false;
        }
        else
            bcode2=true;
    }
    checkguest p(true,name,code1);//���Ƿ��û�����
    QTime t;
    t.start();
    while(t.elapsed()<500)
    {
        QApplication::processEvents();
    }//��Ҫ���ӳ�
    all=p.getwhether();
    if(all&&bname&&bcode1&&bcode2)
    {
        if(all==1||all==2||all==3)
        {
            QMessageBox::warning(this,
                                 tr("����"),
                                 tr("�û����Ѵ���"),
                                 QMessageBox::Ok);
            ui->name1->setText("");
            ui->code11->setText("");
            ui->code21->setText("");
        }
        if(all==4)
        {
            QMessageBox::warning(this,
                                 tr("����"),
                                 tr("���������ݿ��쳣"),
                                 QMessageBox::Ok);
        }
    }
    if(bname&&bcode1&&bcode2&&!all)
    {
        QMessageBox::information(NULL,tr("��ʾ"),tr("ע��ɹ�"),QMessageBox::Ok);
        QString sname="\""+name+"\"",scode="\""+code1+"\"";
        QSqlQuery query;
        QString sql=QString("insert into jzmm(id,password,rem,auto) values(%1,%2,0,0)").arg(sname).arg(scode);
        query.exec(sql);
        this->close();
        Roomchoser* roomchose= new Roomchoser;
        roomchose->setAttribute(Qt::WA_DeleteOnClose);
        player p(name);
        QObject::connect(&p,SIGNAL(nameSignal(QString)),roomchose,SLOT(readName(QString)));
        p.sendname();
        roomchose->show();
    }
    else
    {
        if(!bname)
        {
            ui->name1->setText("");
            ui->code11->setText("");
        }
        else if(!bcode1)
        {
            ui->code11->setText("");
        }
        if(all>4||all<0)
        {
            QMessageBox::warning(this,
                                 tr("����"),
                                 tr("�����������쳣"),
                                 QMessageBox::Ok);
        }
        else
            ui->code21->setText("");
    }
}

void entry::on_cancel_clicked()
{
    this->close();
    login* l=new login;
    l->setAttribute(Qt::WA_DeleteOnClose);
    l->show();
    l->judgeauto();
}
