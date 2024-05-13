#include "clan.h"
#include "game.h" // Include for accessing the Game class
#include "clan.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>
extern Game * game;

Clan::Clan(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    // Define dimensions for the walls
    int wallWidth = 100; // Adjust as needed
    int wallHeight = 20; // Adjust as needed

    // Calculate the coordinates for the walls
    int centerX = 310; // Get the center x-coordinate of the player
    int centerY = 195; // Get the center y-coordinate of the player
    int wallX = centerX - wallWidth / 2; // Calculate the x-coordinate for the wall
    int wallY = centerY - wallHeight / 2; // Calculate the y-coordinate for the wall

    // Create and add the connected walls around the player cannon
    QPixmap wall = QPixmap(":/Sprites/Full_Walls.png").scaled(QPixmap(":/Sprites/Full_Walls.png").width() / 2, QPixmap(":/Sprites/Full_Walls.png").height() / 2);

   // QPixmap *wall1 = new QGraphicsPixmapItem(QPixmap(":/Sprites/Full_Walls.png"));
    this->setPos(wallX - 85, wallY - 85); // Adjust the position to surround the player
   // wall1->setScale(0.5); // Adjust the scale of the wall item if necessary
    setPixmap(wall);

    // Ensure the player/cannon is drawn on top of the walls



}


