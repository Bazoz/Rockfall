#pragma once
#include "AllegroHeader.h"
#include "Header.h"
#include "MainMenuView.h"
#include "CoreEnumerations.h"
#include "SettingView.h"
#include "Rock.h"
#include "GameView.h"
#include "LevelView.h"

class AllegroView 
{
	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *eventQueue;

	ALLEGRO_BITMAP *backgroundImage;
	ALLEGRO_FONT* mainFont;
	ALLEGRO_BITMAP *mainAtlas;

	BaseView* currentView;
	BaseView** views ;


	int width;
	int height;

	int fpsTimeout;

	int bouncer_x;
	int bouncer_y;



public:

	AllegroView();

	void Initialize(int width, int height);
	void StartGame();

	~AllegroView();

};

