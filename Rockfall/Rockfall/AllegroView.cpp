#include "AllegroView.h"



AllegroView::AllegroView()
{
	display = nullptr;
	timer = nullptr;
	eventQueue = nullptr;
	backgroundImage = nullptr;
	bouncer_x = 0;
	bouncer_y = 0;
	views = new BaseView*[2];

	fpsTimeout = 60;
}


void AllegroView::Initialize(int width, int height)
{

	if (!al_init())     //Инициализация библиотеки
	{
		throw "Allegro initialize error!"; //Не проинициализированна библиотека
	}

	al_install_mouse();

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

	if (!al_install_mouse()) {
		throw  "failed to initialize the mouse!";
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

	eventQueue = al_create_event_queue();
	if (eventQueue == nullptr)
	{
		throw "Event queue creation error!";
	}
	

	backgroundImage = al_load_bitmap("Resources/Images/Main.png"); //Подключение картинки

	mainAtlas = al_load_bitmap("Resources/Images/Atlas.png");

	if (backgroundImage == nullptr || mainAtlas == nullptr)
	{
		throw "Load image error!";
	}


	al_set_target_bitmap(al_get_backbuffer(display));

	
	
	al_register_event_source(eventQueue, al_get_timer_event_source(timer)); 
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_mouse_event_source());


	
	//currentView = new Setting(width, height, backgroundImage, mainFont);
	views[(int)ViewType::MainMenu] = new MainMenuView(width, height) ;
	views[(int)ViewType::SettingMenu] = new SettingMenu(width, height);
	views[(int)ViewType::GameView] = new GameView(width, height);
	views[(int)ViewType::LevelView] = new LevelView(width, height);
	currentView = views[(int)ViewType::MainMenu];


}

void AllegroView::StartGame()
{
	al_start_timer(timer);
	ALLEGRO_EVENT ev;
	
	//al_convert_mask_to_alpha(mainAtlas, al_map_rgb(0, 0, 0));

	//currentView->RocessEvent(ev);

	al_convert_mask_to_alpha(mainAtlas, al_map_rgb(36, 255, 0));

	while (true) //главный цыкл преложения
	{
		al_wait_for_event(eventQueue, &ev);
		
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;
			
			views[(int)currentView->CheckSwitchView(bouncer_x, bouncer_y)];
			
		}

		if (ev.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(eventQueue))
		{
	
			currentView->Update();
			ViewType type = currentView->GetViewState();
			currentView = views[(int)type];
			currentView->ShowMenu();
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

	if (eventQueue != nullptr)
	{
		al_destroy_event_queue(eventQueue);
	}


}
