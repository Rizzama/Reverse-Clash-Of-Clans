#ifndef WAVE_H
#define WAVE_H

#include <QGraphicsTextItem>
#include "Player.h"

class Wave : public QGraphicsTextItem {
public:
    Wave(Player *player);
    int getWave();

private:
    Player *player;
    int waveNumber;
};

#endif // WAVE_H
