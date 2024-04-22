#include "building.h"

Building::Building(int id, const QString &name, int level) {
    this->id = id;
    this->name = name;
    this->level = level;
}

void Building::setId(int id){
    this->id = id;
}

int Building::getId() const{
    return id;
}

void Building::setName(const QString& name) {
    this->name = name;
}

QString Building::getName() const{
    return name;
}

void Building::setLevel(int level){
    this->level = level;
}

int Building::getLevel() const{
    return level;
}
