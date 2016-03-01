#include "Rock.h"



Rock::Rock()
{
}

Rock::Rock(int x, int y, float speed)
{
	this->x = x;
	this->y = y;
	this->speed = speed;
}

int Rock::GetX() const
{
	return x;
}

int Rock::GetY() const
{
	return y;
}

int s = 0;

void Rock::Move()
{

	//while (live != false)
	//{
		s++;
		x += s < 100 ? 0.5 : -0.5;
		if (s > 200) s = 0;
		float offset = x - 100;
		y = 400 - ((offset * offset)/10);

		cout << "x: " << x << "y: " << y << endl;
	//}
	
}

Rock::~Rock()
{
}
