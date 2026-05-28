#pragma once
#include <string>
#include "Utils.h"

class Player;

enum class ItemType { Weapon, Armor };

class Items
{
public:
    std::string name;
    std::string description;
    int         damageBonus;
    int         healthBonus;
    ItemType    type;

    Items();
    Items(std::string name, std::string description, int damageBonus, int healthBonus, ItemType type);

    // Prompts the player to equip this item, applying the appropriate stat bonus.
    void ChooseItem(Player& player);
};

// Global item instances — defined in Items.cpp
extern Items Mace;
extern Items Axe;
extern Items Bow;
extern Items Greatsword;
extern Items LeatherArmor;
extern Items Chainmail;
extern Items PlateArmor;
