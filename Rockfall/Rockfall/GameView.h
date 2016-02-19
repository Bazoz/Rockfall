#pragma once
#include "BaseView.h"
#include "Header.h"


class GameView : public BaseView
{

	ALLEGRO_BITMAP *settingsButtonNormal;
	ALLEGRO_BITMAP *settingsButtonPushed;

	ALLEGRO_BITMAP * settingButtonImage;
	ALLEGRO_BITMAP * settingButtonImagePush;


public:

	GameView(int width, int height);
	virtual void Update();
	ViewType CheckSwitchView(int x, int y);

	void ShowMenu();

	~GameView();
};

