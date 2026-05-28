#pragma once
#include "Player.h"
#include "Enemies.h"

int GenerateNumber(int min, int max); //Generates a random number at the start of the program

void PlayerFirst(Player& player, Enemy& enemy);
void EnemyFirst(Player& player, Enemy& enemy);
bool Battle(Player& player, Enemy& enemy, int speed, int windowSize, bool isBoss = false);
bool BattleTimer(Player& player, Enemy& enemy, int speed, int windowSize, bool randomPosition = false);
