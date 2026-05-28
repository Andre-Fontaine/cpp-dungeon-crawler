#pragma once
#include <string>

// Prints text to the console one character at a time for a typewriter effect.
// speed: delay in milliseconds between each character (default: 30ms)
// newLineBefore: prints a blank line before the text if true (default: false)
void TypeWriter(const std::string& text, int speed = 30, bool newLineBefore = false);

// Pauses execution for the given number of milliseconds.
void Delay(int milliseconds);
