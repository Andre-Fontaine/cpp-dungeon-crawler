#include "Items.h"
#include "Player.h"
using namespace std;

Items::Items() : name(""), description(""), damageBonus(0)
{
}

Items::Items(string name, string description, float damageBonus)
    : name(name), description(description), damageBonus(damageBonus)
{
}

void Items::ChooseItem(Player& player)
{
    float totalDamage = player.baseDamage + damageBonus;
    player.baseDamage += damageBonus;
    cout << player.name << " picks up a " << name << " and gains "
        << damageBonus << " bonus damage, totalling "
        << totalDamage << " damage!" << endl;
}

Items Mace("Mace", "A heavy club.", 7);
Items Axe("Axe", "A sharp blade.", 6);
Items Bow("Bow", "A ranged weapon.", 10);