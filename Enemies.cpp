#include <string>
#include <iostream>
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
	cout << "-----------------------------" << endl
		<< "BATTLE COMMENCED" << endl
		<< "You encountered: " << enemy.name << endl
		<< "Health: " << enemy.health << endl
		<< "Damage: " << enemy.baseDamage << endl
		<< "-----------------------------" << endl;
	Battle(player, enemy);
}
