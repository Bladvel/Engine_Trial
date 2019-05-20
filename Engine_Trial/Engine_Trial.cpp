// Engine_Trial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Animator.h"

/*This WHOLE proyect lacks include guards, add them*/

/*As this code is constantly rewritten dor experimentation, excuse the mess*/

int main()
{
	ALLEGRO_DISPLAY * display;
	ALLEGRO_EVENT_QUEUE *queue;


	al_init();
	display = al_create_display(640, 640);
	queue = al_create_event_queue();

	al_register_event_source(queue, al_get_display_event_source(display));

	al_init_image_addon();

	PackageManager Manager;
	Animator Rocas;
	Rocas.SetState(0);

	ALLEGRO_BITMAP* bitmap;
	bitmap = al_load_bitmap("Rocks0.png");

	std::vector<std::string> Imagen = {"Rocks0.png","Rocks1.png","Rocks2.png","Rocks3.png","Rocks4.png"};
	Manager.AddPackage("Rocas","Imagen",5,Imagen);

	Rocas.LoadPackage(Manager.UnpackImage("Rocas"));

	bool running = true;

	while (running) {

		al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));

		al_draw_bitmap(Rocas.Draw(), 0, 0, 0);

		al_flip_display();
	
		ALLEGRO_EVENT event;
		if (!al_is_event_queue_empty(queue)) {
			al_wait_for_event(queue, &event);
			if (event.type == ALLEGRO_EVENT_KEY_UP || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
				running = false;
		}
	}

	al_destroy_display(display);
	return 0;
}

