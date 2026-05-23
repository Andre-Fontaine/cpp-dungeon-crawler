#include <iostream>
#include <string>
#include "source.h"
#include "Rooms.h"
#include "Enemies.h"
#include "Player.h"
#include "Items.h"
#include "Utils.h"
using namespace std;



//Start of game
string GameStart()
{
	TypeWriter("Welcome to the Dungeon Crawler! Prepare to explore a mysterious labyrinth filled with danger and adventure.");
	string playerName;
	TypeWriter("Please enter your name:");
	getline(cin, playerName);
	TypeWriter("Welcome, " + playerName + "! You won't know what lies ahead through this labyrinth. Find the means to survive. Your journey begins now.", 30, true);
	return playerName;
}

int main()
{
	string playerName = GameStart();
	Player player(playerName, 100, 10);
	Cellar(player);




}