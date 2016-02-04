#include "AllegroView.h"



AllegroView::AllegroView()
{
	display = nullptr;
	timer = nullptr;
	eventQueu = nullptr;
	backgroundImage = nullptr;

	fpsTimeout = 60;
}


void AllegroView::Initialize(int width, int height, int r, int g, int b)
{

	if (!al_init())     //Инициализация библиотеки
	{
		throw "Allegro initialize error!"; //Не проинициализированна библиотека
	}

	al_init_image_addon();

	this->width = width;
	this->height = height;

	display = al_create_display(width, height);

	if (display == nullptr)
	{

		throw "Display creation error!";
	}

	if (!al_install_keyboard())
	{
		throw "Install keyboard error!";
	}


	backgroundColor.r = r;
	backgroundColor.b = b;
	backgroundColor.g = g;
	backgroundColor.a = 0;

	

}


AllegroView::~AllegroView()
{
	if (display != nullptr)
	{
		al_destroy_display(display);
	}

	if (timer != nullptr)
	{
		al_destroy_timer(timer);
	}

	if (eventQueu != nullptr)
	{
		al_destroy_event_queue(eventQueu);
	}



}
