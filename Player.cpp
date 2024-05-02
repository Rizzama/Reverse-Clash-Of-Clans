#include "Player.h"
#include <QKeyEvent>
#include "enemy.h"
#include "qgraphicsscene.h"

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

void Player::keyPressEvent(QKeyEvent *Event){
    if (Event->key() == Qt::Key_Left){

    }else if (Event->key() == Qt::Key_Right){

    }else if (Event->key() == Qt::Key_Down){

    }else if(Event->key() == Qt::Key_Up){

    }else if(Event->key() == Qt::Key_Space){

    }
}

void Player::createEnemy()
{ Enemy* enemy = new Enemy();
    scene()->addItem(enemy);

}
