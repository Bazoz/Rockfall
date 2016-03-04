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

	float Speed;

	int MaxRock;
	float SpeedRock;
	int OneStars;
	int TwoStars;
	int TreeStars;

	
	void Initialize();
	
	/*void InitRock(Rock rocks[], int size);
	void DrawRock(Rock rocks[], int size);
	void StartRock(Rock rocks[], int size);
	void UpdateRock(Rock rocks[], int size);*/

public:
	

	Level();
	Level(int maxRock, float speedRock, int oneStars, int twoStars, int treeStars);
	
	void Update();
	list<Rock>* GetRocks();

	//float MoveSpeedRock(float speed);

	~Level();
};

