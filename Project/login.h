#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMessageBox>
#include <QCheckBox>
#include <QComboBox>
#include <QDebug>
#include <QPixmap>
#include <QTime>
#include "entry.h"
#include "trans.h"
#include "player.h"
#include "checkguest.h"
#include "roomchoser.h"
#include "mysql.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    void judgeauto();
    ~login();

private slots:
    void on_entrybutton_clicked();

    void on_loginbutton_clicked();


    void on_autologin_stateChanged(int);

    void on_remember_stateChanged(int);


    void on_cname1_currentIndexChanged(QString );

private:
    Ui::login *ui;
};

#endif // LOGIN_H


