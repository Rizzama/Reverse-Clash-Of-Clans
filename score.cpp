#include "Score.h"
#include <QFont>
#include <QTimer>
#include "health.h"

// Assuming that 'health' is a global variable accessible from this file


Score::Score(){
    // *********** initialize the score to 0 **********
    score = 0;

    // ********* display the text **********
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("Helvetica",16));
}

void Score::increase(){
    score = score + 20;
    setPlainText(QString("Score: ") + QString::number(score)); // Score increments by 20
    setDefaultTextColor(Qt::green);


    // Use QTimer to revert the color back to white after 500 milliseconds (adjust as needed)
    QTimer::singleShot(500, this, &Score::resetColor);
}

void Score::resetColor(){
    setDefaultTextColor(Qt::white);
}

int Score::getScore(){
    return score;
}
