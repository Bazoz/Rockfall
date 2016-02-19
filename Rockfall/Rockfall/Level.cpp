#include "Level.h"

Level::Level()
{
	Vector2 p1(74, 240);
	Vector2 p2(210, 261);
	Vector2 p3(339, 267);

	spawnPoints.push_back(p1);
	spawnPoints.push_back(p2);
	spawnPoints.push_back(p3);
}

void Level::Initialize(int rocksCount)
{
	while (--rocksCount >= 0)
	{
		CreateRock();
	}
}

void Level::CreateRock()
{
	Vector2 pos = spawnPoints[rand() % spawnPoints.size()];
	//Rock r(pos.X, pos.Y, 5);
	Rock r(100, 400, 5);
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

Level::~Level()
{

}
