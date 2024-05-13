#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPLayer>
#include <QAudioOutput>
#include "game.h"
#include "score.h"
#include "Player.h"

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Enemy(QGraphicsItem * parent=0);
    void playSpawnSound();

public slots:
    void move();
    void spawnEnemy();
    void increaseSpawnRate();

private:
    QMediaPlayer * run_sound;
    QAudioOutput * run_output;
    QMediaPlayer * attack_sound;
    QAudioOutput * attack_output;
    QMediaPlayer * spawn_sound;
    QAudioOutput * spawn_output;
    int spawning_area;
    QTimer * timer;
    Score *score;

};

#endif // ENEMY_H
