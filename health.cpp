#include "QtWidgets/qgraphicsscene.h"
#include <QFont>
#include <QMediaPLayer>
#include <QAudioOutput>
#include <QTimer>
#include "health.h"

Health::Health(){
    // **** initialize the health to 3 ****
    health = 100;
    maxHealth = 100;

    // **** draw the text *****
    setPlainText(QString("Health: ") + QString::number(health) + QString("/") + QString::number(maxHealth)); // Health: 3
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));

    // ****** Game Over Sound effect *********
    //********* Adding Damage Sound Effect ***************
    womp_womp_output = new QAudioOutput();
    womp_womp_output->setVolume(50);
    womp_womp_sound = new QMediaPlayer();
    womp_womp_sound->setAudioOutput(womp_womp_output);
    womp_womp_sound->setSource(QUrl("qrc:/Sounds/Game Over sound effect.mp3"));
}

// ***** set health to current health after decrement ****
void Health::decrease()
{
    health = health - 5;
   setPlainText(QString("Health: ") + QString::number(health) + QString("/") + QString::number(maxHealth)); // Health: 90
    setDefaultTextColor(Qt::red);

    // Use QTimer to revert the color back to white after 500 milliseconds (adjust as needed)
    QTimer::singleShot(500, this, &Health::resetColor);

    if (health <= 0)
    {
        gameover();
    }
}

void Health::resetColor()
{
    setDefaultTextColor(Qt::white);
}

int Health::getHealth()
{
    return health;
}

void Health::gameover()
{
    for (size_t i = 0, n = scene()->items().size(); i < n; i++){
        scene()->items()[i]->setEnabled(false);
    }
    QGraphicsTextItem *gameover = new QGraphicsTextItem;
    gameover->setFont (QFont ("times", 40)) ;
    gameover->setDefaultTextColor(Qt::black);
    gameover->setPlainText("Game Over");
    gameover->setPos (300, 300) ;

    scene()->addItem (gameover);
    womp_womp_sound ->play();
    health = 0;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Health::maxHealthIncrease(){
    maxHealth = maxHealth + 20;
    health = maxHealth;
    setPlainText(QString("Health: ") + QString::number(health) + QString("/") + QString::number(maxHealth));
}




