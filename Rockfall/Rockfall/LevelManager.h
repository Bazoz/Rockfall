#pragma once
#include "Header.h"
#include "Level.h"

class LevelManager
{
	static vector<Level> levels;
	static int currentLevel;

public:
	LevelManager();
	static void SetCurrentLevel(int number);
	static Level* GetCurrentLevel();
};