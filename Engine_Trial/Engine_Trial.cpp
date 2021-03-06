// Engine_Trial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Animator.h"

/*This WHOLE proyect lacks include guards, add them*/

const double Frames = 30.0;
/*As this code is constantly rewritten dor experimentation, excuse the mess*/

int main()
{
	ALLEGRO_DISPLAY * display;
	ALLEGRO_EVENT_QUEUE *queue;
	ALLEGRO_TIMER *timer;


	al_init();
	display = al_create_display(640, 640);
	queue = al_create_event_queue();

	al_register_event_source(queue, al_get_display_event_source(display));

	timer = al_create_timer(1.0 / Frames);

	al_init_image_addon();

	PackageManager Manager;
	Animator Rocas(2);

	ALLEGRO_BITMAP* bitmap;
	bitmap = al_load_bitmap("Rocks0.png");

	std::vector<std::string> Imagen = {"Rocks0.png","Rocks1.png","Rocks2.png","Rocks3.png","Rocks4.png"};
	Manager.AddPackage("Rocas","Imagen",5,Imagen);

	Rocas.LoadPackage(Manager.UnpackImage("Rocas"));

	bool running = true;
	al_start_timer(timer);
	al_register_event_source(queue, al_get_timer_event_source(timer));

	while (running) {

		al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));

		Rocas.AnimateLoop(false);

		al_draw_bitmap(Rocas.Draw(), 320, 320, 0);

		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);

		if (event.type == ALLEGRO_EVENT_KEY_UP || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			running = false;

		if (event.type == ALLEGRO_EVENT_TIMER) {
			al_flip_display();
		}
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	return 0;
}

