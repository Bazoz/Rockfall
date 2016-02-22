#include "GameView.h"


GameView::GameView(int width, int height, ALLEGRO_BITMAP* atlas)
	:BaseView(width, height, atlas)
{
	rockImage = al_create_sub_bitmap(atlas, 130, 590, 64, 59);
	this->backgroundImage = al_load_bitmap("Resources/Images/Game.jpg");	


}



ViewType GameView::CheckSwitchView(int x, int y)
{
	
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

	//for_each(rocks->begin(), rocks->end(), DrawRock);
}

void GameView::DrawRock(Rock& rock)
{
	al_draw_bitmap(rockImage, rock.GetX(), rock.GetY(), 0);
}

GameView::~GameView()
{
}
