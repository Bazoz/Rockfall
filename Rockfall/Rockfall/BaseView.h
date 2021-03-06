#pragma once
#include "AllegroHeader.h"
#include "CoreEnumerations.h"



class BaseView 
{

protected:
	int width;
	int height;

	ALLEGRO_BITMAP* backgroundImage;
	ALLEGRO_FONT* mainFont;
	
	ViewType viewState;

public:

	BaseView(int width, int height,ALLEGRO_BITMAP * backgroundImage);
	virtual void Update() = 0;
	virtual ViewType CheckSwitchView(int x, int y) = 0;
	virtual void ShowMenu() = 0;
	ViewType GetViewState();

	//virtual void EventHandler(ALLEGRO_EVENT &ev) = 0;// ��� 

};

