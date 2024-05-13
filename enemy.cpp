 // Include for accessing the Game class
#include "enemy.h"
#include "clan.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <stdlib.h>
#include <QDebug>
#include <QList>
#include <typeinfo>

extern Game * game;
Score * score;
Player * player;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {
    // ***  Setting the position of the enemy within the view dimensions ****
    int enmy_x = rand() % 600, enmy_y = (rand() % 200)+400;

    spawning_area = (rand() % 4) + 1;

    if (spawning_area == 1){ //East
         enmy_x = 750, enmy_y = (rand() % 350)+130;
    }else if (spawning_area == 2){ //south
           enmy_x = (rand() % 350)+170, enmy_y = 550 ;
    }else if (spawning_area ==3){ //west
          enmy_x = 50, enmy_y = (rand() % 350)+130;
    }else if (spawning_area == 4){ // north
             enmy_x = (rand() % 350)+170, enmy_y = 50 ;
    }

    if(enmy_x <= 0 || enmy_x >= 800 || enmy_y <= 0 || enmy_y >= 600){


    }else if (enmy_x >= 100 && enmy_x <=400  ){


    }else{
        // ***  Setting the size of the enemy ****
        QPixmap enemy = QPixmap(":/Sprites/Enemy.png").scaled(QPixmap(":/Sprites/Enemy.png").width() / 26, QPixmap(":/Sprites/Enemy.png").height() / 30);
        setPixmap(enemy);
        this->setPos(enmy_x, enmy_y);
        // ***  Moving the enemies downwards automatically every 40 milliseconds ****
        // Enemy Walk.mp3 has the walk frequency of 7Hz or the period of every step is 1/7s
        timer = new QTimer(this); // Using 'this' as parent
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer->start(143);

        //*** Adding Run Sound Effect *****
        run_output = new QAudioOutput(this); // Using 'this' as parent
        run_output->setVolume(5);
        run_sound = new QMediaPlayer(this); // Using 'this' as parent
        run_sound->setAudioOutput(run_output);
        run_sound->setSource(QUrl("qrc:/Sounds/Enemy Walk.mp3"));

        //*** Adding Attack Sound Effect *****
        attack_output = new QAudioOutput(this); // Using 'this' as parent
        attack_output->setVolume(5);

        attack_sound = new QMediaPlayer(this); // Using 'this' as parent
        attack_sound->setAudioOutput(attack_output);
        attack_sound->setSource(QUrl("qrc:/Sounds/Enemy Walk.mp3"));

        //*** Adding Spawn Sound Effect *****
        spawn_output = new QAudioOutput(this); // Using 'this' as parent
        spawn_output->setVolume(5);
        spawn_sound = new QMediaPlayer(this); // Using 'this' as parent
        spawn_sound->setAudioOutput(spawn_output);
        spawn_sound->setSource(QUrl("qrc:/Enemy_Grunt/Enemy_Attack_Demo.mpeg"));


        // QTimer * Timer = new QTimer(this);
        // connect(Timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
        // Timer->start(2000);
        qDebug() << "Enemy spotted";
        playSpawnSound();
    }



}

void Enemy::move() {

    if (spawning_area == 1)
    {
      this->setPos(x() -5, y());
    }else if (spawning_area == 2){
      this->setPos(x(), y() -5);
    }
    else if (spawning_area == 3){
      this->setPos(x() +5, y());
    }
    else if (spawning_area == 4){
      this->setPos(x(), y() +5);
    }
    // Move the enemy downwards
   //setPos(x(), y() + 10);

    // Check for collisions with scene boundaries
    if (pos().y() > scene()->height() || pos().x() < 0 || pos().x() > scene()->width()) {
        // Remove the enemy from the scene if it goes out of bounds
        scene()->removeItem(this);
        delete this;
        return;
    }

    // Move the enemy upwards
  //  setPos(x(), y() - 10);

    // Check for collisions with scene boundaries
    if (pos().y() < 0 || pos().x() < 0 || pos().x() > scene()->width()) {
        // Remove the enemy from the scene if it goes out of bounds
        scene()->removeItem(this);
        delete this;
        return;
    }

    // Move the enemy left
  //  setPos(x() - 10, y());

    // Check for collisions with scene boundaries
    if (pos().x() < 0 || pos().y() < 0 || pos().y() > scene()->height()) {
        // Remove the enemy from the scene if it goes out of bounds
        scene()->removeItem(this);
        delete this;
        return;
    }

    // Move the enemy right
  //  setPos(x() + 10, y());

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
        if (typeid(*(colliding_items[i])) == typeid(Clan)) {
            // Decrease health and play attack sound
            game->decreaseHealth();
            attack_sound->play();

            // Remove both enemies
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete colliding_items[i];
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

void Enemy::spawnEnemy()
{
    scene()->addItem(this);
}

void Enemy::increaseSpawnRate(){
    if (score->getScore() % 100 == 0){
        timer->start(143 / player->getTimes());
    }
}
