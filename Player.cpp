#include <string>
#include <iostream>
#include "source.h"
#include "Player.h"
#include "Items.h"

using namespace std;

Player::Player(string name, float health, float baseDamage)
    : name(name), health(health), baseDamage(baseDamage)
{
}

