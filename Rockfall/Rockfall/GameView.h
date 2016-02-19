#pragma once
#include "BaseView.h"
#include "Header.h"


class GameView : public BaseView
{


public:

	GameView(int width, int height);
	virtual void Update();
	ViewType CheckSwitchView(int x, int y);

	void ShowMenu();

	~GameView();
};

