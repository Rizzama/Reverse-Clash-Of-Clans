#include "cannonball.h"
#include <QKeyEvent>
#include <QTimer>
#include "game.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
#include <typeinfo>
#include <QtMultimedia>
#include <QMediaPLayer>
#include <QAudioOutput>

extern Game * game;

Cannonball::Cannonball(QGraphicsItem *parent, qreal dx, qreal dy)
    : QObject(), QGraphicsPixmapItem(parent), dx(dx), dy(dy) {
    QPixmap cannonBall(":/Sprites/228px-Cannon_Ball.png");
    QPixmap ball = cannonBall.scaled(cannonBall.width() / 2, cannonBall.height() / 2);
    setPixmap(ball);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(movebullet()));
    timer->start(50); // Adjust the bullet speed
}

/*
    run_output = new QAudioOutput(this); // Using 'this' as parent
    run_output->setVolume(50);
    run_sound = new QMediaPlayer(this); // Using 'this' as parent
    run_sound->setAudioOutput(run_output);
    run_sound->setSource(QUrl("qrc:/Sounds/Enemy Walk.mp3"));
*/

void Cannonball::movebullet() {
    // Move the bullet based on the stored movement directions
    setPos(x() + dx, y() + dy); // This happens one time, so it's gonna move 10 pixels, and never move again
    // I'm thinking it needs to be a loop until it reaches the wall.

    // Check for collisions with enemies
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // **** increase the score *****
            enemy_death_sound -> play();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // Delete the bullet if it goes out of the scene boundaries
        scene()->removeItem(this);
        delete this;

}
