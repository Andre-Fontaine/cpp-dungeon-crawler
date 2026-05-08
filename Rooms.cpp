#include <iostream>
#include "Rooms.h"
#include "Enemies.h"

using namespace std;


//Function to get player input for room choices and validate it
char RoomChoice(char A, char B)
{
	char choice;
	cin >> choice;
	if (choice != A && choice != B)
	{
		cout << endl << "Invalid choice. Please choose either A or B." << endl;
	}
	return choice;
}
//Room functions to display room descriptions and choices for the player
void Cellar()
{
	Rooms Cellar;
	Cellar.name = "Cellar";
	cout << endl << "The room is dark and damp. There's dusty kegs, cleaning supplies, and empty glasses everywhere. This place hasn't been occupied in what seems to be decades. Right ahead is a door into the foyer. Behind me is a stairwell going down to the basement. Which should I take?" << endl
		<< "A: Door" << endl
		<< "B: Stairwell" << endl << endl;

	if (RoomChoice('A', 'B') == 'A')
	{
		Foyer();
	}
	else if (RoomChoice('A', 'B') == 'B')
	{
		Basement();
	}
}

void Foyer()
{
	Rooms Foyer;
	Foyer.name = "Foyer";
	cout << endl << "The foyer is dimly lit, with cobwebs hanging from the ceiling and a musty smell in the air. The walls are adorned with faded portraits of long-dead ancestors, their eyes seeming to follow you as you move. In the center of the room, a grand chandelier hangs precariously, its crystals clinking softly in the breeze. As you step further into the foyer, you notice a shadowy figure lurking in the corner. It appears to be a goblin, its eyes gleaming with malice as it prepares to attack." << endl
		<< "A: Fight the Goblin" << endl
		<< "B: Try to sneak past it" << endl << endl;

	if (RoomChoice('A', 'B') == 'A')
	{
		Enemy Goblin("Goblin", 100, 20);
		EncounterEnemy(Goblin);
	}
	else if (RoomChoice('A', 'B') == 'B')
	{
		cout << endl << "You attempt to sneak past the goblin, but it quickly notices you and lunges at you with a wicked grin. You have no choice but to fight!" << endl;
		Enemy Goblin("Goblin", 100, 20);
		EncounterEnemy(Goblin);
	}
}

void Basement()
{
	Rooms Basement;
	Basement.name = "Basement";
	cout << endl << "The basement is cold and eerie. The air is thick with the smell of mold and decay. In the corner, you see a shadowy figure lurking. It seems to be a giant rat, its eyes glowing in the darkness. You can hear its low growls as it prepares to attack." << endl
		<< "A: Fight the Giant Rat" << endl
		<< "B: Try to sneak past it" << endl;

	if (RoomChoice('A', 'B') == 'A')
	{
		Enemy GiantRat("Giant Rat", 100, 30);
		EncounterEnemy(GiantRat);
	}
	else if (RoomChoice('A', 'B') == 'B')
	{
		cout << endl << "You attempt to sneak past the Giant Rat, but it quickly notices you and lunges at you with a wicked grin. You have no choice but to fight!" << endl;
		Enemy GiantRat("Giant Rat", 100, 30);
		EncounterEnemy(GiantRat);
	}
}