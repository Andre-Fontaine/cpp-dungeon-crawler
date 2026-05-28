#pragma once
#include <string>
#include "Player.h"

// Enemy inherits all stats and behaviour from Player.
// Enemies are created locally in each room with their own name, health, and damage values.
class Enemy : public Player
{
public:
    Enemy(std::string name, int health, int baseDamage);
};

// Displays encounter info, runs the battle, and handles game over if the player loses.
// isBoss: enables escalating random difficulty (default: false)
void EncounterEnemy(Player& player, Enemy& enemy, int speed, int windowSize, bool isBoss = false);
