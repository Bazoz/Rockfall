#pragma once
#include "BaseView.h"
class SettingMenu: public BaseView 
{


public:
	SettingMenu(int width, int height);
	virtual void Update();
	ViewType CheckSwitchViev(int x, int y) ;
	~SettingMenu();


};

