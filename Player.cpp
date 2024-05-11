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

        cannonball_output = new QAudioOutput(this);
        cannonball_output->setVolume(50);
        cannonball_sound = new QMediaPlayer(this);
        cannonball_sound->setAudioOutput(cannonball_output);
        cannonball_sound->setSource(QUrl(":/Sounds/CannonFire.mp3"));
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

void Player::keyPressEvent(QKeyEvent *event) {
    QString cannonState;
    QPixmap cannonLeft(":/Sprites/Cannon Left.png");
    QPixmap cannonRight(":/Sprites/Cannon Right.png");
    QPixmap cannonDown(":/Sprites/Cannon Down.png");
    QPixmap cannonUp(":/Sprites/Cannon Up.png");

    if (event->key() == Qt::Key_Left){
        cannonLeft = cannonLeft.scaled(cannonLeft.width() / 3, cannonLeft.height() / 3);
        this->setPixmap(cannonLeft);
        this->setPos(230.79,130.29);
        cannonState = "Left"; // Update cannonState to reflect left direction
        qDebug() << cannonState;
    } else if (event->key() == Qt::Key_Right){
        cannonRight = cannonRight.scaled(cannonRight.width() / 3.25, cannonRight.height() / 3.25);
        this->setPixmap(cannonRight);
        this->setPos(241.29,141.29);
        cannonState = "Right"; // Update cannonState to reflect right direction
        qDebug() << cannonState;
    } else if (event->key() == Qt::Key_Down){
        cannonDown = cannonDown.scaled(cannonDown.width() / 3.25,  cannonDown.height() / 3.25);
        this->setPixmap(cannonDown);
        this->setPos(241.29,141.29);
        cannonState = "Down"; // Update cannonState to reflect down direction
        qDebug() << cannonState;
    } else if(event->key() == Qt::Key_Up){
        cannonUp = cannonUp.scaled(cannonUp.width() / 3.25, cannonUp.height() / 3.25);
        this->setPixmap(cannonUp);
        this->setPos(241.29,141.29);
        cannonState = "Up"; // Update cannonState to reflect up direction
        qDebug() << cannonState;
    } else{
        cannonState = "Firing";
        qDebug() << this->pos();
        qDebug() << cannonState;
        Cannonball *bullet = new Cannonball(this->pos(), this, cannonState); // passes the cannon state to the bullet constructor
        bullet->setPos(241.29,141.29);
        scene()->addItem(bullet);
        cannonball_sound->play();
    }

    qDebug() << cannonState;

}

//   this->setPixmap(cannonDefault);
//   this->setPos(400 - 100, 300 - 82);


void Player::createEnemy()
{ Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
