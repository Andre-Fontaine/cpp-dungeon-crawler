#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "source.h"
#include "Rooms.h"
#include "Enemies.h"
#include "Player.h"
#include "Items.h"
using namespace std;

void TypeWriter(const string& text, int speed)
{
	for (char c : text)
	{
		cout << c << flush;
		this_thread::sleep_for(chrono::milliseconds(speed));
	}
	cout << endl;
}

//Start of game
string GameStart()
{
	TypeWriter("Welcome to the Dungeon Crawler! Prepare to explore a mysterious labyrinth filled with danger and adventure.");
	string playerName;
	TypeWriter("Please enter your name:");
	getline(cin, playerName);
	TypeWriter("Welcome, " + playerName + "! Your journey begins now.");
	TypeWriter("You won't know what lies ahead through this labyrinth. Find the means to survive.");
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