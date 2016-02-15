#include "SettingView.h"



SettingMenu::SettingMenu(int width, int height)
	:BaseView(width, height, backgroundImage)
{
	backgroundImage = al_load_bitmap("Resources/Images/Settings.png");

	settingsButtonNormal = al_load_bitmap("Resources/Images/Atlas.png");

	backButtonImage = al_create_sub_bitmap(settingsButtonNormal, 92, 4, 142, 33);

	backButtonImagePused = al_create_sub_bitmap(settingsButtonNormal, 151, 4, 200, 33);
}



ViewType SettingMenu::CheckSwitchView(int x, int y)
{
	if (x >= 15 && x <= 65 && y >= 9 && y <= 39)
	{				
		backButtonTimeout = 5;
		return ViewType::SettingMenu;
	}

	viewState = ViewType::SettingMenu;
	backButtonTimeout = 0;
	return viewState;
}


void SettingMenu::ShowMenu()
{
	viewState = ViewType::SettingMenu;
}

void SettingMenu::Update()
{
	al_convert_mask_to_alpha(settingsButtonNormal, al_map_rgb(36, 255, 0));
	al_draw_bitmap(backgroundImage, 0, 0, 0);

	//cout << backButtonTimeout << endl;
	//------------------------------------------------------
	if (backButtonTimeout > 0)
	{
		al_draw_bitmap(backButtonImagePused, 15, 9, 0);
		if (--backButtonTimeout <= 0)
		{
			viewState = ViewType::MainMenu;
		}
	}
	else
	{
		al_draw_bitmap(backButtonImage, 15, 9, 0);
	}
	//---------------------------------------------------------
}

SettingMenu::~SettingMenu()
{
}
