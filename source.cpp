#include <iostream>
#include <string>
#include "source.h"
#include "Rooms.h"
#include "Enemies.h"
#include "Player.h"
#include "Items.h"
using namespace std;

//Start of game
string GameStart()
{
	cout << "Welcome to Dungeon Crawler!" << endl;
	string playerName;
	cout << "What is your name?" << endl;
	getline(cin, playerName);
	cout << "You will play as " << playerName << ", a lost soul waking up in an unknown dungeon." << endl;
	cout << "You won't know what lies ahead through this labyrinth. Find the means to survive." << endl << endl;
	return playerName;
}

int main()
{
	string playerName = GameStart();
	Player player(playerName, 100, 10);
	Cellar(player);



	//Creating item Sword with stats
	Items Sword("Sword", "A sharp blade that can be used to deal damage to enemies.", 5);
}