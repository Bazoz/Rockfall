#pragma once
#include "BaseView.h"
#include"Header.h"

class MainMenuView : public BaseView
{
	ALLEGRO_BITMAP *settingsButtonNormal;
	ALLEGRO_BITMAP *settingsButtonPushed;

	ALLEGRO_BITMAP * settingButtonImage;
	ALLEGRO_BITMAP * settingButtonImagePush;

	ALLEGRO_BITMAP * SoundButtonImage;
	ALLEGRO_BITMAP * SoundButtonImagePush;


	int SettingButtonTimeout;
	bool isOn = true;

public:
	MainMenuView(int width, int height);
	virtual void Update();
	ViewType CheckSwitchView(int x, int y) ;

	void ShowMenu();

	~MainMenuView();


};

