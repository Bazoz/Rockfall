#pragma once
#include "BaseView.h"
#include"Header.h"

class MainMenuView : public BaseView
{
	ALLEGRO_BITMAP *settingsButtonNormal;
	ALLEGRO_BITMAP *settingsButtonPushed;

	ALLEGRO_BITMAP * settingButtonImage;
	ALLEGRO_BITMAP * settingButtonImagePush;

	int backButtonTimeout;

public:
	MainMenuView(int width, int height);
	virtual void Update();
	ViewType CheckSwitchView(int x, int y) ;

	void ShowMenus();

	~MainMenuView();


};

