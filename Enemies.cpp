#include <string>
#include <iostream>
#include "Enemies.h"
#include "Source.h"
using namespace std;

Enemy::Enemy(string name, float health, float baseDamage)
	: Player(name, health, baseDamage)
{ 
}

Enemy Spider("Spider", 50, 5);

//Function to display enemy encounter information
void EncounterEnemy(const Enemy& enemy)
{
	cout << endl
		<< "You encountered: " << enemy.name << endl
		<< "Health: " << enemy.health << endl
		<< "Damage: " << enemy.baseDamage << endl
		<< endl;
}

//Creating enemy Spider with stats
/*Enemy Spider;
Spider.name = "Spider";
Spider.health = 50;
Spider.baseDamage = 5;

//Creating enemy Giant Rat with stats
Enemy GiantRat;
GiantRat.name = "Giant Rat";
GiantRat.health = 75;
GiantRat.baseDamage = 10;

//Creating enemy Goblin with stats
Enemy Goblin;
Goblin.name = "Goblin";
Goblin.health = 100;
Goblin.baseDamage = 20;*/