#pragma once
#include <string>
#include "Player.h"


class Enemy : public Player
{
public:
	Enemy(std::string name, float health, float baseDamage);
};

void EncounterEnemy(Player& player, const Enemy& enemy);
