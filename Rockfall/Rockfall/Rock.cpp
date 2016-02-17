#include "Rock.h"



Rock::Rock()
{
}

void Rock::InitRock(Rock rocks[], int size)
{
	for (int i = 0; i < size; i++)
	{
		//rocks[i].ID = ENEMY;
		rocks[i].live = false;
		rocks[i].speed = 5;
		rocks[i].bountx = 18;
		rocks[i].bounty = 18;

	}
}

void Rock::DrawRock(Rock rocks[], int size)
{

}

void Rock::StartRock(Rock rocks[], int size)
{

}

void Rock::UpdateRock(Rock rocks[], int size)
{

}


Rock::~Rock()
{
}
