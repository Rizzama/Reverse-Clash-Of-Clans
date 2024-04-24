#include "enemy.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QGraphicsItem>
#include "game.h"
#include "clan.h"

Game::Game(QWidget *parent, QString playerName): QGraphicsView(parent) { // Modified constructor
//  scene * = new QGraphicsScene(this);
    setFixedSize(parent->size()); // Set the size to match the parent widget's size
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    int backgroundImageWidth, backgroundImageHeight;
    QImage backgroundImage(":/Sprites/GameBackground.jpg");

    if (parent != nullptr){
        scene->setSceneRect(0, 0, parent->size().width(), parent->size().height()); // Set the scene size to match the view's size
        backgroundImage = backgroundImage.scaled(parent->size().width(), parent->size().height(), Qt::KeepAspectRatio);
        backgroundImageWidth = backgroundImage.width();
        backgroundImageHeight = backgroundImage.height();
    } else{
        scene->setSceneRect(0, 0, 800, 600);
        backgroundImage = backgroundImage.scaled(800, 600, Qt::KeepAspectRatio);
        backgroundImageWidth = backgroundImage.width();
        backgroundImageHeight = backgroundImage.height();
    }

    scene->setBackgroundBrush(QBrush(backgroundImage.scaled(backgroundImageWidth, backgroundImageHeight))); // Scale the background image to fit the scene
    setScene(scene);

    player = new Player(playerName); // Pass the playerName argument
    player->setPixmap(QPixmap(":/Sprites/Cannon21B.png"));
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(parent->size().width() / 2, parent->size().height() / 2); // Center the player on the screen

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    timer->start(2000);

    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    addWalls(); // Call the function to add walls
}

void Game::decreaseHealth(){
    health->decrease();
}

void Game::addWalls() {
    // Define dimensions for the walls
    int wallWidth = 100; // Adjust as needed
    int wallHeight = 20; // Adjust as needed

    // Calculate the coordinates for the walls
    int centerX = player->x();
    int centerY = player->y();
    int wallX = centerX - wallWidth / 2;
    int wallY = centerY - wallHeight / 2;

    // Create and add the connected walls around the player cannon
    QGraphicsPixmapItem *wall1 = new QGraphicsPixmapItem(QPixmap(":/Sprites/ConnectedWall.png"));
    wall1->setPos(wallX, wallY);
    scene->addItem(wall1);

    QGraphicsPixmapItem *wall2 = new QGraphicsPixmapItem(QPixmap(":/Sprites/ConnectedWall.png"));
    wall2->setPos(wallX + wallWidth * 3 / 2, wallY);
    scene->addItem(wall2);

    QGraphicsPixmapItem *wall3 = new QGraphicsPixmapItem(QPixmap(":/Sprites/ConnectedWall.png"));
    wall3->setPos(wallX, wallY + wallHeight * 3 / 2);
    scene->addItem(wall3);

    QGraphicsPixmapItem *wall4 = new QGraphicsPixmapItem(QPixmap(":/Sprites/ConnectedWall.png"));
    wall4->setPos(wallX + wallWidth * 3 / 2, wallY + wallHeight * 3 / 2);
    scene->addItem(wall4);

    // Create and add the "Wall2.jpg" walls between the connected walls
    QGraphicsPixmapItem *wall5 = new QGraphicsPixmapItem(QPixmap(":/Sprites/Wall2.jpg"));
    wall5->setPos(wallX + wallWidth, wallY);
    scene->addItem(wall5);

    QGraphicsPixmapItem *wall6 = new QGraphicsPixmapItem(QPixmap(":/Sprites/Wall2.jpg"));
    wall6->setPos(wallX + wallWidth * 3 / 2, wallY + wallHeight);
    scene->addItem(wall6);

    QGraphicsPixmapItem *wall7 = new QGraphicsPixmapItem(QPixmap(":/Sprites/Wall2.jpg"));
    wall7->setPos(wallX + wallWidth, wallY + wallHeight * 3 / 2);
    scene->addItem(wall7);

    QGraphicsPixmapItem *wall8 = new QGraphicsPixmapItem(QPixmap(":/Sprites/Wall2.jpg"));
    wall8->setPos(wallX, wallY + wallHeight);
    scene->addItem(wall8);
}

void Game::spawnEnemy() { // spawnEnemy(int numEnemies);
    // Win condition becomes "if (timer == 0 || numEnemies ==0){return Win;}"
    // if (numEnemies == 0 || timer == 0 && health >= 50){return Win;}
    // Create a new enemy
    Enemy *enemy = new Enemy();

    // Add the enemy to the scene
    scene->addItem(enemy);

    // Play the spawn sound effect
    enemy->playSpawnSound();
}
