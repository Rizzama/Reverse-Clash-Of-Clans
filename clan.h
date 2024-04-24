#ifndef CLAN_H
#define CLAN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
// clan.h

#include <QMainWindow>
#include <QString>

namespace Ui {
class Clan;
}

class Clan : public QMainWindow {
    Q_OBJECT

public:
    Clan(QWidget *parent = nullptr, int ID = 0, QString clanName = "");
    ~Clan();
    void setId(int NID);
    int getID();
    void setName(QString newName);
    QString getName();

private:
    Ui::Clan *ui;
    int id;
    QString clanName;
};

#endif // CLAN_H
