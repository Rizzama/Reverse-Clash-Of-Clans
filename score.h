#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include "health.h"

class Score: public QGraphicsTextItem{
public:
    Score();
    void increase();
    int getScore();
    void resetColor();

private:
    int score;
    Health *health;
};

#endif // SCORE_H
