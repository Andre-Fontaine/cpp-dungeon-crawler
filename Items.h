#pragma once
#include <string>
#include <iostream>
#include "Utils.h"

class Player;

class Items
{
public:
    std::string name;
    std::string description;
    int damageBonus;
    int healthBonus;

    Items();
    Items(std::string name, std::string description, int damageBonus, int healthBonus);
    void ChooseItem(Player& player);
};

extern Items Mace;
extern Items Axe;
extern Items Bow;