#pragma once
#include <string>
#include "Player.h"


class Enemy : public Player
{
public:
	Enemy(string name, float health, float baseDamage);
};

void EncounterEnemy(const Enemy& enemy);
