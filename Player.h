#ifndef PLAYER_H
#define PLAYER_H

#include "clan.h"
#include "QString"

class Player{
private:
    int id;
    QString name;
    int level;
    Clan* clan;

public:
    Player(int id, const QString& name, int level);
    void setId(int id);
    int getId() const;
    void setName(const QString& name);
    QString getName() const;
    void setLevel(int level);
    int getLevel() const;
    void setClan(Clan* clan);
    Clan* getClan() const;
};

#endif // PLAYER_H
