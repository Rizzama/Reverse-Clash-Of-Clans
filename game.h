#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
class game
{
public:
    game();
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
};

#endif // GAME_H
