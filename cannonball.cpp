#include "cannonball.h"
#include <QKeyEvent>
#include <QTimer>
#include "game.h"
#include "score.h"
#include <QGraphicsScene>
#include <QList>
#include <enemy.h>
#include <player.h>
#include <typeinfo>

extern Game *game;

Cannonball::Cannonball(QPointF cannonPos, QGraphicsItem *parent, QString cannon_State) // passed by player.cpp
    : QObject(), QGraphicsPixmapItem(parent) {
    QPixmap cannonBall(":/Sprites/228px-Cannon_Ball.png");


    //*** Adding Enemy Death Sound Effect *****
    enemy_death_output = new QAudioOutput(this); // Using 'this' as parent
    enemy_death_output->setVolume(5);
    enemy_death_sound = new QMediaPlayer(this); // Using 'this' as parent
    enemy_death_sound->setAudioOutput(enemy_death_output);
    enemy_death_sound->setSource(QUrl("qrc:/Sounds/EnemyDeathCry.mp3"));

    qDebug() << cannonPos << " " << this->pos();
    cannonState = cannon_State; // Assigns local cannonState variable with the one passed by player.cpp

    qDebug() << cannonState << "from " << cannon_State;

    if (cannonState == "Up"){
        dy = -10;
        QPixmap ball = cannonBall.scaled(cannonBall.width() /5.5, cannonBall.height() /  5.5);
        setPixmap(ball);
        this->setPos(cannonPos.x() / 2.5, cannonPos.y() / 3.2);

    } else if (cannonState == "Down"){
        dy = 10;
        QPixmap ball = cannonBall.scaled(cannonBall.width() / 5.5, cannonBall.height() /  5.5);
        setPixmap(ball);
        this->setPos(cannonPos.x() / 2.5, cannonPos.y());

    } else if (cannonState == "Right"){
        dx = 10;
        QPixmap ball = cannonBall.scaled(cannonBall.width() / 5.5, cannonBall.height() / 5.5);
        setPixmap(ball);
        this->setPos(cannonPos.x()/2 , cannonPos.y()/ 1.5);
    } else if (cannonState == "Left"){
        dx = -10;
        QPixmap ball = cannonBall.scaled(cannonBall.width() / 5.5, cannonBall.height() /  5.5);
        setPixmap(ball);
        this->setPos(cannonPos.x() /3.5 , cannonPos.y() / 1.5);
    } else{ // When cannonState is "Firing"
        movebullet();
        QPixmap ball = cannonBall.scaled(cannonBall.width() / 5.5, cannonBall.height() /  5.5);
        setPixmap(ball);
        this->setPos(cannonPos.x() / 5.5, cannonPos.y() / 5.5);
    }
    // The uninitialised path of the bullet is down and right

    // Create invisible lines
    // QGraphicsLineItem *upLine = new QGraphicsLineItem(0, 0, 0, -100); // Example line
    // scene()->addItem(upLine);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(movebullet()));
    timer->start(100); // Adjust the bullet speed


}

void Cannonball::movebullet() {

    // Move the bullet based on the stored movement directions
    if (cannonState == "Up"){
        dy = -10;
    } else if (cannonState == "Down"){
        dy = 10;
    } else if (cannonState == "Right"){
        dx = 10;
    } else if (cannonState == "Left"){
        dx = -10;
    } else if (cannonState == "Down Right"){ // When cannonState is "Firing"
        dx+=5;
        dy+=5;
    } else if (cannonState == "Down Left") {
        dx-=5;
        dy+=5;
    } else if (cannonState == "Up Right"){ // When cannonState is "Firing"
        dx+=5;
        dy-=5;
    } else if (cannonState == "Up Left") {
        dx-=5;
        dy-=5;
    }


    this->setPos(x() + dx, y() + dy);
    qDebug() << "cannon state---" << cannonState;

    qDebug() << " move bullet--" << this->pos();

    // Check for collisions with enemies
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // enemy_death_sound -> play();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            game->increaseScore();
            enemy_death_sound->play();
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // Delete the bullet if it goes out of the scene boundaries
    if (pos().x() + 4.5 * 55.94 < 0 || pos().x() > game->getmaxPoint().x() ||
        pos().y() + 4.5 * 34.1531 < 0 || pos().y() > game->getmaxPoint().y()) {
        qDebug() << pos() << " " << game->getmaxPoint();
        scene()->removeItem(this);
        delete this;
    }

}
