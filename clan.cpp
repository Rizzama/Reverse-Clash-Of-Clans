#include "clan.h"
#include "ui_clan.h"

Clan::Clan(QWidget *parent, int ID, QString ClanName)
    : QMainWindow(parent)
    , ui(new Ui::Clan)
{
    ui->setupUi(this);
    id = ID;
    clanName = ClanName;
}

Clan::~Clan()
{
    delete ui;
}

void Clan::setId(int NID){
    id = NID;
}

int Clan::getID(){
    return id;
}

void Clan::setName(QString nClanName){
    clanName = nClanName;
}

QString Clan::getName(){
    return clanName;
}

// Rest of the functions to be coded upon presence of the other classes
