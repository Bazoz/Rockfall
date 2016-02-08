#include "MainMenuView.h"



MainMenuView::MainMenuView(int width, int height)
	:BaseView( width, height, backgroundImage)
{
	backgroundImage = al_load_bitmap("Resources/Images/Main.jpg");


}



ViewType MainMenuView::CheckSwitchView(int x, int y)
{

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
