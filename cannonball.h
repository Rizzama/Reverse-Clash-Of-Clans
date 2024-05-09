#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPLayer>
#include <QKeyEvent>

class Cannonball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
private:
    QMediaPlayer * enemy_death_sound;
    QAudioOutput * enemy_death_output;

public:
    Cannonball(QGraphicsItem *parent = 0);
public slots:
    void movebullet(QKeyEvent *Event);
};

#endif // CANNONBALL_H
