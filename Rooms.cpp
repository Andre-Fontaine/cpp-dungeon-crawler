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
	cin >> choice;
	if (choice != A && choice != B)
	{
		TypeWriter("Invalid choice. Please choose either A or B.", 30, true);
	}
	return choice;
}

//Item encounter function that checks if the room has an item and allows the player to pick it up, providing a damage bonus
void ItemEncounter(Player& player, Rooms& room)
{
	if (room.hasItem)
	{
		TypeWriter("You find a weapon!", 30, true);
		TypeWriter(room.item.name + ": " + room.item.description + " It provides a " + std::to_string(room.item.damageBonus) + " damage bonus.", 30, false);
		room.item.ChooseItem(player);
		room.hasItem = false;
		// Logic to determine which item is found and add it to the player's inventory
	}
}

//Room functions to display room descriptions and choices for the player
void Cellar(Player& player)
{
	Rooms Cellar;
	Cellar.hasItem = false;
	Cellar.name = "The Cellar";
	TypeWriter(Cellar.name, 30, true);
	Delay(2000);
	//Item encounter
	TypeWriter("Cold stone. Darkness. The smell of something rotting nearby. You sit up slowly, head pounding, with no memory of how you got here. You're in a cellar, abandoned by the looks of it. Dusty kegs line the walls, empty glasses and cleaning supplies are strewn across the floor. This place hasn't seen life in decades. As your eyes adjust to the darkness, two paths reveal themselves. Ahead, a worn wooden door sits slightly ajar, a faint sliver of light creeping through the gap. Behind you, a stone stairwell descends into complete darkness, the air rising from below carrying a chill that makes your skin crawl. You have no idea what lies beyond either path. But staying here isn't an option.", 30, true);
		std::cout << endl << "A: Approach the door" << endl
		<< "B: Descend the stairwell" << endl;

	if (RoomChoice('A', 'B') == 'A')
	{
		Foyer(player);
	}
	else if (RoomChoice('A', 'B') == 'B')
	{
		Basement(player);
	}
}

void Foyer(Player& player)
{
	Rooms Foyer;
	Foyer.hasItem = true;
	Foyer.item = Mace;
	Foyer.name = "The Foyer";
	TypeWriter(Foyer.name, 30, true);
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
		Enemy Goblin("Goblin", 100, 20);
		EncounterEnemy(player, Goblin);
	}
	else if (choice == 'B')
	{
		TypeWriter("You take one slow step back toward the door. Then another. The goblin tilts its head, watching. For a moment you think it might let you leave. Then it lunges.", 30, true);
		Enemy Goblin("Goblin", 100, 20);
		EncounterEnemy(player, Goblin);
	}
}

void Basement(Player& player)
{
	Rooms Basement;
	Basement.name = "The Basement";
	TypeWriter(Basement.name, 30, true);
	Delay(2000);
	TypeWriter("The basement is cold and eerie. The air is thick with the smell of mold and decay. In the corner, you see a shadowy figure lurking. It seems to be a giant rat, its eyes glowing in the darkness. You can hear its low growls as it prepares to attack.", 30, true);
	std::cout << endl
		<< "A: Fight the Giant Rat" << endl
		<< "B: Try to sneak past it" << endl;

	char choice = (RoomChoice('A', 'B'));
	if (choice == 'A')
	{
		Enemy GiantRat("Giant Rat", 100, 30);
		EncounterEnemy(player, GiantRat);
	}
	else if (choice == 'B')
	{
		TypeWriter("You attempt to sneak past the Giant Rat, but it quickly notices you and lunges at you with a wicked grin. You have no choice but to fight!", 30, true);
		Enemy GiantRat("Giant Rat", 100, 30);
		EncounterEnemy(player, GiantRat);
	}
}