#include <iostream>
#include <random>
#include <limits>
#include <conio.h>
#include "Battle.h"
#include "Rooms.h"
#include "source.h"
#include "Utils.h"
#include "Items.h"
#include "Player.h"

int GenerateNumber(int min, int max) //Generates a random number at the start of the battle
{
	static std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}

void PlayerFirst(Player& player, Enemy& enemy)//Function to determine the outcome of the battle if the player goes first, allowing them to attack the enemy and reduce their health before the enemy can attack back
{
	TypeWriter("It's heads! " + player.name + " attacks for " + std::to_string(player.baseDamage) + ".", 30);
	enemy.TakeDamage(player.baseDamage);
}

void EnemyFirst(Player& player, Enemy& enemy)//Function to determine the outcome of the battle if the enemy goes first, allowing them to attack the player and reduce their health before the player can attack back
{
	TypeWriter("It's tails! " + enemy.name + " attacks for " + std::to_string(enemy.baseDamage) + ".", 30);
	player.TakeDamage(enemy.baseDamage);
}

void Battle(Player& player, Enemy& enemy)//Function to handle the battle mechanics, including the coin flip to determine who goes first and the battle loop that continues until either the player or the enemy's health drops to 0 or below
{
	TypeWriter("A coin flip determines who attacks first in battle. Heads for " + player.name + ", tails for " + enemy.name + ".", 30, true);
	while (player.health > 0 && enemy.health > 0) //Battle loop that continues until either the player or the enemy's health drops to 0 or below
	{
		TypeWriter("Press any key to flip the coin...", 30, true);
		(void)_getch();
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

	//Determining the outcome of the battle and restoring the player's health if they win
	if (player.health > 0)
	{
		player.health = player.maxHealth; //Restores player's health to max after winning a battle
		TypeWriter(player.name + " wins the battle! Your health has been restored to " + std::to_string(player.maxHealth) + ".", 30, true);
	}
	else
	{
		TypeWriter(enemy.name + " wins the battle! Game over.", 30, true);
	}
}

