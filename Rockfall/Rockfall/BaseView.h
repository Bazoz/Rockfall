#pragma once
#include "AllegroHeader.h"
#include "CoreEnumerations.h"



class BaseView 
{

protected:
	int width;
	int height;

	ALLEGRO_BITMAP* backgroundImage;
	ALLEGRO_FONT* mainFont;
	


public:

	BaseView(int width, int height,ALLEGRO_BITMAP * backgroundImage);
	virtual void Update() = 0;
	virtual ViewType CheckSwitchViev(int x, int y) = 0;

};

