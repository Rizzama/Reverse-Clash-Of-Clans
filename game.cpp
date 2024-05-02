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

