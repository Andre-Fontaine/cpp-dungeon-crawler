#pragma once
#include <string>
using namespace std;

class Rooms
{
public:
	string name;
	string description;
	bool hasEnemy = false;
	bool hasItem = false;
};

char RoomChoice(char A, char B);

void Cellar();

void Basement();

void Foyer();