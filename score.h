#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score();
    void increase();
    int getScore();
    void resetColor();
private:
    int score;
};

#endif // SCORE_H
