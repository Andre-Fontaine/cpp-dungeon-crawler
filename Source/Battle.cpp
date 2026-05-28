#include <iostream>
#include <random>
#include <conio.h>
#include <chrono>
#include <thread>
#include "Battle.h"
#include "Utils.h"

using namespace std;

// Internal helpers — not exposed in the header
static void PlayerFirst(Player& player, Enemy& enemy);
static void EnemyFirst(Player& player, Enemy& enemy);
static void PlayerAttack(Player& player, Enemy& enemy);
static void EnemyAttack(Player& player, Enemy& enemy);

int GenerateNumber(int min, int max)
{
    static mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

static void PlayerFirst(Player& player, Enemy& enemy)
{
    TypeWriter("It's heads! " + player.name + " attacks for " + to_string(player.baseDamage) + ".", 30);
    enemy.TakeDamage(player.baseDamage);
}

static void EnemyFirst(Player& player, Enemy& enemy)
{
    TypeWriter("It's tails! " + enemy.name + " attacks for " + to_string(enemy.baseDamage) + ".", 30);
    player.TakeDamage(enemy.baseDamage);
}

static void PlayerAttack(Player& player, Enemy& enemy)
{
    TypeWriter(player.name + " attacks for " + to_string(player.baseDamage) + ".", 30);
    enemy.TakeDamage(player.baseDamage);
}

static void EnemyAttack(Player& player, Enemy& enemy)
{
    TypeWriter(enemy.name + " attacks for " + to_string(enemy.baseDamage) + ".", 30);
    player.TakeDamage(enemy.baseDamage);
}

bool BattleTimer(Player& player, Enemy& enemy, int speed, int windowSize, bool randomPosition)
{
    int position    = 0;
    int direction   = 1;
    int maxWidth    = 20;
    int windowStart = randomPosition
        ? GenerateNumber(1, maxWidth - windowSize - 1)
        : (maxWidth / 2) - (windowSize / 2);
    int windowEnd   = windowStart + windowSize;

    while (true)
    {
        // Build the visual bar
        string bar = "[";
        for (int i = 0; i < maxWidth; i++)
        {
            if      (i == position)                        bar += "O";
            else if (i == windowStart || i == windowEnd)   bar += "|";
            else if (i > windowStart  && i < windowEnd)    bar += "-";
            else                                           bar += " ";
        }
        bar += "]";

        cout << "\r" << "Press SPACE when the marker is in the window: " << bar << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));

        if (_kbhit())
        {
            char ch = _getch();
            if (ch == ' ')
            {
                cout << endl;
                if (position > windowStart && position < windowEnd)
                {
                    TypeWriter("Success!", 30, true);
                    PlayerAttack(player, enemy);
                    return true;
                }
                else
                {
                    TypeWriter("Missed!", 30, true);
                    EnemyAttack(player, enemy);
                    return false;
                }
            }
        }

        position += direction;
        if (position >= maxWidth - 1 || position <= 0)
            direction = -direction;
    }
}

bool Battle(Player& player, Enemy& enemy, int speed, int windowSize, bool isBoss)
{
    TypeWriter("A coin flip determines who attacks first. Heads for " + player.name + ", tails for " + enemy.name + ".", 30, true);
    TypeWriter("Press any key to flip the coin.", 30, true);
    (void)_getch();

    int coinFlip = GenerateNumber(1, 2);
    if (coinFlip == 1)
        PlayerFirst(player, enemy);
    else
        EnemyFirst(player, enemy);

    if (isBoss)
    {
        // Boss battle: random speed and window size every round for unpredictable difficulty
        while (player.health > 0 && enemy.health > 0)
        {
            int currentSpeed      = GenerateNumber(20, 80);
            int currentWindowSize = GenerateNumber(2, 5);
            BattleTimer(player, enemy, currentSpeed, currentWindowSize, true);
        }
    }
    else
    {
        while (player.health > 0 && enemy.health > 0)
            BattleTimer(player, enemy, speed, windowSize);
    }

    if (player.health > 0)
    {
        player.health = player.maxHealth;
        TypeWriter(player.name + " wins the battle! Health restored to " + to_string(player.maxHealth) + ".", 30, true);
        Delay(1000);
        return true;
    }
    else
    {
        TypeWriter(enemy.name + " wins the battle!", 30, true);
        Delay(1000);
        return false;
    }
}
