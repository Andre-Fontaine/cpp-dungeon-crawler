#include <iostream>
#include <random>
#include <limits>
#include <conio.h>
#include "Battle.h"

int GenerateNumber(int min, int max) //Generates a random number at the start of the battle
{
	static std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}

void PlayerFirst(Player& player, Enemy& enemy)
{
	std::cout << std::endl << "It's heads! " << player.name << " attacks for " << player.baseDamage << "." << std::endl;
	enemy.TakeDamage(player.baseDamage);
}

void EnemyFirst(Player& player, Enemy& enemy)
{
	std::cout << std::endl << "It's tails! " << enemy.name << " attacks for " << enemy.baseDamage << "." << std::endl;
	player.TakeDamage(enemy.baseDamage);
}

void Battle(Player& player, Enemy& enemy)
{
	std::cout << "A coin flip determines who attacks first in battle. Heads for " << player.name << ", tails for " << enemy.name << "." << std::endl;

	while (player.health > 0 && enemy.health > 0) //Battle loop that continues until either the player or the enemy's health drops to 0 or below
	{
		std::cout << std::endl << "Press any key to flip the coin..." << std::endl;
		_getch();
		int coinFlip = GenerateNumber(1, 3); //Generates a random number to determine who goes first in battle
		if (coinFlip == 1)
		{
			PlayerFirst(player, enemy);
		}
		else if (coinFlip == 2)
		{
			EnemyFirst(player, enemy);
		}
		else
		{
			std::cout << std::endl << "The coin flip is inconclusive! Both " << player.name << " and " << enemy.name << " attack simultaneously!" << std::endl;
			player.TakeDamage(enemy.baseDamage);
			enemy.TakeDamage(player.baseDamage);
		}
	}

	if (player.health > 0)
	{
		std::cout << std::endl << player.name << " wins the battle!" << std::endl;
	}
	else
	{
		std::cout << std::endl << enemy.name << " wins the battle!" << std::endl;
	}
}

