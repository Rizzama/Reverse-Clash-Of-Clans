#include <QApplication>
#include "game.h"
#include <QDebug>

Game *game;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Pass the player's name as an argument
    game = new Game(nullptr, "Player1"); //For time constraints...hardcoded name to player1...
    game->show();


    return a.exec();
}
