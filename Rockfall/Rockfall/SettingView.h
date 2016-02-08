#pragma once
#include "BaseView.h"
class Setting: public BaseView
{


public:
	Setting(int width, int height, ALLEGRO_BITMAP * backgroundImage, ALLEGRO_FONT * mainFont);
	virtual void Update();
	~Setting();


};


