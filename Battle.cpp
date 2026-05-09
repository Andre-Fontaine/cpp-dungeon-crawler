#include <iostream>
#include <random>
#include <limits>
#include "Battle.h"
#include <conio.h>
using namespace std;

int GenerateNumber(int min, int max) //Generates a random number at the start of the battle
{
	static mt19937 rng(random_device{}());
	uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}

void PlayerFirst(Player& player, Enemy& enemy)
{
	std::cout << player.name << " attacks for " << player.baseDamage << "." << std::endl;
	enemy.TakeDamage(player.baseDamage);
}

void EnemyFirst(Player& player, Enemy& enemy)
{
	std::cout << enemy.name << " attacks for " << enemy.baseDamage << "." << std::endl;
	player.TakeDamage(enemy.baseDamage);
}

void Battle(Player& player, Enemy& enemy)
{
	cout << "A coin flip determines who goes first in battle. Heads for " << player.name << ", tails for " << enemy.name << "." << endl
		<< "Press any key to flip the coin..." << endl;
	_getch();

	int coinFlip = GenerateNumber(1, 2); //Generates a random number to determine who goes first in battle
	if (coinFlip == 1)
	{
		cout << endl << "It's heads! " << player.name << " goes first!" << endl;
		PlayerFirst(player, enemy);
	}
	else
	{
		cout << endl << "It's tails! " << enemy.name << " goes first!" << endl;
		EnemyFirst(player, enemy);
	}
}

