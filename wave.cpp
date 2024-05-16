#include "wave.h"
#include "Player.h"
#include "qfont.h"

Wave::Wave(Player *player) {
    this->player = player;

    // ********* display the text **********
    setPlainText("Wave: " + QString::number(player->getTimes()));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

int Wave::getWave(){
    return player->getTimes();
}

void Wave::displayWave(){
    setPlainText("Wave: " + QString::number(player->getTimes()));
    setDefaultTextColor(Qt::white);
}
