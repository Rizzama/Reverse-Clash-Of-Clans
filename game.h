#ifndef GAME_H
#define GAME_H

#include "score.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "health.h"
#include <QPointF>

class Game : public QGraphicsView {
public:
    Game(QWidget *parent, const QString& playerName = "Player1"); // Modified constructor
    void spawnEnemy();
    void decreaseHealth();
    void addWalls();
    void addVillageHouse();
    QPointF getmaxPoint();
    void setScorePosition();
    void increaseScore();

private:
    QPointF maxPoint;
    QGraphicsScene *scene;
    Player *player;
    Health *health;
    QString playerName; // Added member variable to store the player's name
    Score *score  = new Score();
};

#endif // GAME_H
