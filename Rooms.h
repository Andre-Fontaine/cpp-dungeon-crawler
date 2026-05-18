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

void Cellar(Player& player);

void Basement(Player& player);

void Foyer(Player& player);