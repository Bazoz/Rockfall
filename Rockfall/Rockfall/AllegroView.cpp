#include "AllegroView.h"



AllegroView::AllegroView()
{
	display = nullptr;
	timer = nullptr;
	eventQueu = nullptr;
	backgroundImage = nullptr;

	fpsTimeout = 60;
}


void AllegroView::Initialize(int width, int height)
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

	if (!al_init_font_addon())
	{
		throw "Font init error!";
	}

	if (!al_init_ttf_addon())
	{
		throw "Ttf init error!";
	}

	timer = al_create_timer(1.0 / fpsTimeout);

	if (timer == nullptr)
	{
		throw "Timer creation error!";
	}

	

	eventQueu = al_create_event_queue();
	if (eventQueu == nullptr)
	{
		throw "Event queue creation error!";
	}

	backgroundImage = al_load_bitmap("Resources/Images/Main.jpg"); //Подключение картинки
	
	mainFont = al_load_font("Resources/Fonts/RosewoodStd-Regular.otf", 25, 0);

	if (backgroundImage == nullptr)
	{
		throw "Load image error!";
	}

	al_set_target_bitmap(al_get_backbuffer(display));


	
	al_register_event_source(eventQueu, al_get_timer_event_source(timer)); 
	al_register_event_source(eventQueu, al_get_display_event_source(display));
	al_register_event_source(eventQueu, al_get_keyboard_event_source());


	currentView = new MainMenuView(width, height, backgroundImage, mainFont);


}

void AllegroView::StartGame()
{
	al_start_timer(timer);
	ALLEGRO_EVENT ev;
	
	//al_convert_mask_to_alpha(mainAtlas, al_map_rgb(0, 0, 0));


	while (true) //главный цыкл преложения
	{
		al_wait_for_event(eventQueu, &ev);


		if (ev.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(eventQueu))
		{
			currentView->Update();
			
			al_flip_display();

		}

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}
	}
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
