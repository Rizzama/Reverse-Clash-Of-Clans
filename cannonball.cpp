#include "cannonball.h"
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

Cannonball::Cannonball(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent) {

    setPixmap(QPixmap(":/Sprites/228px-Cannon_Ball.png"));

    //****** Creating Enemy Death Sound Effect *********
    enemy_death_output = new QAudioOutput();
    enemy_death_output->setVolume(50);
    enemy_death_sound = new QMediaPlayer();
    enemy_death_sound->setAudioOutput(enemy_death_output);
    enemy_death_sound->setSource(QUrl(":/Sounds/barbarian-death-cry---clash-of-clans-made-with-Voicemod.mp3"));

    // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

// Move function is used to 1-  move the bullet upwards
// 2- Handle the collision of the bullets with enemies
void Cannonball::movebullet()
{
    // *******  Getting the colliding items with the Bullet ********
    // ******* Adding Sound effect for destroyed enemy *******

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



    // *******  Moving the bullets ********
// To be redone
    setPos(x(),y()-10);

    if(pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;

    }
}
