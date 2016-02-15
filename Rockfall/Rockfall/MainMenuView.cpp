#include "MainMenuView.h"



MainMenuView::MainMenuView(int width, int height)
	:BaseView( width, height, backgroundImage)
{
	backgroundImage = al_load_bitmap("Resources/Images/Main.png");
	settingsButtonPushed = al_load_bitmap("Resources/Images/Atlas.png");

	settingButtonImage = al_create_sub_bitmap(settingsButtonPushed, 232, 93, 47, 47);
	settingButtonImagePush = al_create_sub_bitmap(settingsButtonPushed, 284, 93, 47, 47);

	SoundButtonImage = al_create_sub_bitmap(settingsButtonPushed, 234, 259, 47, 47);
	SoundButtonImagePush = al_create_sub_bitmap(settingsButtonPushed, 284, 259, 47, 47);

}



ViewType MainMenuView::CheckSwitchView(int x, int y)
{
	if (x >= 29 && x <= 75 && y >= 598 && y <= 646)
	{
		SettingButtonTimeout = 15;
		return ViewType::MainMenu;
	}

	if (x >= 29 && x <= 75 && y >= 525 && y <= 571)
	{
		isOn = !isOn;
		SettingButtonTimeout = 0;
		return ViewType::MainMenu;
	}

	viewState = ViewType::MainMenu;
	//SettingButtonTimeout = 0;
	return viewState;
}

void MainMenuView::ShowMenu()
{
	viewState = ViewType::MainMenu;
}


void MainMenuView::Update()
{

	al_convert_mask_to_alpha(settingButtonImage, al_map_rgb(36, 255, 0));
	al_convert_mask_to_alpha(settingButtonImagePush, al_map_rgb(36, 255, 0));

	al_convert_mask_to_alpha(SoundButtonImagePush, al_map_rgb(36, 255, 0));
	al_convert_mask_to_alpha(SoundButtonImage, al_map_rgb(36, 255, 0));

	al_draw_bitmap(backgroundImage, 0, 0, 0);

	//cout << backButtonTimeout << endl;
	//------------------------------------------------------
	
	if (isOn == true)
		{
			al_draw_bitmap(SoundButtonImage, 29, 525, 0);
		}
		else al_draw_bitmap(SoundButtonImagePush, 29, 525, 0);
	
	
	if (SettingButtonTimeout > 0)
	{
		al_draw_bitmap(settingButtonImagePush, 29, 598, 0);
		if (SettingButtonTimeout > 0  && --SettingButtonTimeout <= 0)
		{
			viewState = ViewType::SettingMenu;
		}
	}

	else
	{
		
		al_draw_bitmap(settingButtonImage, 29, 598, 0);
		
	}
	

}

MainMenuView::~MainMenuView()
{

}
