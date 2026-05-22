#pragma once
#include <string>
#include <iostream>
#include "Utils.h"

class Player;

enum class ItemType { Weapon, Armor };

class Items
{
public:
    std::string name;
    std::string description;
    int damageBonus;
    int healthBonus;
    ItemType type;

    Items();
    Items(std::string name, std::string description, int damageBonus, int healthBonus, ItemType type);
    void ChooseItem(Player& player);
	void ReplaceItem(Player& player, Items& newItem);
};

extern Items Mace;
extern Items Axe;
extern Items Bow;
extern Items LeatherArmor;
extern Items Chainmail;
extern Items PlateArmor;