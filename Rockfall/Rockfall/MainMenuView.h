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

	ALLEGRO_BITMAP * StatusButtonImage;
	ALLEGRO_BITMAP * StatusButtonImagePush;

	ALLEGRO_BITMAP * StorButtonImage;
	ALLEGRO_BITMAP * StorButtonImagePush;

	ALLEGRO_BITMAP * LevelButtonImage;
	ALLEGRO_BITMAP * LevelButtonImagePush;

	ALLEGRO_BITMAP * PlayButtonImage;
	ALLEGRO_BITMAP * PlayButtonImagePush;

	int SettingButtonTimeout;
	int StatusButtonTimeout;
	int StorButtonTimeout;
	int LevelButtonTimeout;
	int PlayButtonTimeout;

	bool isOn = true;

public:
	MainMenuView(int width, int height);
	virtual void Update();
	ViewType CheckSwitchView(int x, int y) ;

	void ShowMenu();

	~MainMenuView();


};

