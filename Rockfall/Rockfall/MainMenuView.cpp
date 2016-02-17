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
	//--------настройки
	if (x >= 29 && x <= 75 && y >= 598 && y <= 646)
	{
		SettingButtonTimeout = 7;
		return ViewType::MainMenu;
	}

	//--------звук
	if (x >= 29 && x <= 75 && y >= 525 && y <= 571)
	{
		isOn = !isOn;
		SettingButtonTimeout = 0;
		return ViewType::MainMenu;
	}

	//--------статус
	if (x >= 322 && x <= 370 && y >= 525 && y <= 572)
	{
		StatusButtonTimeout = 7;
		return ViewType::MainMenu;
	}

	//--------магазин
	if (x >= 322 && x <= 368 && y >= 598 && y <= 644)
	{
		StorButtonTimeout = 7;
		return ViewType::MainMenu;
	}

	//--------левел
	if (x >= 113 && x <= 290 && y >= 551 && y <= 598)
	{
		LevelButtonTimeout = 7;
		return ViewType::MainMenu;
	}

	//--------плей
	if (x >= 94 && x <= 311 && y >= 279 && y <= 494)
	{
		PlayButtonTimeout = 7;
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
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	
	//-----Кнока звука
	if (isOn == true)
		{
			al_draw_bitmap(SoundButtonImage, 29, 525, 0);
		}
		else al_draw_bitmap(SoundButtonImagePush, 29, 525, 0);
	//-----------------------------------
	
	//Кнопка Настройки -------------------------
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

	//-----------Кнопка статус
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

	//-----------Кнопка Магазина
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

	//-----------Кнопка Урони
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

	//-----------Кнопка Play
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
