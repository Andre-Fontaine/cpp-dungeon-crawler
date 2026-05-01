#include <iostream>
#include "source.h"
using namespace std;

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

class Enemy : public Player
{
public:
	Enemy()
	{

	}
};

int main()
{
	//Creating player character with stats
	Player Andre;
	Andre.name = "Andre";
	Andre.health = 100;
	Andre.baseDamage = 10;

	//Creating enemy with stats
	Enemy Spider;
	Spider.name = "Spider";
	Spider.health = 50;
	Spider.baseDamage = 5;

	Andre.TakeDamage(Spider.baseDamage);
}