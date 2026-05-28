#pragma once
#include "Player.h"
#include "Enemies.h"

// Returns a random integer between min and max (inclusive).
int GenerateNumber(int min, int max);

// Runs the full battle sequence between player and enemy.
// speed: marker speed in milliseconds for the timing minigame
// windowSize: width of the hit window in the timing minigame
// isBoss: enables random difficulty scaling each round (default: false)
// Returns true if the player wins, false if the enemy wins.
bool Battle(Player& player, Enemy& enemy, int speed, int windowSize, bool isBoss = false);

// Displays the timing minigame bar and handles player input.
// randomPosition: randomises the hit window position each call (default: false)
// Returns true on a successful hit, false on a miss.
bool BattleTimer(Player& player, Enemy& enemy, int speed, int windowSize, bool randomPosition = false);
