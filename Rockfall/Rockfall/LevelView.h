#pragma once
#include "BaseView.h"
#include "Level.h"

class LevelView : public BaseView
{

	Level * currentLevel;
	//GemeControl* controlle;  // для упраления

public:
	LevelView(int width, int height);// GemeControl * control
	virtual void Update();
	ViewType CheckSwitchView(int x, int y);
	//void EventHandler(ALLEGRO_EVENT &ev);
	void ShowMenu();
	~LevelView();

};

