#ifndef WINBOARD_H
#define WINBOARD_H

#include <QFrame>
#include <QPixmap>
#include <QDebug>

namespace Ui {
    class winboard;
}
class game;

class winboard : public QFrame
{
    Q_OBJECT
    friend class game;

public:
    explicit winboard(QWidget *parent = 0);
    ~winboard();

public slots:
    void slotbdinfoReceived();
private:
    Ui::winboard *ui;
    QString b_name[3];
    QString b_cgscore[3];
    int temp_winornot[3];
};

#endif // WINBOARD_H
