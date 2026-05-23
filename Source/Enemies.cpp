#include <string>
#include <iostream>
#include <conio.h>
#include "Enemies.h"
#include "Source.h"
#include "Battle.h"
#include "Player.h"

using namespace std;

Enemy::Enemy(string name, int health, int baseDamage)
	: Player(name, health, baseDamage)
{ 
}

//Function to display enemy encounter information
void EncounterEnemy(Player& player, Enemy& enemy)
{
	cout << endl 
		<< "-----------------------------" << endl
		<< "BATTLE COMMENCED" << endl
		<< "You encountered: " << enemy.name << endl
		<< "Enemy Health: " << enemy.health << endl
		<< "Enemy Damage: " << enemy.baseDamage << endl
		<< endl
		<< "Your Health: " << player.health << endl
		<< "Your Damage: " << player.baseDamage << endl
		<< "-----------------------------" << endl;

	bool playerWon = Battle(player, enemy);
	if (!playerWon)
	{
		TypeWriter("Your journey ends here.", 80, true);
		Delay(2000);
		TypeWriter("Press any key to close the game...", 100, true);
		(void)_getch();
		exit(0); //Exits the game if the player loses the battle
	}
}
