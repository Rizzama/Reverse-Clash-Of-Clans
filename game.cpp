#include "enemy.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QGraphicsItem>
#include "game.h"
#include "clan.h"

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

        //   setFixedSize); // Set the size to match the parent widget's size
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        scene->setSceneRect(0, 0, 500, 500); // Set the scene size to match the view's size
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
        player->setPos(100, 100); // Center the player on the screen
    }
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    timer->start(2000);

    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    addWalls(); // Call the function to add walls
}
