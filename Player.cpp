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
    qreal bulletDx = 0;
    qreal bulletDy = 0;

    if (event->key() == Qt::Key_Left){
        QPixmap cannonLeft(":/Sprites/Cannon Left.png");
        cannonLeft = cannonLeft.scaled(cannonLeft.width() / 3, cannonLeft.height() / 3);
        this->setPixmap(cannonLeft);
        this->setPos(400 - cannonLeft.width() / 1.55, 300 - cannonLeft.height() / 1.5);
        bulletDx = -10;
    } else if (event->key() == Qt::Key_Right){
        QPixmap cannonRight(":/Sprites/Cannon Right.png");
        cannonRight = cannonRight.scaled(cannonRight.width() / 3.25, cannonRight.height() / 3.25);
        this->setPixmap(cannonRight);
        this->setPos(400 - cannonRight.width() / 1.55, 300 - cannonRight.height() / 1.55);
        bulletDx = 10;
    } else if (event->key() == Qt::Key_Down){
        QPixmap cannonDown(":/Sprites/Cannon Down.png");
        cannonDown = cannonDown.scaled(cannonDown.width() / 3.25,  cannonDown.height() / 3.25);
        this->setPixmap(cannonDown);
        this->setPos(400 - cannonDown.width() / 1.55, 300 - cannonDown.height() / 1.55);
        bulletDy = 10;
    } else if(event->key() == Qt::Key_Up){
        QPixmap cannonUp(":/Sprites/Cannon Up.png");
        cannonUp = cannonUp.scaled(cannonUp.width() / 3.25, cannonUp.height() / 3.25);
        this->setPixmap(cannonUp);
        this->setPos(400 - cannonUp.width() / 1.55, 300 - cannonUp.height() / 1.55);
        bulletDy = -10;
    }

    if (event->key() == Qt::Key_Space) {
        // Create a cannonball and add it to the scene
        Cannonball *bullet = new Cannonball(nullptr, bulletDx, bulletDy);
        bullet->setPos(x() + pixmap().width() / 2 - bullet->pixmap().width() / 2,
                       y() + pixmap().height() / 2 - bullet->pixmap().height() / 2);
        scene()->addItem(bullet);
        cannonball_sound->play();
        // Note: No need to call bullet->movebullet() here since it's already called in the Cannonball constructor
    }
}


//   this->setPixmap(cannonDefault);
//   this->setPos(400 - 100, 300 - 82);


void Player::createEnemy()
{ Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
