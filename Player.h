#pragma once
#include <string>
#include <iostream>

class Player
{
public:
	std::string name;
	float health;
	float baseDamage;

	Player(std::string name, float health, float baseDamage);

	void TakeDamage(float damage) //Function to reduce health when taking damage
	{
		health -= damage;
		std::cout << name << " takes " << damage << " damage " << "and has " << health << " health left." << std::endl;
		if (health < 0)
		{
			health = 0;
			std::cout << name << " has been defeated!" << std::endl;
		}
	}
};

