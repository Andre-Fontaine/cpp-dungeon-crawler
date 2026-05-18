#include "Items.h"
#include "Player.h"
using namespace std;

Items::Items() : name(""), description(""), damageBonus(0), healthBonus(0)
{
}

Items::Items(string name, string description, int damageBonus, int healthBonus)
    : name(name), description(description), damageBonus(damageBonus), healthBonus(healthBonus)
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
        TypeWriter(player.name + " equips the " + name + " and gains " + std::to_string(damageBonus) + " bonus damage, totalling " + std::to_string(totalDamage) + " damage!", 30, true);
    }
    else
    {
		player.baseDamage -= damageBonus; // Revert the damage bonus if the player chooses not to equip the item
		TypeWriter(player.name + " decides not to equip the " + name + ".", 30, true);
    }
}

//Weapons
Items Mace("Mace", "A solid iron headed club designed for one thing: delivering devastating, crushing blows that shields and armor can't stop.", 7, 0);
Items Axe("Axe", "A sharp blade.", 6, 0);
Items Bow("Bow", "A ranged weapon.", 10, 0);

//Armor
Items LeatherArmor("Leather Armor", "Light armor made from toughened animal hide. It offers basic protection while allowing for mobility.", 0, 5);
Items Chainmail("Chainmail", "Medium armor made from interlocking metal rings. It provides good protection against slashing attacks but can be heavy and cumbersome.", 0, 10);
Items PlateArmor("Plate Armor", "Heavy armor made from large metal plates. It offers excellent protection against most attacks but is very heavy and can limit mobility.", 0, 15);