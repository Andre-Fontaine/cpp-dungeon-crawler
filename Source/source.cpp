#include <iostream>
#include <string>
#include <limits>
#include "source.h"
#include "Rooms.h"
#include "Player.h"
#include "Utils.h"

using namespace std;

string GameStart()
{
    TypeWriter("Welcome to Dungeon Crawler.", 30, false);
    TypeWriter("You wake up. You do not know where you are. You do not know who you are.", 30, true);
    TypeWriter("But you remember your name.", 60, true);
    Delay(1000);

    string playerName;
    cout << endl << "Enter your name: ";
    getline(cin, playerName);

    TypeWriter("Welcome, " + playerName + ". Your journey begins now.", 30, true);
    Delay(1500);
    return playerName;
}

int main()
{
    string playerName = GameStart();
    Player player(playerName, 100, 10);
    Cellar(player);
    return 0;
}
