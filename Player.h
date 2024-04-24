#ifndef PLAYER_H
#define PLAYER_H

#include "clan.h"
#include "QString"
#include <QGraphicsPixmapItem>

class Player: public QObject, public QGraphicsPixmapItem {
private:
    static int id;
    QString name;
    int level;
    Clan* clan;

public:
    Player(QString name);
    int getId() const;
    void setName(const QString& name);
    QString getName() const;
    void setLevel(int level);
    int getLevel() const;
    void setClan(Clan* clan);
    Clan* getClan() const;
};

#endif // PLAYER_H
