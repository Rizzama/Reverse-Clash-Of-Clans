#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "health.h"

class Game : public QGraphicsView {
public:
    Game(QWidget *parent, const QString& playerName = "Player1"); // Modified constructor
    void spawnEnemy();
    void decreaseHealth();
    void addWalls();
private:
    QGraphicsScene *scene;
    Player *player;
    Health *health;
    QString playerName; // Added member variable to store the player's name
};

#endif // GAME_H
