#include "enemy.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QGraphicsItem>
#include "game.h"

Game::Game(QWidget *parent, const QString& playerName)
    : QGraphicsView(parent), scene(new QGraphicsScene(this)), playerName(playerName) { // Modified constructor

    if (parent){
        setFixedSize(parent->size()); // Set the size to match the parent widget's size
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        scene->setSceneRect(0, 0, parent->size().width(), parent->size().height()); // Set the scene size to match the view's size
        // Directly specify the dimensions of the background image as 1334 x 750
        QImage backgroundImage(":/Sprites/GameBackground.jpg");
        int backgroundImageWidth = 1334;
        int backgroundImageHeight = 750;

        scene->setBackgroundBrush(QBrush(backgroundImage.scaled(backgroundImageWidth, backgroundImageHeight))); // Scale the background image to fit the scene
        setScene(scene);
    }else{

        setFixedSize(800,600); // Set the size to match the parent widget's size
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        scene->setSceneRect(0, 0, 800, 600); // Set the scene size to match the view's size
        // Directly specify the dimensions of the background image as 1334 x 750
        QImage backgroundImage(":/Sprites/GameBackground.jpg");
        int backgroundImageWidth = 1334;
        int backgroundImageHeight = 750;

        scene->setBackgroundBrush(QBrush(backgroundImage.scaled(backgroundImageWidth, backgroundImageHeight))); // Scale the background image to fit the scene
        setScene(scene);
    }



    player = new Player(playerName); // Pass the playerName argument
    player->setPixmap(QPixmap(":/Sprites/Cannon21B.png"));
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    if (parent){
        player->setPos(parent->size().width() / 2, parent->size().height() / 2); // Center the player on the screen
    }else{
        player->setPos(400-100, 300-82); // Center the player on the screen
    }

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    timer->start(2000);

    health = new Health();
    health->setPos(health->x(), health->y() );
    scene->addItem(health);

    addWalls(); // Call the function to add walls
    addVillageHouse();
}

void Game::decreaseHealth(){
    health->decrease();
}

void Game::addWalls() {
    // Define dimensions for the walls
    int wallWidth = 100; // Adjust as needed
    int wallHeight = 20; // Adjust as needed

    // Calculate the coordinates for the walls
    int centerX = player->x(); // Get the center x-coordinate of the player
    int centerY = player->y(); // Get the center y-coordinate of the player
    int wallX = centerX - wallWidth / 2; // Calculate the x-coordinate for the wall
    int wallY = centerY - wallHeight / 2; // Calculate the y-coordinate for the wall

    // Create and add the connected walls around the player cannon
    QGraphicsPixmapItem *wall1 = new QGraphicsPixmapItem(QPixmap(":/Sprites/Full_Walls.png"));
    wall1->setPos(wallX - 85, wallY - 85); // Adjust the position to surround the player
    wall1->setScale(0.5); // Adjust the scale of the wall item if necessary
    scene->addItem(wall1);

    // Ensure the player/cannon is drawn on top of the walls
    player->setZValue(1); // Set the stacking order of the player/cannon
}

void Game::addVillageHouse() {
    // Define dimensions for the village house
    int villageWidth = 100; // Adjust as needed
    int villageHeight = 100; // Adjust as needed

    // Calculate the coordinates for the village house
    int centerX = player->x(); // Get the center x-coordinate of the player
    int centerY = player->y(); // Get the center y-coordinate of the player
    int villageX = centerX - villageWidth / 2; // Calculate the x-coordinate for the village house
    int villageY = centerY - villageHeight / 2; // Calculate the y-coordinate for the village house

    // Create and add the village house item to the scene
    QGraphicsPixmapItem *village1 = new QGraphicsPixmapItem(QPixmap(":/Sprites/VillageHouseA.png"));
    village1->setPos(villageX+140, villageY+80);
    village1->setScale(0.1); // Adjust the scale of the village item
    scene->addItem(village1);

    // Create and add the village house item to the scene
    QGraphicsPixmapItem *village2 = new QGraphicsPixmapItem(QPixmap(":/Sprites/Goblin_Hut_House.png"));
    village2->setPos(villageX+80, villageY+120);
    village2->setScale(0.8);
    scene->addItem(village2);
}


