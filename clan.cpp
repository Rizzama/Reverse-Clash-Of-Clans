// clan.cpp

#include "clan.h"
#include "game.h" // Include for accessing the Game class
#include "Player.h" // Include for accessing the Player class
#include "ui_clan.h"

Clan::Clan(QWidget *parent, int ID, QString ClanName)
    : QMainWindow(parent), ui(new Ui::Clan), id(ID), clanName(ClanName) {
    ui->setupUi(this);
}

Clan::~Clan() {
    delete ui;
}

void Clan::setId(int NID) {
    id = NID;
}

int Clan::getID() {
    return id;
}

void Clan::setName(QString nClanName) {
    clanName = nClanName;
}

QString Clan::getName() {
    return clanName;
}
