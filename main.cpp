#include "clan.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Clan w;
    w.show();
    return a.exec();
}
