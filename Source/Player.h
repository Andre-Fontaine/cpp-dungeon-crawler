#pragma once
#include <string>
#include "Utils.h"
#include "Items.h"

class Player
{
public:
    std::string name;
    int         health;
    int         maxHealth;
    int         baseDamage;
    int         maxDamage;

    bool        weaponIsEquipped    = false;
    bool        armorIsEquipped     = false;
    int         equippedWeaponDamage = 0;
    int         equippedArmorHealth  = 0;

    Player(std::string name, int health, int baseDamage);

    // Reduces health by damage amount and prints the result.
    // Sets health to 0 if it would go negative.
    void TakeDamage(int damage);
};
