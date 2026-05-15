#include <iostream>
#include <random>
#include <limits>
#include <conio.h>
#include "Battle.h"
#include "source.h"
#include "Utils.h"

int GenerateNumber(int min, int max) //Generates a random number at the start of the battle
{
	static std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}

void PlayerFirst(Player& player, Enemy& enemy)
{
	TypeWriter("It's heads! " + player.name + " attacks for " + std::to_string(player.baseDamage) + ".", 30, true);
	enemy.TakeDamage(player.baseDamage);
}

void EnemyFirst(Player& player, Enemy& enemy)
{
	TypeWriter("It's tails! " + enemy.name + " attacks for " + std::to_string(enemy.baseDamage) + ".", 30, true);
	player.TakeDamage(enemy.baseDamage);
}

void Battle(Player& player, Enemy& enemy)
{
	TypeWriter("A coin flip determines who attacks first in battle. Heads for " + player.name + ", tails for " + enemy.name + ".", 30, true);

	while (player.health > 0 && enemy.health > 0) //Battle loop that continues until either the player or the enemy's health drops to 0 or below
	{
		TypeWriter("Press any key to flip the coin...", 30, true);
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
			TypeWriter("The coin flip is inconclusive! Both " + player.name + " and " + enemy.name + " attack simultaneously!", 30, true);
			player.TakeDamage(enemy.baseDamage);
			enemy.TakeDamage(player.baseDamage);
		}
	}

	if (player.health > 0)
	{
		TypeWriter(player.name + " wins the battle!", 30, true);
	}
	else
	{
		TypeWriter(enemy.name + " wins the battle!", 30, true);
	}
}

