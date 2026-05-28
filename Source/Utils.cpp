#include <thread>
#include <iostream>
#include <chrono>
#include <conio.h>
#include "Utils.h"
using namespace std;

void TypeWriter(const string& text, int speed, bool newLineBefore) //Function to display text with a typewriter effect, used for storytelling and dialogue in the game
{
	if (newLineBefore)
	{
		cout << endl;
	}
	for (char c : text)
	{
		cout << c << flush;
		this_thread::sleep_for(chrono::milliseconds(speed));
	}
	cout << endl;

	// Flush input buffer so keypresses during dialogue are discarded
	while (_kbhit())
		_getch();
}

void Delay(int milliseconds) //Function to create a delay in the game, used for dramatic effect and pacing
{
	this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

