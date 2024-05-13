#include "Player.h"
#include <QKeyEvent>
#include "enemy.h"
#include "qgraphicsscene.h"
#include <QDebug>
#include "cannonball.h"
#include <QTimer>
#include "clan.h"

int Player::id = 0;

Player::Player(QString name)
{
    id++;
    this->name = name;
    this->level = 0;
    this->current_state = "";

    cannonball_output = new QAudioOutput(this);
    cannonball_output->setVolume(50);
    cannonball_sound = new QMediaPlayer(this);
    cannonball_sound->setAudioOutput(cannonball_output);
    cannonball_sound->setSource(QUrl("qrc:/Sounds/CannonFire.mp3"));

    QTimer * Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(createEnemy()));
    Timer->start(2000);
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

void Player::keyPressEvent(QKeyEvent *event) {
    QString cannonState;
    QPixmap cannonLeft(":/Sprites/Cannon Left.png");
    QPixmap cannonRight(":/Sprites/Cannon Right.png");
    QPixmap cannonDown(":/Sprites/Cannon Down.png");
    QPixmap cannonUp(":/Sprites/Cannon Up.png");
    QPixmap cannonUpRight (":/Sprites/Cannon_Up_Right.png");
    QPixmap cannonUpLeft (":/Sprites/Cannon_Up_Left.png");
    QPixmap cannonDownRight(":/Sprites/Cannon21B.png");
    QPixmap cannonDownLeft(":/Sprites/Cannon_Down_Left.png");

    if (event->key() == Qt::Key_4){
        cannonLeft = cannonLeft.scaled(cannonLeft.width() / 3, cannonLeft.height() / 3);
        this->setPixmap(cannonLeft);
        this->setPos(230.79,130.29);
        cannonState = "Left"; // Update cannonState to reflect left direction
        this->current_state = "Left";

        qDebug() << cannonState;
    } else if (event->key() == Qt::Key_6){
        cannonRight = cannonRight.scaled(cannonRight.width() / 3.25, cannonRight.height() / 3.25);
        this->setPixmap(cannonRight);
        this->setPos(241.29,141.29);
        cannonState = "Right"; // Update cannonState to reflect right direction
        this->current_state = "Right";
        qDebug() << cannonState;
    } else if (event->key() == Qt::Key_2){
        cannonDown = cannonDown.scaled(cannonDown.width() / 3.25,  cannonDown.height() / 3.25);
        this->setPixmap(cannonDown);
        this->setPos(241.29,141.29);
        cannonState = "Down"; // Update cannonState to reflect down direction
        this->current_state = "Down";
        qDebug() << cannonState;
    } else if(event->key() == Qt::Key_8){
        cannonUp = cannonUp.scaled(cannonUp.width() / 3.25, cannonUp.height() / 3.25);
        this->setPixmap(cannonUp);
        this->setPos(241.29,141.29);
        cannonState = "Up"; // Update cannonState to reflect up direction
        this->current_state = "Up";

        qDebug() << cannonState;
    }
    else if (event->key() == Qt::Key_9 ){
        cannonUpRight = cannonUpRight.scaled(cannonUpRight.width() / 6, cannonUpRight.height() / 6);
        this->setPixmap(cannonUpRight);
        this->setPos(291.29,191.29);
        cannonState = "Up Right"; // Update cannonState to reflect up direction
        this->current_state = "Up Right";

        qDebug() << cannonState;
    } else if (event->key() == Qt::Key_7){
        cannonUpLeft = cannonUpLeft.scaled(cannonUpLeft.width() / 6, cannonUpLeft.height() / 6);
        this->setPixmap(cannonUpLeft);
        this->setPos(291.29,191.29);
        cannonState = "Up Left"; // Update cannonState to reflect up direction
        this->current_state = "Up Left";

        qDebug() << cannonState;
    }
    else if (event->key() == Qt::Key_3){
        cannonUpRight = cannonDownRight.scaled(cannonDownRight.width() / 6, cannonDownRight.height() /6);
        this->setPixmap(cannonDownRight);
       this->setPos(400-100, 300-82);
        cannonState = "Down Right"; // Update cannonState to reflect up direction
        this->current_state = "Down Right";

        qDebug() << cannonState;
    }else if (event->key() == Qt::Key_1){
        cannonDownLeft = cannonDownLeft.scaled(cannonDownLeft.width() / 4.75, cannonDownLeft.height() / 4.75);
        this->setPixmap(cannonDownLeft);
          this->setPos(271.29,171.29);
        cannonState = "Down Left"; // Update cannonState to reflect up direction
        this->current_state = "Down Left";

        qDebug() << cannonState;
    } else{
        cannonState = this->current_state;
        qDebug() << this->pos();
        qDebug() << cannonState;
        Cannonball *bullet = new Cannonball(this->pos(), this, cannonState); // passes the cannon state to the bullet constructor
        cannonball_sound->play();
        // bullet->setPos(50,50);
        // scene()->addItem(bullet);


    }

}

//   this->setPixmap(cannonDefault);
//   this->setPos(400 - 100, 300 - 82);


void Player::createEnemy()
{ Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
 //   enemy->playSpawnSound();

}
void Player::createWall()
{ Clan* clan = new Clan();
    scene()->addItem(clan);
    this->setZValue(1); // Set the stacking order of the player/cannon
    //   enemy->playSpawnSound();
}

int Player::getTimes(){
    return times;
}
