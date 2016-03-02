#include "LevelManager.h"

vector<Level> LevelManager::levels;
int LevelManager::currentLevel = 0;

void LevelManager::InitLevelManager()
{
	Level urov1(15, 3, 3, 8, 15);
	Level urov2(30, 5, 8, 15, 30);
	Level urov3(50, 7, 13, 25, 50);
	Level urov4(70, 10, 18, 40, 70);
	Level urov5(90, 14, 24, 53, 90);
	Level urov6(110,17, 30, 60, 110);
	Level urov7(130, 20, 42, 73, 130);
	Level urov8(150, 22, 51, 90, 150);
	Level urov9(170, 25, 68, 102, 170);
	Level urov10(500, 30, 90, 248, 500);

	levels.push_back(urov1);
	levels.push_back(urov2);
	levels.push_back(urov3);
	levels.push_back(urov4);
	levels.push_back(urov5);
	levels.push_back(urov6);
	levels.push_back(urov7);
	levels.push_back(urov8);
	levels.push_back(urov9);
	levels.push_back(urov10);

}

void LevelManager::SetCurrentLevel(int number)
{	
	currentLevel = number;

}

Level* LevelManager::GetCurrentLevel()
{
	return &levels[currentLevel];
	
}