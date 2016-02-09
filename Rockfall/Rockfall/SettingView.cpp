#include "SettingView.h"



SettingMenu::SettingMenu(int width, int height)
	:BaseView(width, height, backgroundImage)
{
	backgroundImage = al_load_bitmap("Resources/Images/Settings.jpg");

	settingsButtonNormal = al_load_bitmap("Resources/Images/Atlas.png");

	backButtonImage = al_create_sub_bitmap(settingsButtonNormal, 109, 5, 57, 35);

	backButtonImagePused = al_create_sub_bitmap(settingsButtonNormal, 174, 5, 57, 35);
}


ViewType SettingMenu::CheckSwitchView(int x, int y)
{
	
	if (x >= 8 && x <= 61 && y >= 7 && y <= 38)
	{
		return ViewType::MainMenu;
	}
	return ViewType::SettingMenu;
}


void SettingMenu::Update()
{

	al_convert_mask_to_alpha(settingsButtonNormal, al_map_rgb(140, 0, 165));
	al_draw_bitmap(backgroundImage, 0, 0, 0);

	al_draw_bitmap(backButtonImage, 15, 6, 0);

}

SettingMenu::~SettingMenu()
{
}
