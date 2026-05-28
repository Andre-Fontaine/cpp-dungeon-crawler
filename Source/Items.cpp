#include <iostream>
#include "Items.h"
#include "Player.h"

using namespace std;

Items::Items()
    : name(""), description(""), damageBonus(0), healthBonus(0), type(ItemType::Weapon)
{
}

Items::Items(string name, string description, int damageBonus, int healthBonus, ItemType type)
    : name(name), description(description), damageBonus(damageBonus), healthBonus(healthBonus), type(type)
{
}

void Items::ChooseItem(Player& player)
{
    bool replacingWeapon = (type == ItemType::Weapon && player.weaponIsEquipped);
    bool replacingArmor  = (type == ItemType::Armor  && player.armorIsEquipped);

    // Player already has an item of this type equipped — ask if they want to replace it
    if (replacingWeapon || replacingArmor)
    {
        TypeWriter("You already have an item equipped. Would you like to replace it with the " + name + "? (Y/N)", 30, true);
        char replaceChoice;
        cin >> replaceChoice;
        replaceChoice = toupper(replaceChoice);

        if (replaceChoice == 'Y')
        {
            if (replacingWeapon)
            {
                player.baseDamage        -= player.equippedWeaponDamage;
                player.maxDamage         -= player.equippedWeaponDamage;
                player.baseDamage        += damageBonus;
                player.maxDamage         += damageBonus;
                player.equippedWeaponDamage = damageBonus;
                TypeWriter("You swap to the " + name + " and now deal " + to_string(player.baseDamage) + " damage.", 30, true);
            }
            else if (replacingArmor)
            {
                player.health            -= player.equippedArmorHealth;
                player.maxHealth         -= player.equippedArmorHealth;
                player.health            += healthBonus;
                player.maxHealth         += healthBonus;
                player.equippedArmorHealth = healthBonus;
                TypeWriter("You swap to the " + name + " and now have " + to_string(player.health) + " health.", 30, true);
            }
            Delay(1000);
            return;
        }
        else
        {
            TypeWriter("You decide to keep your current item.", 30, true);
            Delay(1000);
            return;
        }
    }

    // No item of this type equipped — ask if they want to equip it
    TypeWriter("Would you like to equip the " + name + "? (Y/N)", 30, true);
    char equipChoice;
    cin >> equipChoice;
    equipChoice = toupper(equipChoice);

    if (equipChoice == 'Y')
    {
        if (type == ItemType::Weapon)
        {
            player.baseDamage        += damageBonus;
            player.maxDamage         += damageBonus;
            player.weaponIsEquipped   = true;
            player.equippedWeaponDamage = damageBonus;
            TypeWriter(player.name + " equips the " + name + " and gains " + to_string(damageBonus) +
                       " bonus damage, totalling " + to_string(player.baseDamage) + " damage!", 30, true);
        }
        else if (type == ItemType::Armor)
        {
            player.health            += healthBonus;
            player.maxHealth         += healthBonus;
            player.armorIsEquipped    = true;
            player.equippedArmorHealth = healthBonus;
            TypeWriter(player.name + " equips the " + name + " and gains " + to_string(healthBonus) +
                       " bonus health, totalling " + to_string(player.health) + " health!", 30, true);
        }
    }
    else
    {
        TypeWriter(player.name + " decides not to equip the " + name + ".", 30, true);
    }

    Delay(1000);
}

// Weapons
Items Mace(
    "Mace",
    "A solid iron headed club designed for one thing: delivering devastating, crushing blows that shields and armor cannot stop.",
    7, 0, ItemType::Weapon);

Items Axe(
    "Axe",
    "A broad-headed war axe, its blade chipped and stained from battles long past. The weight of it feels wrong in your hands, unbalanced and brutal. Whatever it was used for before, it was not sport.",
    6, 0, ItemType::Weapon);

Items Bow(
    "Bow",
    "A longbow carved from dark wood, its string worn but intact. Someone maintained this weapon carefully, right up until they stopped.",
    10, 0, ItemType::Weapon);

Items Greatsword(
    "Greatsword",
    "A massive two-handed sword, its blade blackened and etched with strange symbols. It hums with a dark energy that seems to resonate with the very air around it.",
    12, 0, ItemType::Weapon);

// Armor
Items LeatherArmor(
    "Leather Armor",
    "Light armor made from toughened animal hide. It offers basic protection while allowing for mobility.",
    0, 5, ItemType::Armor);

Items Chainmail(
    "Chainmail",
    "Medium armor made from interlocking metal rings. It provides good protection against slashing attacks but can be heavy and cumbersome.",
    0, 10, ItemType::Armor);

Items PlateArmor(
    "Plate Armor",
    "Heavy armor made from large metal plates. It offers excellent protection against most attacks but is very heavy and can limit mobility.",
    0, 15, ItemType::Armor);
