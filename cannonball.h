#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Cannonball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Cannonball();
public slots:
    void movebullet();
};

#endif // CANNONBALL_H
