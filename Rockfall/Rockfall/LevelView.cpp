#include "LevelView.h"


LevelView::LevelView(int width, int height)
	:BaseView(width, height, backgroundImage)
{
	
	backgroundImage = al_load_bitmap("Resources/Images/Level.jpg");


}

ViewType LevelView::CheckSwitchView(int x, int y)
{
	viewState = ViewType::LevelView;
	return viewState;
}

void LevelView::ShowMenu()
{
	viewState = ViewType::LevelView;
}

void LevelView::Update()
{

}




LevelView::~LevelView()
{

}

//void LevelView::EventHandler(ALLEGRO_EVENT &ev)
//{
//	// Активаия кнопок
//}
