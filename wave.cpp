#include "wave.h"
#include "Player.h"
#include "qfont.h"

Wave::Wave(Player *player) {
    this->player = player;

    // ********* display the text **********
    setPlainText("Wave: " + QString::number(player->getTimes()));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Helvetica",16));
}
