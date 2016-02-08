#include "SettingView.h"



Setting::Setting(int width, int height, ALLEGRO_BITMAP * backgroundImage, ALLEGRO_FONT * mainFont)
	:BaseView(width, height, backgroundImage, mainFont)
{

}

void Setting::Update()
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	backgroundImage = al_load_bitmap("Resources/Images/Settings.jpg");
	//backgroundImage = al_load_bitmap("Resources/Images/Main.jpg");
	/*al_draw_text(mainFont, al_map_rgb(255, 0, 0), width / 2, 10, ALLEGRO_ALIGN_CENTER, "MainMenu");
	al_draw_text(mainFont, al_map_rgb(255, 0, 0), 100, 200 , 0, "MainMenu");*/  //текст в меню

}


Setting::~Setting()
{
}
