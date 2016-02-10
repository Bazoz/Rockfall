#pragma once
#include "BaseView.h"


class MainMenuView : public BaseView
{
	ALLEGRO_BITMAP *settingsButtonNormal;
	ALLEGRO_BITMAP *settingsButtonPushed;



public:
	MainMenuView(int width, int height);
	virtual void Update();
	ViewType CheckSwitchView(int x, int y) ;
	void ShowMenu();

	~MainMenuView();


};

