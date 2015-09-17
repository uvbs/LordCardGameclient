#ifndef TRANS_H
#define TRANS_H

#include <QDialog>
#include <QMovie>
#include <QTime>
#include "login.h"

namespace Ui {
class trans;
}

class trans : public QDialog
{
    Q_OBJECT

public:
    explicit trans(QWidget *parent = 0);
    ~trans();

private:
    Ui::trans *ui;
};

#endif // TRANS_H
