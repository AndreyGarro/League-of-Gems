//
// Matriz[50][25]
//

#include "Aplicacion.h"
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <math.h>
#define FPS 60.0


void Application::initApp() {
    this->Display = al_create_display(this->Width, this->Height);
    if (this->Display != NULL) {
        al_set_window_title(this->Display, this->title.c_str());
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0));
        std::cout << "Initialized OK" << std::endl;
    }
    initMatriz();
    imprimirMatriz();
    this->start = true;
}

int Application::mainLoop() {
    al_init_primitives_addon();
    this->EventQueue = al_create_event_queue();
    al_install_mouse();
    al_init_image_addon();


//    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
//    al_register_event_source(EventQueue, al_get_timer_event_source(timer));
    al_register_event_source(this->EventQueue, al_get_mouse_event_source());
    al_register_event_source(this->EventQueue, al_get_display_event_source(this->Display));


//    al_start_timer(timer);

    ALLEGRO_BITMAP *fondo = al_load_bitmap("/home/christian/Escritorio/LOG/img/grassTexture.png");

    while (start) {
        ALLEGRO_EVENT oEvent;
        al_wait_for_event(this->EventQueue, &oEvent);

        if(oEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            start = false;
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
            else if(oEvent.mouse.button & 1) {
                std::cout << x << " " << y << std::endl;
            }
        }

        al_draw_bitmap(fondo, 0, 0, 0);
        colocarObstaculos();
        al_flip_display();
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0));
    }

    al_destroy_bitmap(fondo);
    //al_destroy_timer(timer);
    return 0;
}

void Application::initMatriz() {
    srand(time(0));
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 50; ++j) {
            this->matriz[i][j] = random()%15;
        }
    }
}
void Application::imprimirMatriz(){
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 50; ++j) {
            std::cout << matriz[i][j] <<" ";
        }
        std::cout << std::endl;
    }
}
void Application::colocarObstaculos() {
    ALLEGRO_BITMAP *tree = al_load_bitmap("/home/christian/Escritorio/LOG/img/treeSprite.jpg");
    al_convert_mask_to_alpha(tree, al_map_rgb(1,1,1));
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 50; ++j) {
            if(matriz[i][j] == 0){
                float x =  j*50;
                float y = i*25;
                al_draw_filled_rectangle(x,y,x+26,y+28,al_map_rgb_f(1,1,1));
                al_draw_scaled_bitmap(tree, 0, 0, 900, 560, x, y ,50, 50,0);
            }
        }
    }
}

//int [25][50]Application::getMatriz() {
//    return matriz[25][50];
//}

Application::~Application() {
    al_destroy_display(Display);
    al_destroy_event_queue(EventQueue);
}