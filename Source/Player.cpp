#include <string>
#include "Player.h"

using namespace std;

Player::Player(string name, int health, int baseDamage)
    : name(name), health(health), baseDamage(baseDamage), maxHealth(health), maxDamage(baseDamage)
{
}

void Player::TakeDamage(int damage)
{
    health -= damage;
    TypeWriter(name + " takes " + to_string(damage) + " damage and has " + to_string(health) + " health left.", 30, true);

    if (health <= 0)
    {
        health = 0;
        TypeWriter(name + " has been defeated!", 30, true);
    }
}
