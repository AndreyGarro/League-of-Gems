//
// Created by christian on 22/10/18.
//

#include "Aplicacion.h"
#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_primitives.h>


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

    al_register_event_source(this->EventQueue, al_get_mouse_event_source());
    al_register_event_source(this->EventQueue, al_get_display_event_source(this->Display));


    while (start) {
        ALLEGRO_EVENT oEvent;
        al_wait_for_event(this->EventQueue, &oEvent);

        if(oEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            start = false;
            return 0;
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

        al_draw_filled_rectangle(550, 410, 560, 420, al_map_rgb_f(1.0,1.0,0.0));
        al_draw_filled_rectangle(550, 310, 570, 325, al_map_rgb_f(1.0,1.0,0.0));
        al_draw_filled_rectangle(550, 510, 570, 525, al_map_rgb_f(1.0,1.0,0.0));
        al_draw_filled_rectangle(550, 450, 570, 465, al_map_rgb_f(1.0,1.0,0.0));
        al_draw_filled_rectangle(550, 350, 570, 365, al_map_rgb_f(1.0,1.0,0.0));
        al_draw_filled_rectangle(0, 250, 75, 650, al_map_rgb_f(1.0,1.0,1.0));


        al_flip_display();
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0));
    }

}
Application::~Application() { }