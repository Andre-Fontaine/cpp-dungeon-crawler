#include "Items.h"
#include "Player.h"
#include "Rooms.h"
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
	bool replacingWeapon = (type == ItemType::Weapon && player.weaponIsEquipped);
	bool replacingArmor = (type == ItemType::Armor && player.armorIsEquipped);

	if (replacingWeapon || replacingArmor)
	{
		TypeWriter("You already have an item equipped. Would you like to replace it with the " + name + "? (Y/N)", 30, true);
		char replaceChoice;
		cin >> replaceChoice;
		if (replaceChoice == 'Y' || replaceChoice == 'y')
		{
			if (replacingWeapon)
			{
				//Removes damage bonus from currently equipped weapon
				player.baseDamage -= player.equippedWeaponDamage;
				player.maxDamage -= player.equippedWeaponDamage; 

				//Add new weapon's damage bonus
				player.baseDamage += damageBonus; 
				player.maxDamage += damageBonus; 

				//Update equippedWeaponDamage to reflect the new weapon's damage bonus
				player.equippedWeaponDamage = damageBonus; 
				TypeWriter("You unequip your current item and equip the " + name + ", now having " + std::to_string(player.baseDamage) + " damage.", 30, true);
				return;
			}
			else if (replacingArmor)
			{
				//Removes health bonus from currently equipped armor
				player.health -= player.equippedArmorHealth;
				player.maxHealth -= player.equippedArmorHealth;

				//Add new armor's health bonus
				player.health += healthBonus;
				player.maxHealth += healthBonus;

				//Update equippedArmorHealth to reflect the new armor's health bonus
				player.equippedArmorHealth = healthBonus;
				TypeWriter("You unequip your current item and equip the " + name + ", now having " + std::to_string(player.health) + " health.", 30, true);
				return;
			}
		}
		else if (replaceChoice == 'N' || replaceChoice == 'n')
		{
			TypeWriter("You decide not to equip the " + name + " and keep your current item.", 30, true);
			return; // Exit the function early since the player chose not to equip the new item
		}
	}

	//Equip item if no item is currently equipped
		char equipChoice;
		TypeWriter("Would you like to equip the " + name + "? (Y/N)", 30, true);
		cin >> equipChoice;
		if (equipChoice == 'Y' || equipChoice == 'y')
		{
			if (type == ItemType::Weapon)
			{
				player.baseDamage += damageBonus;
				player.maxDamage += damageBonus; // Update damageBonus to reflect the player's new total damage after equipping the weapon
				player.weaponIsEquipped = true; // Set isEquipped to true to indicate that the item is now equipped
				player.equippedWeaponDamage = damageBonus;
				TypeWriter(player.name + " equips the " + name + " and gains " + std::to_string(damageBonus) + " bonus damage, totalling " + std::to_string(player.baseDamage) + " damage!", 30, true);
				Delay(1000);
			}
			else if (type == ItemType::Armor)
			{
				player.health += healthBonus;
				player.maxHealth += healthBonus; // Increase maxHealth by the health bonus provided by the armor
				player.armorIsEquipped = true; // Set isEquipped to true to indicate that the item is now equipped
				player.equippedArmorHealth = healthBonus;
				TypeWriter(player.name + " equips the " + name + " and gains " + std::to_string(healthBonus) + " bonus health, totalling " + std::to_string(player.health) + " health!", 30, true);
				Delay(1000);
			}
		}
		else if (equipChoice == 'N' || equipChoice == 'n')
		{
			TypeWriter(player.name + " decides not to equip the " + name + ".", 30, true);
			Delay(1000);
		}
	}

//Weapons
Items Mace("Mace", "A solid iron headed club designed for one thing: delivering devastating, crushing blows that shields and armor can't stop.", 7, 0, ItemType::Weapon);
Items Axe("Axe", "A broad-headed war axe, its blade chipped and stained from battles long past. The weight of it feels wrong in your hands, unbalanced and brutal. Whatever it was used for before, it was not sport.", 6, 0, ItemType::Weapon);
Items Bow("Bow", "A longbow carved from dark wood, its string worn but intact. Someone maintained this weapon carefully, right up until they stopped.", 10, 0, ItemType::Weapon);
Items Greatsword("Greatsword", "A massive two-handed sword, its blade blackened and etched with strange symbols. It hums with a dark energy that seems to resonate with the very air around it.", 12, 0, ItemType::Weapon);

//Armor
Items LeatherArmor("Leather Armor", "Light armor made from toughened animal hide. It offers basic protection while allowing for mobility.", 0, 5, ItemType::Armor);
Items Chainmail("Chainmail", "Medium armor made from interlocking metal rings. It provides good protection against slashing attacks but can be heavy and cumbersome.", 0, 10, ItemType::Armor);
Items PlateArmor("Plate Armor", "Heavy armor made from large metal plates. It offers excellent protection against most attacks but is very heavy and can limit mobility.", 0, 15, ItemType::Armor);