#ifndef CLAN_H
#define CLAN_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPLayer>
#include <QAudioOutput>
class Clan: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Clan(QGraphicsItem *parent = 0);


public slots:

private:


};

#endif // CLAN_H
