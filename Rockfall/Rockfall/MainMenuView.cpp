#include "MainMenuView.h"



MainMenuView::MainMenuView(int width, int height)
	:BaseView( width, height, backgroundImage)
{
	backgroundImage = al_load_bitmap("Resources/Images/Main.png");
	settingsButtonPushed = al_load_bitmap("Resources/Images/Atlas.png");

	settingButtonImage = al_create_sub_bitmap(settingsButtonNormal, 93, 232, 140, 279);

	settingButtonImagePush = al_create_sub_bitmap(settingsButtonNormal, 93, 284, 140, 330);
}



ViewType MainMenuView::CheckSwitchView(int x, int y)
{
	if (x >= 29 && x <= 75 && y >= 598 && y <= 646)
	{
		backButtonTimeout = 5;
		return ViewType::MainMenu;
	}

	viewState = ViewType::MainMenu;
	backButtonTimeout = 0;
	return viewState;
}

void MainMenuView::ShowMenus()
{
	viewState = ViewType::MainMenu;
}


void MainMenuView::Update()
{

	al_convert_mask_to_alpha(settingsButtonNormal, al_map_rgb(36, 255, 0));
	al_draw_bitmap(backgroundImage, 0, 0, 0);

	//cout << backButtonTimeout << endl;
	//------------------------------------------------------
	if (backButtonTimeout > 0)
	{
		al_draw_bitmap(settingButtonImagePush, 29, 75, 0);
		if (--backButtonTimeout <= 0)
		{
			viewState = ViewType::SettingMenu;
		}
	}
	else
	{
		al_draw_bitmap(settingButtonImage, 29, 75, 0);
	}
	

}

MainMenuView::~MainMenuView()
{

}
