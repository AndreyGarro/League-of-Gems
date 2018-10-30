//
// Matriz[50][25]
//

#include "Aplicacion.h"
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#define FPS 60.0

void Application::initApp() {
    this->Display = al_create_display(this->Width, this->Height);
    if (this->Display != NULL) {
        al_set_window_title(this->Display, this->title.c_str());
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0));
        std::cout << "Initialized OK" << std::endl;
    }
}

int Application::mainLoop() {
    al_init_primitives_addon();
    bool start = true;

    /////
    int tempX, tempY;
    int x,y;
    ////
    this->EventQueue = al_create_event_queue();
    al_install_mouse();
    al_init_image_addon();

    ALLEGRO_BITMAP *fondo = al_load_bitmap("grassTexture.jpg");

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);

    al_register_event_source(this->EventQueue, al_get_mouse_event_source());
    al_register_event_source(this->EventQueue, al_get_display_event_source(this->Display));
    al_register_event_source(EventQueue, al_get_timer_event_source(timer));


    al_start_timer(timer);


    while (start) {
        ALLEGRO_EVENT oEvent;
        al_wait_for_event(this->EventQueue, &oEvent);

        if(oEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            start = false;
        }
        else if(oEvent.mouse.button & 1){
            std::cout << "Hola mundo" << std::endl;
        }
        else if (oEvent.type == ALLEGRO_EVENT_MOUSE_AXES) {
             tempX = oEvent.mouse.x;
             tempY = oEvent.mouse.y;
        }
        else if (oEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            if(oEvent.mouse.button & 2){
                x = tempX;
                y = tempY;
                std::cout << x <<" "<< y << std::endl;
            }
        }

//        al_draw_bitmap(fondo, 0, 0, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0));
    }

    al_destroy_display(Display);
    al_destroy_timer(timer);
    al_destroy_bitmap(fondo);
    al_destroy_event_queue(EventQueue);
    return 0;
}
Application::~Application() { }