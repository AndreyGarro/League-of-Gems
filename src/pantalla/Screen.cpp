//
// Created by andrew on 06/10/18.
//

#include "Screen.h"
#include <allegro5/allegro_native_dialog.h>
#include <string>
#include <iostream>
#include <jmorecfg.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

void Screen::iniciar() {

    if(!al_init()) {
        al_show_native_message_box(NULL, "ERROR", NULL, "No se pudo inicializar Allegro", NULL, NULL);
    }

    this->display = al_create_display(screenWidth, screenHeight);
//    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    display = al_create_display(screenWidth, screenHeight);
    al_set_window_position(display, 0,0);
    al_set_window_title(display, "League Of Gems");

    if(!display){
        al_show_native_message_box(NULL, "ERROR", NULL, "No se pudo crear el Display", NULL, NULL);
    }

    al_init_primitives_addon();
    al_draw_rectangle(10, 10, 100, 100, al_map_rgb(255, 98, 100), 9.0);

    al_flip_display();
    al_rest(5.0);
    al_destroy_display(display);




}
