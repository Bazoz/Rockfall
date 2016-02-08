#include "MainMenuView.h"



MainMenuView::MainMenuView(int width, int height, ALLEGRO_BITMAP * backgroundImage, ALLEGRO_FONT * mainFont)
	:BaseView( width, height, backgroundImage, mainFont)
{
	
}



ViewType MainMenuView::CheckSwitchViev(int x, int y)
{
	
	backgroundImage = al_load_bitmap("Resources/Images/Main.jpg");

	if (x >= 22 && x<=71 && y >=640 && y<= 690)
	{
		return ViewType::SettingMenu;
	}
	
	return ViewType::MainMenu;
}

void MainMenuView::Update()
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	

}

MainMenuView::~MainMenuView()
{

}
