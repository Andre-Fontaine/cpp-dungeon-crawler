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
	bool hasEnemy;
	bool hasItem;
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
		int totalDamage = player.baseDamage + damageBonus;
		player.baseDamage += damageBonus;
		cout << player.name << " picks up a " << name << " and gains " << damageBonus << " bonus damage, totalling " << totalDamage << " damage!" << endl;
	}
};

void EnterRoom(const Rooms& rooms)
{
	cout << rooms.description << endl;
}

void EncounterEnemy(const Enemy& enemy)
{
	cout << endl 
		<< "You encountered: " << enemy.name << endl
		<< "Health: " << enemy.health << endl
		<< "Damage: " << enemy.baseDamage << endl
		<< endl;
}

int main()
{
	GameStart();

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

	//Creating a room with description and properties
	Rooms Cellar;
	Cellar.name = "Cellar";
	Cellar.description = "The room is dark and damp. There's dusty kegs, cleaning supplies, and empty glasses everywhere. This place hasn't been occupied in what seems to be decades. Right ahead is a door. Behind me is a stairwell going down. Which should I take?";
	Cellar.hasEnemy = false;
	Cellar.hasItem = false;

	//Simulating combat
	EnterRoom(Cellar);
	EncounterEnemy(Goblin);
		Sword.UseItem(Andre);
		cout << Andre.name << " attacks " << Goblin.name << " for " << Andre.baseDamage << " damage!" << endl;
		Goblin.TakeDamage(Andre.baseDamage);
}