#include "cannonball.h"
#include <QTimer>

Cannonball::Cannonball() {
    QGraphicsPixmapItem *bulletPic = new QGraphicsPixmapItem;
    QPixmap pic1 (":/Sprites/228px-Cannon_Ball.png");
    pic1 = pic1.scaledToHeight(30);
    pic1 = pic1.scaledToWidth(30);
    bulletPic->setPixmap(pic1);

    QTimer *Timer = new QTimer();
    connect(Timer, SIGNAL(timeout), this, SLOT(move()));

    Timer->start(50);
}

void Cannonball::movebullet(){
    setPos(x(), y() - 10);
}
