#include "GameView.h"


GameView::GameView(int width, int height, ALLEGRO_BITMAP* atlas)
	:BaseView(width, height, atlas)
{
	rockImage = al_create_sub_bitmap(atlas, 130, 590, 64, 59);
	this->backgroundImage = al_load_bitmap("Resources/Images/Game.jpg");	

	settingsButtonNormal = al_load_bitmap("Resources/Images/Atlas.png");
	backButtonImage = al_create_sub_bitmap(settingsButtonNormal, 92, 4, 47, 29);
	backButtonImagePush = al_create_sub_bitmap(settingsButtonNormal, 151, 4, 47, 29);

}



ViewType GameView::CheckSwitchView(int x, int y)
{
	//Кнопка назад
	if (x >= 15 && x <= 65 && y >= 9 && y <= 39)
	{
		backButtonTimeout = 7;
		return ViewType::GameView;
	}


	viewState = ViewType::GameView;
	return viewState;

}

void GameView::ShowMenu()
{
	viewState = ViewType::GameView;
}

void GameView::SetLevel(Level* level)
{
	this->level = level;
}

void GameView::Update()
{

	


	level->Update();

	al_draw_bitmap(backgroundImage, 0, 0, 0);

	list<Rock>* rocks = level->GetRocks();
	list<Rock>::iterator i = rocks->begin();

	while (i != rocks->end())
	{
		al_draw_bitmap(rockImage, i->GetX(), i->GetY(), 0);
		i++;
	}

	//------------------------------------------------------
	if (backButtonTimeout > 0)
	{
		al_draw_bitmap(backButtonImagePush, 15, 9, 0);
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

	//for_each(rocks->begin(), rocks->end(), DrawRock);
}

void GameView::DrawRock(Rock& rock)
{
	al_draw_bitmap(rockImage, rock.GetX(), rock.GetY(), 0);
}

GameView::~GameView()
{
}
