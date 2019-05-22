#pragma once
#include "BaseView.h"
#include "Header.h"
#include "Level.h"

class GameView : public BaseView
{
	ALLEGRO_BITMAP * rockImage;
	Level* level;

	ALLEGRO_BITMAP * settingsButtonNormal;
	ALLEGRO_BITMAP * backButtonImage;
	ALLEGRO_BITMAP * backButtonImagePush;


	int backButtonTimeout;

	void DrawRock(Rock& rock);

public:

	GameView(int width, int height, ALLEGRO_BITMAP*  atlas);
	virtual void Update();
	ViewType CheckSwitchView(int x, int y);
	void SetLevel(Level* level);
	void ShowMenu();

	~GameView();
};

