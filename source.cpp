#include <iostream>
#include "source.h"
using namespace std;

void GameStart()
{
	cout << "Welcome to Dungeon Crawler!" << endl;
	cout << "You will play as Andre, a lost soul waking up in an unknown dungeon." << endl;
	cout << "You won't know what lies ahead through this labyrinth. Find the means to survive." << endl << endl;
}
class Player
{
public:
	string name;
	float health;
	float baseDamage;

	Player()
	{
		health = 100;
		baseDamage = 5;
	}
	
	void TakeDamage(float damage) //Function to reduce health when taking damage
	{
		health -= damage;
		cout << name << " takes " << damage << " damage " << "and has " << health << " health left." << endl;
		if (health < 0)
		{
			health = 0;
			cout << name << " has been defeated!" << endl;
		}
	}
};

class Rooms
{
public:
	string name;
	string description;
	bool hasEnemy = false;
	bool hasItem = false;
	bool exitA = false;
};


class Enemy : public Player
{
public:
	Enemy()
	{

	}
};

class Items
{
public:
	string name;
	string description;
	float damageBonus;

	Items()
	{
		damageBonus = 0;
	}

	void UseItem(Player& player)
	{
		float totalDamage = player.baseDamage + damageBonus;
		player.baseDamage += damageBonus;
		cout << player.name << " picks up a " << name << " and gains " << damageBonus << " bonus damage, totalling " << totalDamage << " damage!" << endl;
	}
};

void EncounterEnemy(const Enemy& enemy)
{
	cout << endl 
		<< "You encountered: " << enemy.name << endl
		<< "Health: " << enemy.health << endl
		<< "Damage: " << enemy.baseDamage << endl
		<< endl;
}

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

void Cellar()
{
	Rooms Cellar;
	Cellar.name = "Cellar";
	cout << endl <<"The room is dark and damp. There's dusty kegs, cleaning supplies, and empty glasses everywhere. This place hasn't been occupied in what seems to be decades. Right ahead is a door into the foyer. Behind me is a stairwell going down to the basement. Which should I take?" << endl
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
		Enemy Goblin;
		Goblin.name = "Goblin";
		Goblin.health = 100;
		Goblin.baseDamage = 20;
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
}

int main()
{
	GameStart();
	Cellar();

	//Creating player character with stats
	Player Andre;
	Andre.name = "Andre";
	Andre.health = 100;
	Andre.baseDamage = 10;

	//Creating enemy Spider with stats
	Enemy Spider;
	Spider.name = "Spider";
	Spider.health = 50;
	Spider.baseDamage = 5;

	//Creating enemy Giant Rat with stats
	Enemy GiantRat;
	GiantRat.name = "Giant Rat";
	GiantRat.health = 75;
	GiantRat.baseDamage = 10;

	//Creating enemy Goblin with stats
	Enemy Goblin;
	Goblin.name = "Goblin";
	Goblin.health = 100;
	Goblin.baseDamage = 20;

	//Creating item Sword with stats
	Items Sword;
	Sword.name = "Sword";
	Sword.description = "A rusty sword that hasn't been used in ages.";
	Sword.damageBonus = 15;
}