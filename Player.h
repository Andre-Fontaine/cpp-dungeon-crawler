#pragma once
#include <string>
using namespace std;

class Player
{
public:
	string name;
	float health;
	float baseDamage;

	Player(string name, float health, float baseDamage);

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

