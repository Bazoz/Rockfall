#pragma once
#include "AllegroHeader.h"
#include "Header.h"
#include "MainMenuView.h"

class AllegroView
{
	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *eventQueu;

	ALLEGRO_BITMAP *backgroundImage;
	ALLEGRO_FONT* mainFont;

	BaseView* currentView;

	int width;
	int height;

	int fpsTimeout;


public:

	AllegroView();

	void Initialize(int width, int height);
	void StartGame();

	~AllegroView();

};

