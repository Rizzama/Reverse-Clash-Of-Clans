#include "game.h"
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QImage>

// To be refurbished

game::game() {

    // *******  Create the View ********
    setFixedSize(800,600);
    show();
    setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy (Qt::ScrollBarAlwaysOff);


    // ******* Create the Scene ********

    scene= new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/images/space_qt.jpg")));


    // *******  Create the Player ********

    Player * player = new Player ();
    player->setPixmap(QPixmap(":/images/jet_qt.png"));
    scene->addItem(player);



    // *******  Setting the focus to the Player ********

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********

    player->setPos(400,500);

    // *******   Assign scene to the view   ***************

    setScene(scene);

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);

    // ******** create the score and health **********
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

}
