#include "SettingView.h"



SettingMenu::SettingMenu(int width, int height)
	:BaseView(width, height, backgroundImage)
{
	backgroundImage = al_load_bitmap("Resources/Images/Settings.jpg");
}



ViewType SettingMenu::CheckSwitchViev(int x, int y)
{
	
	if (x >= 8 && x <= 61 && y >= 7 && y <= 38)
	{
		return ViewType::MainMenu;
	}

	return ViewType::SettingMenu;
}

void SettingMenu::Update()
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	

}

SettingMenu::~SettingMenu()
{
}
