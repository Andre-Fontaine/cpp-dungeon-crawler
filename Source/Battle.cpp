#include <iostream>
#include <random>
#include <limits>
#include <conio.h>
#include <chrono>
#include <thread>
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

void PlayerAttack(Player& player, Enemy& enemy)//Function to handle the player's attack during the battle loop, allowing them to attack the enemy and reduce their health
{
	TypeWriter(player.name + " attacks for " + std::to_string(player.baseDamage) + ".", 30);
	enemy.TakeDamage(player.baseDamage);
}

void EnemyAttack(Player& player, Enemy& enemy)//Function to handle the enemy's attack during the battle loop, allowing them to attack the player and reduce their health
{
	TypeWriter(enemy.name + " attacks for " + std::to_string(enemy.baseDamage) + ".", 30);
	player.TakeDamage(enemy.baseDamage);
}

bool BattleTimer(Player& player, Enemy& enemy) //ADD DAMAGE UPON SUCCESS OR FAILURE. NOT COMPLETED.
{
    int position = 0;
    int direction = 1;
    int maxWidth = 20;
    int windowStart = 8;
    int windowEnd = 12;

    while (true)
    {
        std::string bar = "[";
        for (int i = 0; i < maxWidth; i++)
        {
            if (i == position)
                bar += "O";
            else if (i == windowStart || i == windowEnd)
                bar += "|";
            else if (i > windowStart && i < windowEnd)
                bar += "-";
            else
                bar += " ";
        }
        bar += "]";

        std::cout << "\r" << "Press 'Space' when in the window to deal damage: " << bar << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        if (_kbhit())
        {
            char ch = _getch();
            if (ch == ' ')
            {
                if (position >= windowStart && position <= windowEnd)
                {
                    std::cout << std::endl;
                    TypeWriter("Direct hit!", 30, true);
                    PlayerAttack(player, enemy);
                    return true;
                }
                else
                {
                    std::cout << std::endl;
                    TypeWriter("You missed!", 30, true);
                    EnemyAttack(player, enemy);
                    return false;
                }
            }
        }

        position += direction;
        if (position >= maxWidth - 1 || position <= 0)
        {
            direction = -direction;
        }
    }
}

bool Battle(Player& player, Enemy& enemy)//Function to handle the battle mechanics, including the coin flip to determine who goes first and the battle loop that continues until either the player or the enemy's health drops to 0 or below
{
	TypeWriter("A coin flip determines who attacks first in battle. Heads for " + player.name + ", tails for " + enemy.name + ".", 30, true);
	TypeWriter("Press any key to flip the coin...", 30, true);
	(void)_getch();
	int coinFlip = GenerateNumber(1, 2); //Generates a random number to determine who goes first in battle

		if (coinFlip == 1)
		{
			PlayerFirst(player, enemy);
		}
		else if (coinFlip == 2)
		{
			EnemyFirst(player, enemy);
		}

        while (player.health > 0 && enemy.health > 0)
        {
            BattleTimer(player, enemy);
        }

	//Determining the outcome of the battle and restoring the player's health if they win
	if (player.health > 0)
	{
		player.health = player.maxHealth; //Restores player's health to max after winning a battle
		TypeWriter(player.name + " wins the battle! Your health has been restored to " + std::to_string(player.maxHealth) + ".", 30, true);
		return true;
	}
	else
	{
		TypeWriter(enemy.name + " wins the battle!", 30, true);
		return false;
	}
}

