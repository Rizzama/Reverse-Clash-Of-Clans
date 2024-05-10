#ifndef PLAYER_H
#define PLAYER_H

#include "clan.h"
#include "QString"
#include "qmediaplayer.h"
#include <QGraphicsPixmapItem>

class Player: public QObject, public QGraphicsPixmapItem {
private:
    static int id;
    QString name;
    int level;
    Clan* clan;
    QMediaPlayer * cannonball_sound;
    QAudioOutput * cannonball_output;

public:
    Player(QString name);
    int getId() const;
    void setName(const QString& name);
    QString getName() const;
    void setLevel(int level);
    int getLevel() const;
    void setClan(Clan* clan);
    Clan* getClan() const;
    void createEnemy();

public slots:
    void keyPressEvent(QKeyEvent *Event);
};

#endif // PLAYER_H
