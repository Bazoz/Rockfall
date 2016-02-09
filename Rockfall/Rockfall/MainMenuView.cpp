#include "MainMenuView.h"



MainMenuView::MainMenuView(int width, int height)
	:BaseView( width, height, backgroundImage)
{
	backgroundImage = al_load_bitmap("Resources/Images/Main.jpg");


}



ViewType MainMenuView::CheckSwitchView(int x, int y)
{

	if (x >= 30 && x<=83 && y >=675 && y<= 727)
	{
		return ViewType::SettingMenu;
	}
	
	return ViewType::MainMenu;
}
//
//void GameView::ProcessEvent(ALLEGRO_EVENT* ev)
//{
//	PlayerRoket->Setdirection(currectDirection->GetDirection());
//}

void MainMenuView::Update()
{

	al_draw_bitmap(backgroundImage, 0, 0, 0);
	

}

MainMenuView::~MainMenuView()
{

}
