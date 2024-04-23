#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "health.h"

class Game: public QGraphicsView{
public:
    Game();

    QGraphicsScene * scene;
    Player * player;
    Health * health;

};

#endif // GAME_H
