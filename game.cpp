#include "game.h"
#include "health.h"
#include "player.h"
#include "enemy.h"
#include <QTimer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)) {
    // Set the size of the view
    setFixedSize(800, 600);

    // Hide scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Set up the scene
    scene->setSceneRect(0, 0, 800, 600);
    scene->setBackgroundBrush(QBrush(QImage(":/Sprites/GameBackground.jpg")));
    setScene(scene);

    // Create the player
    Player *player = new Player();
    player->setPixmap(QPixmap(":/Sprites/228px-Cannon_Ball.png"));
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(400, 500);

    // Create the enemies automatically
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    timer->start(2000);

    // Create the score and health
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);
}

void Game::spawnEnemy() {
    // Create a new enemy
    Enemy *enemy = new Enemy();

    // Add the enemy to the scene
    scene->addItem(enemy);

    // Play the spawn sound effect
    enemy->playSpawnSound();
}
