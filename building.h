#ifndef BUILDING_H
#define BUILDING_H

#include <QString>

class Building
{
private:
    int id;
    QString name;
    int level;
    // int buildingHealth

public:
    Building(int id = 0, const QString& name = "", int level = 0);

    void setId(int id);

    int getId() const;

    void setName(const QString& name);

    QString getName() const;

    void setLevel(int level);

    int getLevel() const;
};

#endif
