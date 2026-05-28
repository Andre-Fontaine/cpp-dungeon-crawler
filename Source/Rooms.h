#pragma once
#include <string>
#include "Items.h"

class Player;

class Rooms
{
public:
    std::string name;
    bool        hasItem  = false;
    bool        hasItem2 = false;
    Items       item;
    Items       item2;
};

// Checks if the room contains an item and prompts the player to equip it.
void ItemEncounter(Player& player, Rooms& room);

// Reads a char input, converts to uppercase, and loops until A or B is entered.
char RoomChoice(char A, char B);

// Room functions — called in sequence as the player progresses
void Cellar(Player& player);
void Foyer(Player& player);
void Basement(Player& player);
void Library(Player& player);
void DiningHall(Player& player);
void Armory(Player& player);
void Courtyard(Player& player);
