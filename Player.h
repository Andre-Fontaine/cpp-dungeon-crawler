#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Utils.h"
#include "Items.h"


class Player
{
public:
	std::string name;
	float health;
	float baseDamage;
	std::vector<Items> inventory;
	Player(std::string name, float health, float baseDamage);

	void TakeDamage(float damage) //Function to reduce health when taking damage
	{
		health -= damage;
		TypeWriter(name + " takes " + std::to_string(damage) + " damage " + "and has " + std::to_string(health) + " health left.", 30, true);
		if (health < 0)
		{
			health = 0;
			TypeWriter(name + " has been defeated!", 30, true);
		}
	}
};

