#pragma once
#include "BaseView.h"
class SettingMenu: public BaseView 
{


public:
	SettingMenu(int width, int height, ALLEGRO_BITMAP * backgroundImage, ALLEGRO_FONT * mainFont);
	virtual void Update();
	ViewType CheckSwitchViev(int x, int y) ;
	~SettingMenu();


};


