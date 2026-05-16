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
    float damageBonus;

    Items();
    Items(std::string name, std::string description, float damageBonus);
    void ChooseItem(Player& player);
};