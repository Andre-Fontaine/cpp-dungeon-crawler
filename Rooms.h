#pragma once
#include <string>
#include "Player.h"

class Rooms
{
public:
	std::string name;
	std::string description;
	bool hasEnemy = false;
	bool hasItem = false;
};

char RoomChoice(char A, char B);

void Cellar(Player& player);

void Basement(Player& player);

void Foyer(Player& player);