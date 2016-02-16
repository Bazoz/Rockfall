#include "LevelView.h"


LevelView::LevelView(int width, int height, Level* level)
	:BaseView(width, height, backgroundImage)
{
	currentLevel = level;
}

//void LevelView::Update()
//{
//
//}
//
//ViewType LevelView::CheckSwitchView(int x, int y)
//{
//
//}


LevelView::~LevelView()
{

}

//void LevelView::EventHandler(ALLEGRO_EVENT &ev)
//{
//	// Активаия кнопок
//}
