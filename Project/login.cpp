#include "login.h"
#include "ui_login.h"
#include <QDebug>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->code1->setEchoMode(QLineEdit::Password);
    this->setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint);
    //this->setFixedSize(430,330);//������һ���໥�滻������Ϊ���޷����
    this->move((QApplication::desktop()->width() - this->width())/2,
               (QApplication::desktop()->height() - this->height())/2);
    ui->name1->setFocus();
    // ���ر���ͼƬ
    QPixmap loginbk = QPixmap(":/imagefile/res/logintop.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(loginbk));
    this->setPalette(palette);
    //����ͷ��
    QPixmap ghead= QPixmap(":/imagefile/res/guest.jpg").scaled(80,80);
    ui->guestLabel->setPixmap(ghead);
    ui->guestLabel->show();
    //���ð�ť
    ui->loginbutton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;background-color:yellow");
    //    ui->loginbutton->setShortcut(Qt::Key_Enter);
}

login::~login()
{
    delete ui;
}

void login::judgeauto()
{
    QSqlQuery query;
    QString sql="create table if not exists jzmm(id varchar(50) primary key,password varchar(50),rem bool,auto bool)";
    query.exec(sql);
    sql="select * from jzmm";
    query.exec(sql);
    while(query.next())//ʵ�ֲ�ѯ
    {
        bool rem1=query.value(2).toBool();
        bool auto1=query.value(3).toBool();
        ui->cname1->addItem(query.value(0).toString());
        if(rem1)
            ui->remember->setCheckState(Qt::Checked);
        else
            ui->remember->setCheckState(Qt::Unchecked);
        if(auto1)
        {
            this->hide();
            QString name=query.value(0).toString();
            QString code=query.value(1).toString();
            ui->name1->setText(name);
            ui->code1->setText(code);
            ui->autologin->setCheckState(Qt::Checked);
            //�˴�ҲҪ�������������ݿ�����Ӳ���
            checkguest p(false,name,code);
            trans transmovie;
            transmovie.setAttribute(Qt::WA_DeleteOnClose);
            transmovie.show();
            QTime t;
            t.start();
            while(t.elapsed()<4000)
            {
                QApplication::processEvents();
            }
            int decide=p.getwhether();
            if(decide==1)
            {
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
                this->show();
                QMessageBox::warning(this,
                                     tr("����"),
                                     tr("���û�����"),
                                     QMessageBox::Ok);
                ui->name1->setFocus();
            }
        }
    }
}

void login::on_entrybutton_clicked()
{
    entry* e=new entry;
    this->close();
    e->setAttribute(Qt::WA_DeleteOnClose);
    e->show();
}

void login::on_loginbutton_clicked()
{
    int decide;
    QString name=ui->name1->text(),code=ui->code1->text();
    QString sname="\""+name+"\"",scode="\""+code+"\"";//���ڱ�ʾ������˫���ŵ��˺����룬���ڽ�����д�����ݿ�
    if(name!=""&&code!="")
    {
        this->hide();
        checkguest p(false,name,code);//������������Ƿ��û������Ӧ�����ϵ����ݿ�,֮���ٸ�
        trans transmovie;
        transmovie.setAttribute(Qt::WA_DeleteOnClose);
        transmovie.show();
        QTime t;
        t.start();
        while(t.elapsed()<4000)
        {
            QApplication::processEvents();
        }
        decide=p.getwhether();
        if( decide == 1 )
        {
            if(ui->remember->checkState()==Qt::Checked)
            {
                QSqlQuery query;
                QString sql="create table if not exists jzmm(id varchar(50) primary key,password varchar(50),rem bool,auto bool)";
                query.exec(sql);
                sql="select * from jzmm";
                query.exec(sql);
                while(query.next())//ʵ�ֲ�ѯ
                {
                    if(query.value(0).toString()==name)
                    {
                        sql=QString("delete from jzmm where id=%1;").arg(sname);
                        query.exec(sql);
                    }
                }
                if(ui->autologin->checkState()==Qt::Checked)
                {
                    sql=QString("insert into jzmm(id,password,rem,auto) values(%1,%2,1,1)").arg(sname).arg(scode);
                    query.exec(sql);
                }
                else if(ui->remember->checkState()==Qt::Checked)
                {
                    sql=QString("insert into jzmm(id,password,rem,auto) values(%1,%2,1,0)").arg(sname).arg(scode);
                    query.exec(sql);
                }
            }
            this->close();
            Roomchoser* roomchose= new Roomchoser;
            roomchose->setAttribute(Qt::WA_DeleteOnClose);
            player p(name);
            QObject::connect(&p,SIGNAL(nameSignal(QString)),roomchose,SLOT(readName(QString)));
            p.sendname();
            roomchose->show();
        }
        if(decide==0)
        {
            QMessageBox::warning(this,
                                 tr("����"),
                                 tr("�û�������"),
                                 QMessageBox::Ok);
            ui->name1->setFocus();
            this->show();
        }
        if(decide==2)
        {
            QMessageBox::warning(this,
                                 tr("����"),
                                 tr("���û�����"),
                                 QMessageBox::Ok);
            ui->name1->setFocus();
            this->show();
        }
        if(decide==3)
        {
            QMessageBox::warning(this,
                                 tr("����"),
                                 tr("�����������������"),
                                 QMessageBox::Ok);
            ui->name1->setFocus();
            this->show();
        }
        if(decide==4)
        {
            QMessageBox::warning(this,
                                 tr("����"),
                                 tr("���ݿ��쳣�����Ժ�����"),
                                 QMessageBox::Ok);
            ui->name1->setFocus();
            this->show();
        }
        if(decide>4||decide<0)
        {
            QMessageBox::warning(this,
                                 tr("����"),
                                 tr("�����쳣�����Ժ�����"),
                                 QMessageBox::Ok);
            //ui->name1->setFocus();
            this->show();
        }
    }
    else
    {
        QMessageBox::warning(this,
                             tr("����"),
                             tr("�������˺Ż�����"),
                             QMessageBox::Ok);
        ui->name1->setFocus();
    }
}


void login::on_cname1_currentIndexChanged(QString str)
{
    str=ui->cname1->currentText();
    ui->name1->setText(str);
    QSqlQuery query;
    QString sql="select * from jzmm";
    query.exec(sql);
    while(query.next())//ʵ�ֲ�ѯ
    {
        if(str==query.value(0).toString())
        {
            if(query.value(3).toBool()==true)
                ui->autologin->setCheckState(Qt::Checked);
            else
                ui->autologin->setCheckState(Qt::Unchecked);
            if(query.value(2).toBool()==true)
            {
                ui->code1->setText(query.value(1).toString());
                ui->remember->setCheckState(Qt::Checked);
            }
            else
            {
                ui->code1->setText("");
                ui->remember->setCheckState(Qt::Unchecked);
            }
            break;
        }
    }
}

void login::on_autologin_stateChanged(int)
{
    if(ui->autologin->checkState() == Qt::Checked)
        ui->remember->setCheckState(Qt::Checked);
}

void login::on_remember_stateChanged(int)
{
    if(ui->remember->checkState() != Qt::Checked )
        ui->autologin->setCheckState(Qt::Unchecked);
}
