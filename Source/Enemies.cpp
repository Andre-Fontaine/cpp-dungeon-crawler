#include <iostream>
#include <conio.h>
#include "Enemies.h"
#include "Battle.h"
#include "Utils.h"

using namespace std;

Enemy::Enemy(string name, int health, int baseDamage)
    : Player(name, health, baseDamage)
{
}

void EncounterEnemy(Player& player, Enemy& enemy, int speed, int windowSize, bool isBoss)
{
    Delay(1500);

    cout << endl
         << "-----------------------------" << endl
         << "        BATTLE COMMENCED     " << endl
         << "-----------------------------" << endl
         << "Enemy:        " << enemy.name    << endl
         << "Enemy Health: " << enemy.health  << endl
         << "Enemy Damage: " << enemy.baseDamage << endl
         << endl
         << "Your Health:  " << player.health    << endl
         << "Your Damage:  " << player.baseDamage << endl
         << "-----------------------------" << endl;

    bool playerWon = Battle(player, enemy, speed, windowSize, isBoss);

    if (!playerWon)
    {
        TypeWriter("Your journey ends here.", 80, true);
        Delay(2000);
        TypeWriter("Press any key to close the game.", 100, true);
        (void)_getch();
        exit(0);
    }
}
