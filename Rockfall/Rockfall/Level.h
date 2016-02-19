#pragma once
#include "Header.h"
#include "Rock.h"
#include "Vector2.h"

class Level
{
	const int NUM_ROCKS = 5;
	vector<Vector2> spawnPoints;
	queue<Rock> rocks;
	list<Rock> visibleRocks;
	void CreateRock();

	/*void InitRock(Rock rocks[], int size);
	void DrawRock(Rock rocks[], int size);
	void StartRock(Rock rocks[], int size);
	void UpdateRock(Rock rocks[], int size);*/

public:
	Level();
	void Initialize(int rocksCount);
	void Update();
	list<Rock>* GetRocks();

	~Level();
};

