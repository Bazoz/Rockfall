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

	StatusButtonImage = al_create_sub_bitmap(settingsButtonPushed, 233, 150, 47, 47);
	StatusButtonImagePush = al_create_sub_bitmap(settingsButtonPushed, 284, 150, 47, 47);

	StorButtonImage = al_create_sub_bitmap(settingsButtonPushed, 235, 206, 47, 47);
	StorButtonImagePush = al_create_sub_bitmap(settingsButtonPushed, 284, 206, 47, 47);

	LevelButtonImage = al_create_sub_bitmap(settingsButtonPushed, 4, 37, 178, 47);
	LevelButtonImagePush = al_create_sub_bitmap(settingsButtonPushed, 189, 37, 178, 47);

	PlayButtonImage = al_create_sub_bitmap(settingsButtonPushed, 4, 89, 215, 215);
	PlayButtonImagePush = al_create_sub_bitmap(settingsButtonPushed, 4, 307, 215, 215);

}



ViewType MainMenuView::CheckSwitchView(int x, int y)
{
	//--------���������
	if (x >= 29 && x <= 75 && y >= 598 && y <= 646)
	{
		SettingButtonTimeout = 15;
		return ViewType::MainMenu;
	}

	//--------����
	if (x >= 29 && x <= 75 && y >= 525 && y <= 571)
	{
		isOn = !isOn;
		SettingButtonTimeout = 0;
		return ViewType::MainMenu;
	}

	//--------������
	if (x >= 322 && x <= 370 && y >= 525 && y <= 572)
	{
		StatusButtonTimeout = 15;
		return ViewType::MainMenu;
	}

	//--------�������
	if (x >= 322 && x <= 368 && y >= 598 && y <= 644)
	{
		StorButtonTimeout = 15;
		return ViewType::MainMenu;
	}

	//--------�����
	if (x >= 113 && x <= 290 && y >= 551 && y <= 598)
	{
		LevelButtonTimeout = 15;
		return ViewType::MainMenu;
	}

	//--------����
	if (x >= 94 && x <= 311 && y >= 279 && y <= 494)
	{
		PlayButtonTimeout = 15;
		return ViewType::MainMenu;
	}

	viewState = ViewType::MainMenu;
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

	al_convert_mask_to_alpha(StatusButtonImagePush, al_map_rgb(36, 255, 0));
	al_convert_mask_to_alpha(StatusButtonImage, al_map_rgb(36, 255, 0));

	al_convert_mask_to_alpha(StorButtonImagePush, al_map_rgb(36, 255, 0));
	al_convert_mask_to_alpha(StorButtonImage, al_map_rgb(36, 255, 0));

	al_convert_mask_to_alpha(LevelButtonImagePush, al_map_rgb(36, 255, 0));
	al_convert_mask_to_alpha(LevelButtonImage, al_map_rgb(36, 255, 0));

	al_convert_mask_to_alpha(PlayButtonImagePush, al_map_rgb(36, 255, 0));
	al_convert_mask_to_alpha(PlayButtonImage, al_map_rgb(36, 255, 0));


	al_draw_bitmap(backgroundImage, 0, 0, 0);
	
	//-----����� �����
	if (isOn == true)
		{
			al_draw_bitmap(SoundButtonImage, 29, 525, 0);
		}
		else al_draw_bitmap(SoundButtonImagePush, 29, 525, 0);
	//-----------------------------------
	
	//������ ��������� -------------------------
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
	//------------------------------------------

	//-----------������ ������
	if (StatusButtonTimeout > 0)
	{
		al_draw_bitmap(StatusButtonImagePush, 318, 525, 0);
		if (StatusButtonTimeout > 0 && --StatusButtonTimeout <= 0)
		{
			viewState = ViewType::SettingMenu;
		}
	}
	else
	{
		al_draw_bitmap(StatusButtonImage, 318, 525, 0);
	}
	//-------------------------------

	//-----------������ ��������
	if (StorButtonTimeout > 0)
	{
		al_draw_bitmap(StorButtonImagePush, 318, 598, 0);
		if (StorButtonTimeout > 0 && --StorButtonTimeout <= 0)
		{
			viewState = ViewType::SettingMenu;
		}
	}
	else
	{
		al_draw_bitmap(StorButtonImage, 318, 598, 0);
	}
	//-------------------------------

	//-----------������ �����
	if (LevelButtonTimeout > 0)
	{
		al_draw_bitmap(LevelButtonImagePush, 113, 551, 0);
		if (LevelButtonTimeout > 0 && --LevelButtonTimeout <= 0)
		{
			viewState = ViewType::SettingMenu;
		}
	}
	else
	{
		al_draw_bitmap(LevelButtonImage, 113, 551, 0);
	}
	//-------------------------------

	//-----------������ Play
	if (PlayButtonTimeout > 0)
	{
		al_draw_bitmap(PlayButtonImagePush, 94, 279, 0);
		if (PlayButtonTimeout > 0 && --PlayButtonTimeout <= 0)
		{
			viewState = ViewType::SettingMenu;
		}
	}
	else
	{
		al_draw_bitmap(PlayButtonImage, 94, 279, 0);
	}
	//-------------------------------


}

MainMenuView::~MainMenuView()
{

}
