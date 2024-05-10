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

    qreal dx, dy; // To increment movement in whichever direction

public:
    Cannonball(QGraphicsItem *parent = nullptr, qreal dx = 0, qreal dy = 0);
public slots:
    void movebullet();
    void keyPressEvent(QKeyEvent *event);
};

#endif // CANNONBALL_H
