#pragma once
#include "Header.h"
#include "GameEnumeration.h"

class Rock
{

	int ID;
	int X;
	int Y;
	bool Live;
	float Speed;
	int Bountx;
	int Bounty;	

public:
	Rock();
	Rock(int x, int y, float speed);
	int GetX() const;
	int GetY() const;
	//int GetID() const;
	//bool GetLive() const;
	//float GetSpeed() const;
	//int GetBountx() const;
	//int GetBounty() const;



	void Move();
	~Rock();
};

