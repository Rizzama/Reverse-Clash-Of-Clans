#include "cannonball.h"
#include <QKeyEvent>
#include <QTimer>
#include "game.h"
#include <QGraphicsScene>
#include <QList>
#include <enemy.h>
#include <player.h>
#include <typeinfo>

extern Game *game;

Cannonball::Cannonball(QGraphicsItem *parent, qreal dx, qreal dy)
    : QObject(), QGraphicsPixmapItem(parent), dx(dx), dy(dy) {
    QPixmap cannonBall(":/Sprites/228px-Cannon_Ball.png");
    QPixmap ball = cannonBall.scaled(cannonBall.width() / 5.5, cannonBall.height() / 5.5);
    setPixmap(ball);

    // Create invisible lines
    // QGraphicsLineItem *upLine = new QGraphicsLineItem(0, 0, 0, -100); // Example line
    // scene()->addItem(upLine);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(movebullet()));
    timer->start(50); // Adjust the bullet speed
    this->movebullet();
}

void Cannonball::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        dx = -10;
        dy = 0;
    } else if (event->key() == Qt::Key_Right) {
        dx = 10;
        dy = 0;
    } else if (event->key() == Qt::Key_Up) {
        dx = 0;
        dy = -10;
    } else if (event->key() == Qt::Key_Down) {
        dx = 0;
        dy = 10;
    }
    // This if condition is never called
    if(event->key() == Qt::Key_Space){
        this->movebullet();
    }
}

void Cannonball::movebullet() {

    // Move the bullet based on the stored movement directions
    this->setPos(x() + dx, y() + dy);

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
    if (!scene()->sceneRect().contains(pos())) {
        scene()->removeItem(this);
        delete this;
    }
}

