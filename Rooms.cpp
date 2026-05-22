#include <iostream>
#include "Rooms.h"
#include "Items.h"
#include "Enemies.h"
#include "Player.h"
#include "source.h"
#include "Utils.h"
using namespace std;

//Function to get player input for room choices and validate it
char RoomChoice(char A, char B)
{
	char choice;
	do 
	{
		cin >> choice;
		if (choice != A && choice != B)
		{
			TypeWriter("Invalid choice. Please choose either A or B.", 30, true);
		}
	} while (choice != A && choice != B);
	return choice;
}

//Item encounter function that checks if the room has an item and allows the player to pick it up, providing a damage bonus
void ItemEncounter(Player& player, Rooms& room)
{
	if (room.hasItem)
	{
		TypeWriter("***You found an item!***", 50, true);
		if (room.item.type == ItemType::Weapon)
		{
			TypeWriter(room.item.name + ": " + room.item.description + " It provides a " + std::to_string(room.item.damageBonus) + " damage bonus.", 30, false);
		}
		else if (room.item.type == ItemType::Armor)
		{
			TypeWriter(room.item.name + ": " + room.item.description + " It provides a " + std::to_string(room.item.healthBonus) + " health bonus.", 30, false);
		}
		room.item.ChooseItem(player);
		room.hasItem = false;
		// Logic to determine which item is found and add it to the player's inventory
	}
}

//### ALL ROOMS AND ENCOUNTERS START HERE ###
void Cellar(Player& player)
{
	Rooms Cellar;
	Cellar.hasItem = true;
	Cellar.item = Bow;
	Cellar.name = "The Cellar";
	TypeWriter(Cellar.name, 60, true);
	Delay(2000);
	ItemEncounter(player, Cellar);
	Delay(1000);
	TypeWriter("Cold stone. Darkness. The smell of something rotting nearby. You sit up slowly, head pounding, with no memory of how you got here. You're in a cellar, abandoned by the looks of it. Dusty kegs line the walls, empty glasses and cleaning supplies are strewn across the floor. This place hasn't seen life in decades. As your eyes adjust to the darkness, two paths reveal themselves. Ahead, a worn wooden door sits slightly ajar, a faint sliver of light creeping through the gap. Behind you, a stone stairwell descends into complete darkness, the air rising from below carrying a chill that makes your skin crawl. You have no idea what lies beyond either path. But staying here isn't an option.", 30, true);
		std::cout << endl << "A: Approach the door" << endl
		<< "B: Descend the stairwell" << endl;

	char choice = (RoomChoice('A', 'B'));

	if (choice == 'A')
	{
		Foyer(player);
	}
	else if (choice == 'B')
	{
		Basement(player);
	}
}

void Foyer(Player& player)
{
	Rooms Foyer;
	Enemy Goblin("Goblin", 100, 20);
	Foyer.hasItem = true;
	Foyer.item = Mace;
	Foyer.name = "The Foyer";
	TypeWriter(Foyer.name, 60, true);
	Delay(2000);
	ItemEncounter(player, Foyer);
	Delay(1000);
	TypeWriter("You push the door open slowly, its hinges groaning in protest after years of neglect. Beyond it lies a foyer, grand in another life, now swallowed by decay. A chandelier hangs overhead, its crystals dulled by years of dust, swaying gently despite the absence of any breeze. Faded portraits line the walls, their subjects long dead, their painted eyes seeming to follow your every step. You are halfway across the room when you hear it. A low, guttural sound from the far corner. You freeze. Crouched in the shadows is a goblin, its yellow eyes locking onto yours the moment you stop moving. It bares its teeth in something between a grin and a snarl, a rusted blade clutched in its clawed hand. It has not attacked yet. But it will. You have a split second to decide.", 30, true);
	std::cout << endl
		<< "A: Stand your ground and fight." << endl
		<< "B: Back away slowly and run." << endl;

	char choice = (RoomChoice('A', 'B'));
	if (choice == 'A')
	{
		EncounterEnemy(player, Goblin);
	}
	else if (choice == 'B')
	{
		TypeWriter("You take one slow step back toward the door. Then another. The goblin tilts its head, watching. For a moment you think it might let you leave. Then it lunges.", 30, true);
		EncounterEnemy(player, Goblin);
	}
}

void Basement(Player& player)
{
	Rooms Basement;
	Enemy GiantRat("Giant Rat", 35, 30);
	Basement.name = "The Basement";
	Basement.hasItem = true;
	Basement.item = LeatherArmor;
	TypeWriter(Basement.name, 60, true);
	Delay(2000);
	ItemEncounter(player, Basement);
	Delay(1000);
	TypeWriter("The basement is cold and eerie. The air is thick with the smell of mold and decay. In the corner, you see a shadowy figure lurking. It seems to be a giant rat, its eyes glowing in the darkness. You can hear its low growls as it prepares to attack.", 30, true);
	std::cout << endl
		<< "A: Fight the Giant Rat" << endl
		<< "B: Try to sneak past it" << endl;

	char choice = (RoomChoice('A', 'B'));
	if (choice == 'A')
	{
		EncounterEnemy(player, GiantRat);
	}
	else if (choice == 'B')
	{
		TypeWriter("You attempt to sneak past the Giant Rat, but it quickly notices you and lunges at you with a wicked grin. You have no choice but to fight!", 30, true);
		EncounterEnemy(player, GiantRat);
	}
}