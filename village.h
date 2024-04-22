#ifndef VILLAGE_H
#define VILLAGE_H

#include "building.h"
#include <QVector>

class Village
{
public:
    Village();
    void setVillage(Village village);
    void addBuildings(int id, const QString bName, int level);
    bool removeBuildings(Building removed);
    void getBuildings(); // Regular Display function
    int getAvgLevel();

private:
    QVector<Building> myVillage;
    QString vName;
    int avgLevel; // Level of the village is the average of all the building levels in the village itself
    // vector of class

};

#endif // VILLAGE_H
