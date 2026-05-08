#pragma once
#include <string>
#include <iostream>
#include "Player.h"
using namespace std;

class Items
{
public:
	string name;
	string description;
	float damageBonus;

	Items(string name, string description, float damageBonus);

	void UseItem(Player& player)
	{
		float totalDamage = player.baseDamage + damageBonus;
		player.baseDamage += damageBonus;
		cout << player.name << " picks up a " << name << " and gains " << damageBonus << " bonus damage, totalling " << totalDamage << " damage!" << endl;
	}
};