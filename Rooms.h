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
};

void ItemEncounter(Player& player, Rooms& room);

char RoomChoice(char A, char B);

// ### List of rooms ##
void Cellar(Player& player); //First room
void Basement(Player& player);
void Foyer(Player& player);
void Library(Player& player);
void DiningHall(Player& player);
void Armory(Player& player);
void Courtyard(Player& player); //Last room