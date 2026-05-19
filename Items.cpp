#include "Items.h"
#include "Player.h"
using namespace std;

Items::Items() : name(""), description(""), damageBonus(0), healthBonus(0), type(ItemType::Weapon)
{
}

Items::Items(string name, string description, int damageBonus, int healthBonus, ItemType type)
    : name(name), description(description), damageBonus(damageBonus), healthBonus(healthBonus), type(type)
{
}

void Items::ChooseItem(Player& player)//Function to allow the player to choose whether or not to equip the item, providing a damage bonus if they do
{
    int totalDamage = player.baseDamage + damageBonus;
	char equipChoice;
    player.baseDamage += damageBonus;
	TypeWriter("Would you like to equip the " + name + "? (Y/N)", 30, true);
	cin >> equipChoice;
    if (equipChoice == 'Y' || equipChoice == 'y')
    {
		if (type == ItemType::Weapon)
		{
			player.baseDamage += damageBonus;
			damageBonus = player.maxDamage; // Update damageBonus to reflect the player's new total damage after equipping the weapon
			TypeWriter(player.name + " equips the " + name + " and gains " + std::to_string(damageBonus) + " bonus damage, totalling " + std::to_string(totalDamage) + " damage!", 30, true);
		}
		else if (type == ItemType::Armor)
		{
			player.health += healthBonus;
			TypeWriter(player.name + " equips the " + name + " and gains " + std::to_string(healthBonus) + " bonus health, totalling " + std::to_string(player.health) + " health!", 30, true);
			player.maxHealth += healthBonus; // Increase maxHealth by the health bonus provided by the armor
		}
    }
	else
    {
		player.baseDamage -= damageBonus; // Revert the damage bonus if the player chooses not to equip the item
		player.health -= healthBonus; // Revert the health bonus if the player chooses not to equip the item
		TypeWriter(player.name + " decides not to equip the " + name + ".", 30, true);
    }
}

//Weapons
Items Mace("Mace", "A solid iron headed club designed for one thing: delivering devastating, crushing blows that shields and armor can't stop.", 7, 0, ItemType::Weapon);
Items Axe("Axe", "A broad-headed war axe, its blade chipped and stained from battles long past. The weight of it feels wrong in your hands, unbalanced and brutal. Whatever it was used for before, it was not sport.", 6, 0, ItemType::Weapon);
Items Bow("Bow", "A longbow carved from dark wood, its string worn but intact. Someone maintained this weapon carefully, right up until they stopped.", 10, 0, ItemType::Weapon);

//Armor
Items LeatherArmor("Leather Armor", "Light armor made from toughened animal hide. It offers basic protection while allowing for mobility.", 0, 5, ItemType::Armor);
Items Chainmail("Chainmail", "Medium armor made from interlocking metal rings. It provides good protection against slashing attacks but can be heavy and cumbersome.", 0, 10, ItemType::Armor);
Items PlateArmor("Plate Armor", "Heavy armor made from large metal plates. It offers excellent protection against most attacks but is very heavy and can limit mobility.", 0, 15, ItemType::Armor);