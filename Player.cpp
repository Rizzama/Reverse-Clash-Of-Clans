#include "Player.h"

Player::Player(const QString& name, int level)
    {
        id++;
        this->name = name;
        this->level = level;
        this->clan = nullptr;
    }

    int Player::getId() const {
        return id;
    }

    void Player::setName(const QString& name)
    {
        this->name = name;
    }

    QString Player::getName() const
    {
        return name;
    }

    void Player::setLevel(int level)
    {
        this->level = level;
    }

    int Player::getLevel() const
    {
        return level;
    }

    void Player::setClan(Clan* clan)
    {
        this->clan = clan;
    }

    Clan* Player::getClan() const
    {
        return clan;
    }


