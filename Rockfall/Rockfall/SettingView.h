#pragma once
#include "BaseView.h"
#include"Header.h"

class SettingMenu: public BaseView 
{


	ALLEGRO_BITMAP *settingsButtonNormal;
	ALLEGRO_BITMAP *backButtonImagePused;

	ALLEGRO_BITMAP * backButtonImage;
	ALLEGRO_BITMAP * backButtonImagePush;

	int backButtonTimeout;

public:
	SettingMenu(int width, int height);
	virtual void Update();
	ViewType CheckSwitchView(int x, int y) ;

	void ShowMenu();

	~SettingMenu();


};


