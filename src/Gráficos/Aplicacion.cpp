
#include "Aplicacion.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <math.h>

void Application::initApp() {
    al_init();
    this->Display = al_create_display(this->Width, this->Height);
    if (this->Display != NULL) {
        al_set_window_title(this->Display, this->title.c_str());
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0));
        std::cout << "Initialized OK" << std::endl;
    }
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();
    initMatriz();
    imprimirMatriz();
    this->start = true;
    iFPS = al_get_display_refresh_rate(this->Display);
    this->fondo = al_load_bitmap("../img/grassTexture.bmp");
}

int Application::mainLoop(){
    //
    Player j1 = Player();
    Enemy e1 = Enemy();

    if (iFPS == 0) {
        iFPS = 30;
    }

    timer = al_create_timer(1.0 / iFPS);
    this->EventQueue = al_create_event_queue();
    al_register_event_source(this->EventQueue, al_get_mouse_event_source());
    al_register_event_source(this->EventQueue, al_get_display_event_source(this->Display));
    al_register_event_source(this->EventQueue, al_get_timer_event_source(timer));
    al_start_timer(timer);



    while (true) {
        al_wait_for_event(this->EventQueue, &oEvent);

        if (oEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (oEvent.mouse.button & 2) {
                this->x = oEvent.mouse.x;
                this->y = oEvent.mouse.y;
                std::cout << x << " " << y << std::endl;
                j1.setIJ(y/70, x/90, this->matriz);
            }
        }
        if(oEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            al_destroy_bitmap(fondo);
            al_destroy_display(this->Display);
            al_destroy_event_queue(this->EventQueue);
            al_destroy_timer(timer);
            return 0;
        }

        //// Actualiza la pantalla cada frame de la pantalla
        if (oEvent.type == ALLEGRO_EVENT_TIMER && oEvent.timer.source == timer) {
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_bitmap(fondo, 0, 0, 0);
            j1.dibujaJugador();
            e1.dibujaEnemigo();
            Sprite::dibujaObstaculo(matriz);
            al_flip_display();
        }
    }
}

void Application::initMatriz() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 15; ++j) {
            if(static_cast<int>(random() % 5) == 0){
                this->matriz[i][j] = 0;
            }
            else{
                this->matriz[i][j] = 1;
            }
            if(i>6 && j < 5){
                this->matriz[i][j] = 1;
            }
            if(i < 4   && j> 10){
                this->matriz[i][j] = 1  ;
            }
        }
    }
}
void Application::imprimirMatriz(){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 15; ++j) {
            std::cout << matriz[i][j] <<" ";
        }
        std::cout << std::endl;
    }
}

Application::~Application() {
}