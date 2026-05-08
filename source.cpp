#include <iostream>
#include <string>
#include "source.h"
#include "Rooms.h"
#include "Enemies.h"
#include "Player.h"
#include "Items.h"
using namespace std;

//Start of game
void GameStart()
{
	cout << "Welcome to Dungeon Crawler!" << endl;
	cout << "You will play as Andre, a lost soul waking up in an unknown dungeon." << endl;
	cout << "You won't know what lies ahead through this labyrinth. Find the means to survive." << endl << endl;
}

int main()
{
	GameStart();
	Cellar();

	//Creating player character with stats
	Player Andre("Andre", 100, 10);

	//Creating item Sword with stats
	Items Sword("Sword", "A sharp blade that can be used to deal damage to enemies.", 5);
}