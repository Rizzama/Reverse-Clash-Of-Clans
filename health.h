#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QMediaPLayer>
#include <QAudioOutput>

class Health: public QGraphicsTextItem{
public:
    Health();
    void decrease();
    int getHealth();
    void dead();
    void gameover();
    void resetColor();
private:
    int health;
    QMediaPlayer * womp_womp_sound;
    QAudioOutput * womp_womp_output;
};

#endif // HEALTH_H
