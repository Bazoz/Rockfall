#include "Rock.h"



Rock::Rock()
{
}

Rock::Rock(int x, int y, float speed)
{
	//this->ID = id;
	this->X = x;
	this->Y = y;
	//this->Live = live;
	this->Speed = speed;
	//this->Bountx = bountx;
	//this->Bounty = bounty;

}

int Rock::GetX() const
{
	return X;
}

int Rock::GetY() const
{
	return Y;
}

//int Rock::GetID() const
//{
//	return ID;
//}
//
//bool Rock::GetLive() const
//{
//	return Live;
//}
//
//float Rock::GetSpeed() const
//{
//	return Speed;
//}
//
//int Rock::GetBountx() const
//{
//	return Bountx;
//}
//
//int Rock::GetBounty() const
//{
//	return Bounty;
//}



int s = 0;

void Rock::Move()
{	
	Y++;
	if (Y >= 670)
	{
		Y= 100;
	}
	

	cout << "x: " << X << "y: " << Y << endl;


	/*	s++;
		X += s < 100 ? 0.5 : -0.5;
		if (s > 200) s = 0;
		float offset = X - 100;
		Y = 400 - ((offset * offset)/10);

		cout << "x: " << X << "y: " << Y << endl;*/
	
}

Rock::~Rock()
{
}
