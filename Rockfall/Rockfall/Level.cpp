#include "Level.h"

Level::Level()
{
	SpeedRock = 0;
	MaxRock =OneStars = TwoStars = TreeStars = 0;
}


Level::Level(int maxRock, float speedRock, int oneStars, int twoStars, int threeStars)
{
	MaxRock = maxRock;
	SpeedRock = speedRock;
	OneStars = oneStars;
	TwoStars = twoStars;
	TreeStars = threeStars;

	Vector2 p1(74, 240);
	Vector2 p2(210, 261);
	Vector2 p3(339, 267);

	spawnPoints.push_back(p1);
	spawnPoints.push_back(p2);
	spawnPoints.push_back(p3);

	/*this->Live = live;
	this->Speed = speed;
	this->Bountx = bountx;
	this->Bounty = bounty;*/


	Initialize();
}

void Level::Initialize()
{
	int rocksCount = MaxRock;
	while (--rocksCount >= 5)
	{
		CreateRock();
	}
}

void Level::CreateRock()
{
		Vector2 pos = spawnPoints[rand() % spawnPoints.size()];
		//Rock r(pos.X, , SpeedRock);
		Rock r(74, pos.Y, 3);
		
		rocks.push(r);
}

void Level::Update()
{
	list<Rock>::iterator i = visibleRocks.begin();
	while (i != visibleRocks.end())
	{
		i->Move();
		i++;
	}

	if (visibleRocks.size() == 0)
	{		
		visibleRocks.push_back(rocks.front());
		rocks.pop();
	}


}

list<Rock>* Level::GetRocks()
{
	return &visibleRocks;
}

//float Level::MoveSpeedRock(float speed)
//{
//	if (true)
//	{
//
//	}
//
//	this->Speed = speed;
//	return Speed;
//}


 

Level::~Level()
{   


	

}
