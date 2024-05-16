#ifndef PLAYER_H
#define PLAYER_H

#include "QString"
#include "qmediaplayer.h"
#include <QGraphicsPixmapItem>

class Player: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT;
private:
    static int id;
    QString name;
    int level;
    QMediaPlayer * cannonball_sound;
    QAudioOutput * cannonball_output;
    QString current_state;
    int times = 0;

public:
    Player(QString name);
    int getId() const;
    void setName(const QString& name);
    QString getName() const;
    void setLevel(int level);
    int getLevel() const;
    int getTimes();
    void setTimes();

public slots:
    void keyPressEvent(QKeyEvent *Event);
    void createEnemy();
    void createWall();
};

#endif // PLAYER_H
