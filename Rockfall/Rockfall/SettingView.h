#pragma once
#include "BaseView.h"

class SettingMenu: public BaseView 
{
	ALLEGRO_BITMAP *settingsButtonNormal;
	ALLEGRO_BITMAP *backButtonImagePused;

	ALLEGRO_BITMAP * backButtonImage;




public:
	SettingMenu(int width, int height);
	virtual void Update();
	ViewType CheckSwitchView(int x, int y) ;

	~SettingMenu();


};


