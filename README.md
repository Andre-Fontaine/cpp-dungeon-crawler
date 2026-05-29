# Dungeon Crawler

A text-based dungeon crawler written in C++ where the player navigates a series 
of rooms, encounters enemies, finds weapons and armor, and faces a final boss to 
escape limbo.

## About
The player wakes up in a cellar with no memory of who they are. Progressing 
through interconnected rooms, they face enemies in a timing-based combat system, 
find and equip items that permanently alter their stats, and ultimately confront 
a mirror image of themselves as the final boss.

## Features
- Timing-based combat minigame with a moving marker and hit window
- Boss battle with randomised speed and window position each round
- Branching room paths with multiple routes through the dungeon
- Weapon and armor equip system with stat replacement logic
- Permanent stat choices that carry through the entire game
- Typewriter dialogue effect with input buffer flushing
- Player name input used throughout the narrative

## Built With
- C++17
- Visual Studio
- Windows Console (uses `<conio.h>` for real-time input)

## How to Build and Run

### Requirements
- Windows
- Visual Studio 2019 or later

### Visual Studio
1. Clone the repository
2. Open the solution file in Visual Studio
3. Build in Release mode (Build → Build Solution)
4. Press Ctrl+F5 to run

### Command Line
```bash
g++ source.cpp Player.cpp Enemies.cpp Items.cpp Rooms.cpp Battle.cpp Utils.cpp -o DungeonCrawler
./DungeonCrawler
```

## How to Play
- Enter your name when prompted
- Read each room description carefully
- Press A or B to make choices at each prompt
- During combat, press SPACE when the marker is inside the window to deal damage
- Missing the window lets the enemy attack instead
- Find and equip weapons and armor to improve your stats
- Survive all encounters to reach the final boss

## Project Structure
```
├── source.h / source.cpp     — Entry point and game start sequence
├── Player.h / Player.cpp     — Player class with stats and damage handling
├── Enemies.h / Enemies.cpp   — Enemy class inheriting from Player
├── Items.h / Items.cpp       — Item class, equip logic, and item definitions
├── Rooms.h / Rooms.cpp       — All room functions and encounter logic
├── Battle.h / Battle.cpp     — Combat system including timing minigame
└── Utils.h / Utils.cpp       — TypeWriter and Delay utility functions
```

## Screenshots
**Opening**
<img width="1468" height="707" alt="Main" src="https://github.com/user-attachments/assets/948ad924-f363-4966-bab2-a44ccd9d0aee" />

**Multiple Choice**
<img width="1455" height="302" alt="Second" src="https://github.com/user-attachments/assets/577ae044-f307-4425-b5d0-e01d46d9e658" />

**Battle**
<img width="1477" height="425" alt="Third" src="https://github.com/user-attachments/assets/c2fb1607-fa06-4f8c-9a41-a84da33bcfb4" />

**Equipping**
<img width="1473" height="245" alt="Fourth" src="https://github.com/user-attachments/assets/545c28e8-c274-47cb-b0bb-345a3ef71a37" />

## What I Learned
- Structuring a multi-file C++ project across headers and source files
- Class inheritance with Player as a base class for Enemy
- Separating interface from implementation across .h and .cpp files
- Real-time console input using `_kbhit()` and `_getch()` from `<conio.h>`
- Persistent stat tracking across a full game session
- Writing clean, maintainable code across a project of this scale

## Part of
This project is part of my C++ Game Development learning roadmap.
Working toward a career in game development using C++ and Unreal Engine 5.
