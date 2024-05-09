#include "Player.h"
#include <QKeyEvent>
#include "enemy.h"
#include "qgraphicsscene.h"
#include <QDebug>
#include "cannonball.h"

int Player::id = 0;

Player::Player(QString name)
    {
        id++;
        this->name = name;
        this->level = 0;
        this->clan = nullptr;
    }

int Player::getId() const {
    return id;
}

void Player::setName(const QString& name)
{
    this->name = name;
}

QString Player::getName() const
{
    return name;
}

void Player::setLevel(int level)
{
    this->level = level;
}

int Player::getLevel() const
{
    return level;
}

void Player::setClan(Clan* clan)
{
    this->clan = clan;
}

Clan* Player::getClan() const
{
    return clan;
}

//Change the cannon sprite based on key input. How???
void Player::keyPressEvent(QKeyEvent *Event){
    QPixmap cannonDefault(":/Sprites/Cannon21B.png"); // The dimensions of the image at the path is 100 x 82
    // We need to change the size of cannonDefault to match the original size.


    if (Event->key() == Qt::Key_Left){
        QPixmap cannonLeft(":/Sprites/Cannon Left.png");
//        cannonLeft = cannonLeft.scaled(cannonDefault.width(), cannonDefault.height());
        cannonLeft = cannonLeft.scaled(cannonLeft.width() / 3, cannonLeft.height() / 3);
        this->setPixmap(cannonLeft);
        this->setPos(400 - cannonLeft.width() / 1.55, 300 - cannonLeft.height() / 1.5); // Center the player on the screen
        // Don't ask, that's what worked
        if(Event->key() == Qt::Key_Space){
            Cannonball * buller = new Cannonball;
            buller->setPixmap(QPixmap(":/Sprites/228px-Cannon_Ball.png"));
            buller->setPos(400 - cannonLeft.width() / 1.55, 300 - cannonLeft.height() / 1.55);
            scene()->addItem(buller);
            buller->movebullet(Event);
        }
    }else if (Event->key() == Qt::Key_Right){
        QPixmap cannonRight(":/Sprites/Cannon Right.png");
        //cannonRight = cannonRight.scaled(cannonDefault.width(), cannonDefault.height());
        cannonRight = cannonRight.scaled(cannonRight.width() / 3.25, cannonRight.height() / 3.25);
        this->setPixmap(cannonRight);
        this->setPos(400 - cannonRight.width() / 1.55, 300 - cannonRight.height() / 1.55); // Center the player on the screen
        if(Event->key() == Qt::Key_Space){
            Cannonball * buller = new Cannonball;
            buller->setPixmap(QPixmap(":/Sprites/228px-Cannon_Ball.png"));
            buller->setPos(400 - cannonRight.width() / 1.55, 300 - cannonRight.height() / 1.55);
            scene()->addItem(buller);
            buller->movebullet(Event);
        }
    }else if (Event->key() == Qt::Key_Down){
        QPixmap cannonDown(":/Sprites/Cannon Down.png");
        //cannonDown = cannonDown.scaled(cannonDefault.width(), cannonDefault.height());
        cannonDown = cannonDown.scaled(cannonDown.width() / 3.25,  cannonDown.height() / 3.25);
        this->setPixmap(cannonDown);
        this->setPos(400 - cannonDown.width() / 1.55, 300 - cannonDown.height() / 1.55); // Center the player on the screen
        if(Event->key() == Qt::Key_Space){
            Cannonball * buller = new Cannonball;
            buller->setPixmap(QPixmap(":/Sprites/228px-Cannon_Ball.png"));
            buller->setPos(400 - cannonDown.width() / 1.55, 300 - cannonDown.height() / 1.55);
            scene()->addItem(buller);
            buller->movebullet(Event);
        }
    }else if(Event->key() == Qt::Key_Up){
        QPixmap cannonUp(":/Sprites/Cannon Up.png");
        //cannonUp = cannonUp.scaled(cannonDefault.width(), cannonDefault.height());
        cannonUp = cannonUp.scaled(cannonUp.width() / 3.25, cannonUp.height() / 3.25);
        this->setPixmap(cannonUp);
        this->setPos(400 - cannonUp.width() / 1.55, 300 - cannonUp.height() / 1.55); // Center the player on the screen
        if(Event->key() == Qt::Key_Space){
            Cannonball * buller = new Cannonball();
            buller->setPixmap(QPixmap(":/Sprites/228px-Cannon_Ball.png"));
            buller->setPos(400 - cannonUp.width() / 1.55, 300 - cannonUp.height() / 1.55);
            scene()->addItem(buller);
            buller->movebullet(Event);
        }
    }

//   this->setPixmap(cannonDefault);
//   this->setPos(400 - 100, 300 - 82);
}

void Player::createEnemy()
{ Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
