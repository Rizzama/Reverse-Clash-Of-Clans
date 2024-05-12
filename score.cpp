#include "Score.h"
#include <QFont>

Score::Score(){
    // *********** initialize the score to 0 **********
    score = 0;

    // ********* display the text **********
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("Helvetica",16));
}

void Score::increase(){
    score = score +20;
    setPlainText(QString("Score: ") + QString::number(score)); //Score increments by 20
    setDefaultTextColor(Qt::green);
    setPlainText(QString("Score: ") + QString::number(score)); //Score increments by 20
    setDefaultTextColor(Qt::white);
}

int Score::getScore(){
    return score;
}
