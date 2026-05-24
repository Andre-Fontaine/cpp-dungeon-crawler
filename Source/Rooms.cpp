#include <iostream>
#include "Rooms.h"
#include "Items.h"
#include "Enemies.h"
#include "Player.h"
#include "source.h"
#include "Utils.h"
#include "Battle.h"
using namespace std;

//Function to get player input for room choices and validate it
char RoomChoice(char A, char B)
{
	char choice;
	do 
	{
		cin >> choice;
		choice = toupper(choice);
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
	}
}

//### ALL ROOMS AND ENCOUNTERS START HERE ###
void Cellar(Player& player) //COMPLETED
{
	Rooms Cellar;
	Cellar.hasItem = false;
	Cellar.name = "---The Cellar---";
	TypeWriter(Cellar.name, 60, true);
	Delay(2000);
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

void Foyer(Player& player) //COMPLETED
{
	Rooms Foyer;
	Foyer.hasItem = true;
	Foyer.name = "---The Foyer---";
	Foyer.item = LeatherArmor;
	TypeWriter(Foyer.name, 60, true);
	Delay(2000);
	TypeWriter("You push the door open slowly, its hinges groaning in protest after years of neglect. Beyond it lies a foyer, grand in another life, now swallowed by decay. A chandelier hangs overhead, its crystals dulled by years of dust, swaying gently despite the absence of any breeze. Faded portraits line the walls, their subjects long dead, their painted eyes seeming to follow your every step. You are halfway across the room when you hear it. A low, guttural sound from the far corner. You freeze. Crouched in the shadows is a goblin, its yellow eyes locking onto yours the moment you stop moving. It bares its teeth in something between a grin and a snarl, a rusted blade clutched in its clawed hand. It has not attacked yet. But it will. You have a split second to decide.", 30, true);
	std::cout << endl
		<< "A: Stand your ground and fight." << endl
		<< "B: Back away slowly and run." << endl;

	char choice = (RoomChoice('A', 'B'));
	if (choice == 'A')
	{
		Enemy Goblin("Goblin", 25, 10);
		EncounterEnemy(player, Goblin, 20, 5);
		ItemEncounter(player, Foyer);
		TypeWriter("The goblin is dead. You stare at your hands for a moment longer than you should. You do not remember learning to fight. You do not remember much of anything. But your body knew what to do, and that terrifies you more than the goblin did. A door on the far wall sits slightly ajar. Beyond it lies a library, dark and still. You get the unsettling feeling it was waiting for you.", 30, true);
		Library(player);
	}
	else if (choice == 'B')
	{
		TypeWriter("You take one slow step back toward the door. Then another. The goblin tilts its head, watching. For a moment you think it might let you leave. Then it lunges.", 30, true);
		Enemy Goblin("Goblin", 25, 10);
		EncounterEnemy(player, Goblin, 20, 5);
		ItemEncounter(player, Foyer);
		TypeWriter("The goblin hits the floor. You do not feel victorious. You feel terrified. This was not the plan. The plan was to get out. You look back toward the stairwell and make a decision. The basement. Now. You are not ready for whatever else this place has waiting. You take the stairs two at a time and disappear into the darkness below before anything else finds you.", 30, true);
		Basement(player);
	}
}

void Basement(Player& player) //COMPLETED
{
	Rooms Basement;
	Basement.name = "---The Basement---";
	Basement.hasItem = false;
	TypeWriter(Basement.name, 60, true);
	Delay(2000);
	TypeWriter("There is nothing welcoming about this place and you knew that before you took the first step down. The cold settles in immediately, the kind that has nothing to do with temperature and everything to do with the feeling that something here is deeply wrong. You stand in the dark and wait for your eyes to adjust and think about all the better decisions you could have made tonight. Then something growls from the far corner, low and unhurried, like whatever it belongs to has nowhere else to be. Like it has been waiting. Like it is perfectly fine with waiting a little longer.", 30, true);
	std::cout << endl
		<< "A: Stand still and hope it doesn't see you" << endl
		<< "B: Slowly walk back up the stairs" << endl;

	char choice = (RoomChoice('A', 'B'));
	if (choice == 'A' || choice == 'a')
	{
		Enemy GiantRat("Giant Rat", 100, 10);
		TypeWriter("You do not move. You do not breathe. You stand in the dark and stare at the thing in the corner and tell yourself that if you are still enough, quiet enough, it will lose interest. For a moment it almost works. The growling stops. The eyes blink. Then it lunges and the basement explodes into chaos and you realise that standing still was never really an option.", 30, true);
		EncounterEnemy(player, GiantRat, 50, 10);
		TypeWriter("Silence returns to the basement. You stand there longer than you should, staring at nothing, breathing slowly. You told yourself staying still was a strategy. It was not. It was fear wearing the mask of a plan. You climb the stairs, back through the cellar, and push through into the foyer. You scan the walls and find a door on the far side, slightly ajar. Through the gap, shelves disappear into the dark. A library. You do not know what you are looking for. But something tells you this is where I need to go.", 30, true);
		Library(player);
	}
	else if (choice == 'B' || choice == 'b')
	{
		Enemy GiantRat("Giant Rat", 100, 10);
		TypeWriter("Slow. Steady. One step back, then another. You keep your eyes on it and it keeps its eyes on you. The stairs are right behind you. You can feel them. Five more steps and you are out of here. Three more. Two. Then your foot finds the first step and the rat decides it has been patient long enough. It crosses the room faster than anything that size has any right to and suddenly the stairs do not matter anymore.", 30, true);
		EncounterEnemy(player, GiantRat, 50, 10);
		TypeWriter("Your breathing is the loudest thing in the room now. You were two steps from the stairs when it caught you and somehow you are still standing. You take the stairs up, back through the cellar, and push into the foyer. On the far wall a door sits slightly ajar. Through the gap, shelves stretch into the darkness. A library. Whatever brought you here and left you with nothing but instinct, maybe the answers are in there.", 30, true);
		Library(player);
	}
}

void Library(Player& player)
{
	Rooms Library;
	Library.name = "---The Library---";
	Library.hasItem = true;
	Library.item = Axe;
	TypeWriter(Library.name, 60, true);
	Delay(2000);
	ItemEncounter(player, Library);
	Delay(1000);
	TypeWriter("The library is the first room that feels intentional. Everything else in this place has the look of abandonment, of things left behind without care. But the library is different. The shelves are tall and orderly, the books arranged with a precision that suggests someone spent a great deal of time in here. Dust covers everything but nothing is broken, nothing is overturned. Whoever maintained this room did so until the very end. A single reading chair sits in the center beneath a cracked skylight, pale light falling across an open book on the armrest as though someone set it down and meant to come back. On the shelves, two volumes have been pulled slightly forward from the rest, as though left deliberately. An invitation, or a warning. You are not sure there is a difference. You cross the room slowly, running your fingers along the spines, and stop at the two that have been left for you.", 30, true);
	std::cout << endl
		<< "A: Read the worn leather journal. Its pages filled with survival instincts, battle techniques, and hard won experience. (+ Damage, - Health" << endl
		<< "B: Read the old medical tome. Detailing anatomy, endurance, and the limits of the human body. (+ Health, - Damage)" << endl;
	
	char choice = (RoomChoice('A', 'B'));
	if (choice == 'A')
	{
		TypeWriter("The journal reads like a confession. Whoever wrote it had seen things, done things, and learned from every one of them. By the time you close it your hands feel steadier and your instincts feel sharper. But something else lingers too. A coldness. A reminder of what it costs to become capable of violence. You feel it in your chest, a dull ache that was not there before.", 30, true);
		player.maxHealth -= 10;
		player.health = player.maxHealth; // sync current health to new max
		player.baseDamage += 5;
		TypeWriter("You gain 5 bonus damage, totalling " + std::to_string(player.baseDamage) + ", but permanently lose 10 maximum health, totalling " + std::to_string(player.maxHealth) + ".", 90, true);
	}
	else if (choice == 'B')
	{
		TypeWriter("You open the medical tome and begin to read. The pages are filled with detailed information about the human body, its capabilities, and its limitations. It's a resource for understanding your own strength and endurance.", 30, true);
		player.maxHealth += 10;
		player.health = player.maxHealth; // sync current health to new max
		player.baseDamage -= 5;
		TypeWriter("You gain 10 maximum health, totalling " + std::to_string(player.maxHealth) + ", but permanently lose 5 damage, totalling " + std::to_string(player.baseDamage) + ".", 90, true);
	}
}