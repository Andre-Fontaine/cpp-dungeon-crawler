#pragma once
#include <string>
#include "Items.h"

class Player;
class Rooms
{
public:
	std::string name;
	std::string description;
	bool hasEnemy = false;
	bool hasItem = false;
	Items item;

	void ItemEncounter(Player& player)
	{
		if (hasItem)
		{
			TypeWriter("You find a weapon!", 30, true);
			TypeWriter(item.name + ": " + item.description, 30, false);
			// Logic to determine which item is found and add it to the player's inventory
		}
	}
};

char RoomChoice(char A, char B);

void Cellar(Player& player);

void Basement(Player& player);

void Foyer(Player& player);