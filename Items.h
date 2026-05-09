#pragma once
#include <string>
#include <iostream>
#include "Player.h"

class Items
{
public:
	std::string name;
	std::string description;
	float damageBonus;

	Items(std::string name, std::string description, float damageBonus);
	void UseItem(Player& player)
	{
		float totalDamage = player.baseDamage + damageBonus;
		player.baseDamage += damageBonus;
		std::cout << player.name << " picks up a " << name << " and gains " << damageBonus << " bonus damage, totalling " << totalDamage << " damage!" << std::endl;
	}
};