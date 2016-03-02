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

	//Кнопка назад
	if (x >= 15 && x <= 65 && y >= 9 && y <= 39)
	{
		backButtonTimeout = 7;
		return ViewType::SettingMenu;
	}


	//Кнопки вниз и вверх
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

	//Первый уровень
	if (x >= 59 && x <= 90 && y >= 185 + skrolY && y <= 216 + skrolY)
	{
		level1Timeout = 7;
			return ViewType::SettingMenu;
	}


	//Второй уровень
	if (x >= 198 && x <= 229 && y >= 223 + skrolY && y <= 254 + skrolY)
	{
		level2Timeout = 7;
		return ViewType::SettingMenu;
	}

	//3 уровень
	if (x >= 317 && x <= 348 && y >= 299 + skrolY && y <= 330 + skrolY)
	{
		level3Timeout = 7;
		return ViewType::SettingMenu;
	}


	//4 уровень
	if (x >= 224 && x <= 255 && y >= 391 + skrolY && y <= 442 + skrolY)
	{
		level4Timeout = 7;
		return ViewType::SettingMenu;
	}

	//5 уровень
	if (x >= 94 && x <= 125 && y >= 326 + skrolY && y <= 357 + skrolY)
	{
		level5Timeout = 7;
		return ViewType::SettingMenu;
	}

	//6 уровень
	if (x >= 113 && x <= 144 && y >= 461 + skrolY && y <= 4692 + skrolY)
	{
		level6Timeout = 7;
		return ViewType::SettingMenu;
	}

	//7 уровень
	if (x >= 299 && x <= 330 && y >= 498 + skrolY && y <= 529 + skrolY)
	{
		level7Timeout = 7;
		return ViewType::SettingMenu;
	}

	//8 уровень
	if (x >= 293 && x <= 324 && y >= 606 + skrolY && y <= 637 + skrolY)
	{
		level8Timeout = 7;
		return ViewType::SettingMenu;
	}

	//9 уровень
	if (x >= 161 && x <= 192 && y >= 588 + skrolY && y <= 619 + skrolY)
	{
		level9Timeout = 7;
		return ViewType::SettingMenu;
	}

	//10 уровень
	if (x >= 69 && x <= 100 && y >= 692 + skrolY && y <= 723 + skrolY)
	{
		level10Timeout = 7;
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

	

	//Звезды
	//starsView[(int)StarsView::Two] = new al_draw_bitmap(twoStars, 45,159+ skrolY, 0);
	al_draw_bitmap(twoStars, 45,159+ skrolY, 0);

	al_draw_bitmap(nonStars, 184, 196 + skrolY, 0);

	al_draw_bitmap(nonStars, 303, 273 + skrolY, 0);

	al_draw_bitmap(nonStars, 210, 364 + skrolY, 0);

	al_draw_bitmap(nonStars, 80, 229 + skrolY, 0);

	al_draw_bitmap(nonStars, 99, 434 + skrolY, 0);

	al_draw_bitmap(nonStars, 285, 471 + skrolY, 0);

	al_draw_bitmap(nonStars, 279, 579 + skrolY, 0);

	al_draw_bitmap(nonStars, 147, 562 + skrolY, 0);

	al_draw_bitmap(nonStars, 55, 666 + skrolY, 0);

	//-------

	//Уровень 1
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

	//Уровень 2
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

	//Уровень 3
	if (level3Timeout > 0)
	{
		al_draw_bitmap(level3, 317, 299 + skrolY, 0);
		if (--level3Timeout <= 0)
		{
			viewState = ViewType::MainMenu;
		}
	}
	else
	{
		al_draw_bitmap(level3, 317, 299 + skrolY, 0);
	}
	//-------------------

	//Уровень 4
	if (level4Timeout > 0)
	{
		al_draw_bitmap(level4, 224, 391 + skrolY, 0);
		if (--level4Timeout <= 0)
		{
			viewState = ViewType::MainMenu;
		}
	}
	else
	{
		al_draw_bitmap(level4, 224, 391 + skrolY, 0);
	}
	//-------------------

	//Уровень 5
	if (level5Timeout > 0)
	{
		al_draw_bitmap(level5, 94, 326 + skrolY, 0);
		if (--level5Timeout <= 0)
		{
			viewState = ViewType::MainMenu;
		}
	}
	else
	{
		al_draw_bitmap(level5, 94, 326 + skrolY, 0);
	}
	//-------------------

	//Уровень 6
	if (level6Timeout > 0)
	{
		al_draw_bitmap(level6, 113, 461 + skrolY, 0);
		if (--level6Timeout <= 0)
		{
			viewState = ViewType::MainMenu;
		}
	}
	else
	{
		al_draw_bitmap(level6, 113, 461 + skrolY, 0);
	}
	//-------------------

	//Уровень 7
	if (level7Timeout > 0)
	{
		al_draw_bitmap(level7, 299, 498 + skrolY, 0);
		if (--level7Timeout <= 0)
		{
			viewState = ViewType::MainMenu;
		}
	}
	else
	{
		al_draw_bitmap(level7, 299, 498 + skrolY, 0);
	}
	//-------------------

	//Уровень 8
	if (level8Timeout > 0)
	{
		al_draw_bitmap(level8, 293, 606 + skrolY, 0);
		if (--level8Timeout <= 0)
		{
			viewState = ViewType::MainMenu;
		}
	}
	else
	{
		al_draw_bitmap(level8, 293, 606 + skrolY, 0);
	}
	//-------------------

	//Уровень 9
	if (level9Timeout > 0)
	{
		al_draw_bitmap(level9, 161, 588 + skrolY, 0);
		if (--level9Timeout <= 0)
		{
			viewState = ViewType::MainMenu;
		}
	}
	else
	{
		al_draw_bitmap(level9, 161, 588 + skrolY, 0);
	}
	//-------------------

	//Уровень 10
	if (level10Timeout > 0)
	{
		al_draw_bitmap(level10, 69, 692 + skrolY, 0);
		if (--level10Timeout <= 0)
		{
			viewState = ViewType::MainMenu;
		}
	}
	else
	{
		al_draw_bitmap(level10, 69, 692 + skrolY, 0);
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


	//Кнопки вниз вверх
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

