#include "village.h"
#include <iostream>

Village::Village() {
    vName = "";
    avgLevel = 0;
}

void Village::addBuildings(int id, const QString bName, int level){
    Building newBuilding(id, bName, level);
    myVillage.push_back(newBuilding);
}


bool operator==(const Building& lhs, const Building& rhs) {
    // Implement comparison logic based on Building attributes
    return lhs.getId() == rhs.getId() && lhs.getName() == rhs.getName() && lhs.getLevel() == rhs.getLevel();
}


bool Village::removeBuildings(Building removed){ // Gave me an error for undefined "==" operator. Fixed it and defined operator above.
    auto it = std::find(myVillage.begin(), myVillage.end(), removed);
    if (it != myVillage.end()){
        myVillage.erase(it);
        return true;
    }
    return false;
}

int Village::getAvgLevel(){
    int sum = 0;
    QVector<Building>::Iterator Iter;
    for (Iter = myVillage.begin(); Iter != myVillage.end(); Iter++) {
        sum += Iter->getLevel();
    }
    return sum/(myVillage.size());
}

void Village::getBuildings(){
    QVector<Building>::Iterator Iter;
    std::cout << "ID:\t\t Name:\t\t Level:" << std::endl;
    for (Iter = myVillage.begin(); Iter != myVillage.end(); Iter++) {
        std::cout << Iter->getId() << "\t" << Iter->getName().toStdString() << "\t" << Iter->getLevel() << std::endl;
    }
}
