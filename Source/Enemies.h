#pragma once
#include <string>
#include "Player.h"


class Enemy : public Player
{
public:
	Enemy(std::string name, int health, int baseDamage);
};

void EncounterEnemy(Player& player, Enemy& enemy, int speed, int windowSize);
