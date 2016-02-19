#pragma once
#include "Header.h"
#include "GameEnumeration.h"

class Rock
{

	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int bountx;
	int bounty;

	const int NUM_ROCKS = 5;

public:
	Rock();

	void InitRock(Rock rocks[], int size);
	void DrawRock(Rock rocks[], int size);
	void StartRock(Rock rocks[], int size);
	void UpdateRock(Rock rocks[], int size);
	


	~Rock();
};

