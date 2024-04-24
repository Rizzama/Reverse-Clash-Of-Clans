#include "enemy.h"
#include "game.h" // Include for accessing the Game class
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include <QList>
#include <typeinfo>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {
    // *******  Setting the size of the enemy ********
    setPixmap(QPixmap(":/Sprites/pngwing.com.png"));

    // *******  Setting the position of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // *******  Moving the enemies downwards automatically every 40 milliseconds ********
    // Enemy Walk.mp3 has the walk frequency of 7Hz or the period of every step is 1/7s
    QTimer * timer = new QTimer(this); // Using 'this' as parent
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(143);

    //********* Adding Run Sound Effect ***************
    run_output = new QAudioOutput(this); // Using 'this' as parent
    run_output->setVolume(50);
    run_sound = new QMediaPlayer(this); // Using 'this' as parent
    run_sound->setAudioOutput(run_output);
    run_sound->setSource(QUrl("qrc:/Sounds/Enemy Walk.mp3"));

    //********* Adding Attack Sound Effect ***************
    attack_output = new QAudioOutput(this); // Using 'this' as parent
    attack_output->setVolume(50);
    attack_sound = new QMediaPlayer(this); // Using 'this' as parent
    attack_sound->setAudioOutput(attack_output);
    attack_sound->setSource(QUrl("qrc:/Enemy_Grunt/Enemy_Attack_Demo.mpeg"));

    //********* Adding Spawn Sound Effect ***************
    spawn_output = new QAudioOutput(this); // Using 'this' as parent
    spawn_output->setVolume(50);
    spawn_sound = new QMediaPlayer(this); // Using 'this' as parent
    spawn_sound->setAudioOutput(spawn_output);
    spawn_sound->setSource(QUrl("qrc:/../../../../../Razma/Downloads/Enemy Troop Intro.mp3"));
}

void Enemy::move() {
    // Move the enemy downwards
    setPos(x(), y() + 10);

    // Check for collisions with scene boundaries
    if (pos().y() > scene()->height() || pos().x() < 0 || pos().x() > scene()->width()) {
        // Remove the enemy from the scene if it goes out of bounds
        scene()->removeItem(this);
        delete this;
        return;
    }

    // Move the enemy upwards
    setPos(x(), y() - 10);

    // Check for collisions with scene boundaries
    if (pos().y() < 0 || pos().x() < 0 || pos().x() > scene()->width()) {
        // Remove the enemy from the scene if it goes out of bounds
        scene()->removeItem(this);
        delete this;
        return;
    }

    // Move the enemy left
    setPos(x() - 10, y());

    // Check for collisions with scene boundaries
    if (pos().x() < 0 || pos().y() < 0 || pos().y() > scene()->height()) {
        // Remove the enemy from the scene if it goes out of bounds
        scene()->removeItem(this);
        delete this;
        return;
    }

    // Move the enemy right
    setPos(x() + 10, y());

    // Check for collisions with scene boundaries
    if (pos().x() > scene()->width() || pos().y() < 0 || pos().y() > scene()->height()) {
        // Remove the enemy from the scene if it goes out of bounds
        scene()->removeItem(this);
        delete this;
        return;
    }

    // Check for collisions with the clan
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            // Decrease health and play attack sound
            game->decreaseHealth();
            attack_sound->play();
            // Remove both enemies
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // Check for collisions with walls
    foreach (QGraphicsItem *item, colliding_items) {
        if (typeid(*item) == typeid(QGraphicsPixmapItem)) {
            // Collision with wall detected, decrease health
            game->decreaseHealth();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    // Play run sound
    run_sound->play();
}

void Enemy::playSpawnSound() {
    spawn_sound->play();
}
