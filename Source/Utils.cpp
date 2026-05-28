#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include "Utils.h"

using namespace std;

void TypeWriter(const string& text, int speed, bool newLineBefore)
{
    if (newLineBefore)
        cout << endl;

    for (char c : text)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }

    cout << endl;

    // Discard any keypresses buffered during the typewriter effect
    while (_kbhit())
        _getch();
}

void Delay(int milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}
