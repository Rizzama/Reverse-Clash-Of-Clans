#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPLayer>
#include <QAudioOutput>
#include <QKeyEvent>

class Cannonball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
private:
    QMediaPlayer * enemy_death_sound;
    QAudioOutput * enemy_death_output;
    QString cannonState;
    qreal dx, dy; // To increment movement in whichever direction

public:
    Cannonball(QPointF cannonPos, QGraphicsItem *parent = nullptr, QString cannonState = "Up");
    // Instead of passing dx and dy, we pass a string detailing the state of the cannon and change the dx and dy in the constructor itself
public slots:
   void movebullet();
};

#endif // CANNONBALL_H
