#include "GameView.h"


GameView::GameView(int width, int height)
	:BaseView(width, height, backgroundImage)
{
	backgroundImage = al_load_bitmap("Resources/Images/Game.jpg");

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


void GameView::Update()
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	viewState = ViewType::GameView;


}


GameView::~GameView()
{
}
