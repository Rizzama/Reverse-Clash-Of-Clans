#include "health.h"
#include "QtWidgets/qgraphicsscene.h"
#include <QFont>
#include <QMediaPLayer>
#include <QAudioOutput>

Health::Health(){
    // **** initialize the health to 3 ****
    health = 100;

    // **** draw the text *****
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
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
    health=health-10;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 90
    if (health == 0)
    {
        gameover();
    }
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
    gameover->setDefaultTextColor(Qt::red);
    gameover->setPlainText("Game Over");
    gameover->setPos (300, 250) ;

    scene()->addItem (gameover);
    womp_womp_sound ->play();
}
