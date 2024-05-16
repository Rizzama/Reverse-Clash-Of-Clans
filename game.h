#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "health.h"
#include <QPointF>
#include "score.h"
#include "wave.h"

class Game : public QGraphicsView {

public slots:
    void increaseHealth();

public:
    Game(QWidget *parent, const QString& playerName = "Player1"); // Modified constructor
    void spawnEnemy();
    void decreaseHealth();
    void increaseScore();
    void addVillageHouse();
    QPointF getmaxPoint();

private:
    QPointF maxPoint;
    Health *health;
    Score *score;
    Player *player;
    Wave *wave;
    QGraphicsScene *scene;
    QString playerName; // Added member variable to store the player's name
};

#endif // GAME_H
