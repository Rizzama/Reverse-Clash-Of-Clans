#ifndef CLAN_H
#define CLAN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Clan;
}
QT_END_NAMESPACE

class Clan : public QMainWindow
{
    Q_OBJECT

public:
    Clan(QWidget *parent = nullptr, int ID = 0, QString clanName = "");
    ~Clan();
    void setId(int NID); // Sets the id of the clan
    int getID(); // Returns the id of the clan
    void setName(QString newName); // Changes the name of the clan
    QString getName(); // Returns the name of the clan
    // void addMember(Player member); // Adds a new player to the clan
    // void removeMember(Player member); // Removes the particular player from the clan
    // Player getMembers(); // Returns a list with the players' details
    // void setVillage(Village village); // Sets the current village to be like the parameters
    // Village getVillage(); // Returns the village details

private:
    Ui::Clan *ui;
    int id;
    QString clanName;
    // Village village();
};
#endif // CLAN_H
