#include "LevelView.h"


LevelView::LevelView(int width, int height)
	:BaseView(width, height, backgroundImage)
{
	
	this->backgroundImage = al_load_bitmap("Resources/Images/MapLevel.jpg");
	
	settingsButtonNormal = al_load_bitmap("Resources/Images/Atlas.png");
	atllasLevelMenu = al_load_bitmap("Resources/Images/AtlasLevelas.png");

	backButtonImage = al_create_sub_bitmap(settingsButtonNormal, 92, 4, 47, 29);
	backButtonImagePused = al_create_sub_bitmap(settingsButtonNormal, 151, 4, 47, 29);

	upButtonImage = al_create_sub_bitmap(atllasLevelMenu, 257, 87, 41, 57);
	upButtonImagePush = al_create_sub_bitmap(atllasLevelMenu, 209, 87, 41, 57);

	downButtonImage = al_create_sub_bitmap(atllasLevelMenu, 257, 153, 41, 57);
	downButtonImagePush = al_create_sub_bitmap(atllasLevelMenu, 209, 153, 41, 57);

	upMenuBackground = al_create_sub_bitmap(atllasLevelMenu, 0, 0, 380, 51);

	level1 = al_create_sub_bitmap(atllasLevelMenu, 28, 198, 31, 31);
	level2 = al_create_sub_bitmap(atllasLevelMenu, 28, 240, 31, 31);
	level3 = al_create_sub_bitmap(atllasLevelMenu, 28, 282, 31, 31);
	level4 = al_create_sub_bitmap(atllasLevelMenu, 28, 324, 31, 31);
	level5 = al_create_sub_bitmap(atllasLevelMenu, 28, 366, 31, 31);
	level6 = al_create_sub_bitmap(atllasLevelMenu, 28, 408, 31, 31);
	level7 = al_create_sub_bitmap(atllasLevelMenu, 78, 198, 31, 31);
	level8 = al_create_sub_bitmap(atllasLevelMenu, 78, 240, 31, 31);
	level9 = al_create_sub_bitmap(atllasLevelMenu, 78, 282, 31, 31);
	level10 = al_create_sub_bitmap(atllasLevelMenu, 78, 324, 31, 31);
	             
	nonStars = al_create_sub_bitmap(atllasLevelMenu, 31, 85, 60, 32);
	oneStars = al_create_sub_bitmap(atllasLevelMenu, 115, 85, 60, 32);
	twoStars = al_create_sub_bitmap(atllasLevelMenu, 31, 134, 60, 32);
	treeStars = al_create_sub_bitmap(atllasLevelMenu, 115, 134, 60, 32);
	blockLevel = al_create_sub_bitmap(atllasLevelMenu, 78, 198, 31, 31);


}

ViewType LevelView::CheckSwitchView(int x, int y)
{

	// нопка назад
	if (x >= 15 && x <= 65 && y >= 9 && y <= 39)
	{
		backButtonTimeout = 7;
		return ViewType::SettingMenu;
	}


	// нопки вниз и вверх
	if (x >= 330 && x <= 371 && y >= 340 && y <= 397)
	{
		upButtonTimeout = 7;
		if (skrolY > -30)
		{
			skrolY = skrolY;
		}
		else skrolY += 30;
		
	}

	if (x >= 330 && x <= 371 && y >= 406 && y <= 463)
	{
		downButtonTimeout = 7;
		if (skrolY < -210)
		{
			skrolY = skrolY;
		}
		else skrolY -= 30;
	}
	//-----------------------------------------------

	//ѕервый уровень
	if (x >= 59 && x <= 90 && y >= 185 + skrolY && y <= 216 + skrolY)
	{
		level1Timeout = 7;
			return ViewType::SettingMenu;
	}


	//¬торой уровень
	if (x >= 198 && x <= 229 && y >= 223 + skrolY && y <= 254 + skrolY)
	{
		level2Timeout = 7;
		return ViewType::SettingMenu;
	}




	viewState = ViewType::LevelView;
	return viewState;
}

void LevelView::ShowMenu()
{
	viewState = ViewType::LevelView;
}

void LevelView::Update()
{
	al_draw_bitmap(backgroundImage, 0, skrolY, 0);

	

	//«везды
	//starsView[(int)StarsView::Two] = new al_draw_bitmap(twoStars, 45,159+ skrolY, 0);
	al_draw_bitmap(twoStars, 45,159+ skrolY, 0);
	//-------

	//”ровень
	if (level1Timeout > 0)
	{
		al_draw_bitmap(level1, 59, 185 + skrolY, 0);
		if (--level1Timeout <= 0)
		{
			viewState = ViewType::MainMenu;
		}
	}
	else
	{
		al_draw_bitmap(level1, 59, 185 + skrolY, 0);
	}
	//-------------------

	//”ровень
	if (level2Timeout > 0)
	{
		al_draw_bitmap(level2, 198, 223 + skrolY, 0);
		if (--level2Timeout <= 0)
		{
			viewState = ViewType::MainMenu;
		}
	}
	else
	{
		al_draw_bitmap(level2, 198, 223 + skrolY, 0);
	}
	//-------------------

	al_draw_bitmap(upMenuBackground, 0, 0, 0);
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


	// нопки вниз вверх
	if (upButtonTimeout > 0)
	{
		al_draw_bitmap(upButtonImagePush, 330, 340, 0);
	}
	else
	{
		al_draw_bitmap(upButtonImage, 330,340, 0);
	}

	if (downButtonTimeout > 0)
	{
		al_draw_bitmap(downButtonImagePush, 330, 406, 0);
	}
	else
	{
		al_draw_bitmap(downButtonImage, 330, 406, 0);
	}
	//-------------------------------------


}




LevelView::~LevelView()
{

}

