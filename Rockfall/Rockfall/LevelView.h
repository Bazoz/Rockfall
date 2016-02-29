#pragma once
#include "BaseView.h"
#include "Level.h"

class LevelView : public BaseView
{

	int skrolY = 0 ;

	ALLEGRO_BITMAP * settingsButtonNormal;
	ALLEGRO_BITMAP * backButtonImagePused;
	ALLEGRO_BITMAP * atllasLevelMenu;

	ALLEGRO_BITMAP * backButtonImage;
	ALLEGRO_BITMAP * backButtonImagePush;

	ALLEGRO_BITMAP * upButtonImage;
	ALLEGRO_BITMAP * upButtonImagePush;

	ALLEGRO_BITMAP * downButtonImage;
	ALLEGRO_BITMAP * downButtonImagePush;

	ALLEGRO_BITMAP * level1;
	ALLEGRO_BITMAP * level2;
	ALLEGRO_BITMAP * level3;
	ALLEGRO_BITMAP * level4;
	ALLEGRO_BITMAP * level5;
	ALLEGRO_BITMAP * level6;
	ALLEGRO_BITMAP * level7;
	ALLEGRO_BITMAP * level8;
	ALLEGRO_BITMAP * level9;
	ALLEGRO_BITMAP * level10;

	ALLEGRO_BITMAP * blockLevel;
	ALLEGRO_BITMAP * nonStars;
	ALLEGRO_BITMAP * oneStars;
	ALLEGRO_BITMAP * twoStars;
	ALLEGRO_BITMAP * treeStars;

	ALLEGRO_BITMAP * upMenuBackground;

	int backButtonTimeout;
	int upButtonTimeout;
	int downButtonTimeout;
	int level1Timeout;
	int level2Timeout;
	int level3Timeout;
	int level4Timeout;
	int level5Timeout;
	int level6Timeout;
	int level7Timeout;
	int level8Timeout;
	int level9Timeout;
	int level10Timeout;

	Level * currentLevel;

	StarsView* starsView;

public:
	LevelView(int width, int height);// GemeControl * control
	virtual void Update();
	ViewType CheckSwitchView(int x, int y);

	void ShowMenu();
	~LevelView();

};

