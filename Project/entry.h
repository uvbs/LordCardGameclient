#ifndef ENTRY_H
#define ENTRY_H

#include <QWidget>
#include <QMessageBox>
#include "player.h"
#include "login.h"
#include "checkguest.h"

namespace Ui {
class entry;
}

class entry : public QWidget
{
    Q_OBJECT

public:
    explicit entry(QWidget *parent = 0);
    ~entry();

private slots:

    void on_sure_clicked();

    void on_cancel_clicked();

private:
    Ui::entry *ui;
};

#endif // ENTRY_H
