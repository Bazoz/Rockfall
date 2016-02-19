#pragma once
#include "Header.h"
#include "GameEnumeration.h"

class Rock
{

	int ID;
	float x;
	float y;
	bool live;
	float speed;
	int bountx;
	int bounty;	

public:
	Rock();
	Rock(int x, int y, float speed);
	int GetX() const;
	int GetY() const;
	void Move();
	~Rock();
};

