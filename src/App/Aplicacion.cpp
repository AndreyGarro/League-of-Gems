
#include "Aplicacion.h"
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <math.h>
//
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

//

int Application::matriz[10][15] = {};
/**
 * Iniciacion de todos los atributos y dependencias
 *  para utilizar las funcionalidades de allegro
 */
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
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
    initMatriz();
    imprimirMatriz();
    this->start = true;
    iFPS = al_get_display_refresh_rate(this->Display);
    this->fondo = al_load_bitmap("../img/grassTexture.bmp");
}

/**
 * Ciclo principal de la aplicacion
 * @return
 */
int Application::mainLoop(){
    //
    SoldierController j1;
    EnemyController e1;


    if (iFPS == 0) {
        iFPS = 30;
    }
    timer = al_create_timer(1.0 / iFPS);
    this->EventQueue = al_create_event_queue();
    al_register_event_source(this->EventQueue, al_get_mouse_event_source());
    al_register_event_source(this->EventQueue, al_get_display_event_source(this->Display));
    al_register_event_source(this->EventQueue, al_get_timer_event_source(timer));
    al_register_event_source(this->EventQueue, al_get_keyboard_event_source());

    al_start_timer(timer);

    while (start) {
        al_wait_for_event(this->EventQueue, &oEvent);
        if(this->flagNivel){
            al_show_native_message_box(Display, "Ganaste la Gema!", "Pasaste al siguiente Nivel", "", NULL, NULL);
            this->flagNivel = false;
            if(this->nivel + 1 < 5){
                subirNivel(nivel + 1);
                j1.subirNivel(nivel + 1);
                e1.subirNivel();
            }
        }
        if (oEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (oEvent.mouse.button & 2) {
                this->x = oEvent.mouse.x;
                this->y = oEvent.mouse.y;
                resetMatriz();
                if (y / 70 > 8 && x / 90 < 4 && x/90 > 0) {}
                else {
                    j1.setIJ(y / 70, x / 90, Application::matriz, this->nivel);
                }
            }
            else if(oEvent.mouse.button & 1){
                this->x = oEvent.mouse.x;
                this->y = oEvent.mouse.y;
                if (y / 70 > 8 && x / 90 < 4) {
                    j1.escogerAtaque(y / 70, x / 90);
                }
            }
        }
        if(oEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            al_destroy_bitmap(fondo);
            al_destroy_display(this->Display);
            al_destroy_event_queue(this->EventQueue);
            al_destroy_timer(timer);
            return 0;
        }

        //// Actualiza la pantalla cada 30fps de la pantalla
        if (oEvent.type == ALLEGRO_EVENT_TIMER && oEvent.timer.source == timer) {
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_bitmap(fondo, 0, 0, 0);
            resetMatriz();
            Sprite::dibujaObstaculo(Application::matriz);
            Sprite::dibujaBarraAtaques(Application::matriz);
            j1.dibujaJugador();
            e1.dibujaEnemigo();
            SimpleList<pair<int, pair<int, int>>> listaEnemigos;
            SimpleList<pair<int, pair<int, int>>> listaSoldados;
            listaEnemigos = e1.atacar(matriz);
            listaSoldados = j1.atacar(matriz);
            flagNivel = e1.disminuirVida(listaSoldados);
            j1.disminuirVida(listaEnemigos);
            al_flip_display();
        }
        if(this->nivel +1 == 5 && flagNivel){
            al_show_native_message_box(Display, "Ganaste!!!", "Felicidades ganaste el juego", "", NULL, NULL);
            this->start = false;
            al_flip_display();
        }
    }
}

/**
 * Iniciar la matriz, reservando los espacios necesarios y colocando obstaculos
 */
void Application::initMatriz() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 15; ++j) {
            if(static_cast<int>(random() % 5) == 0){
                Application::matriz[i][j] = 0;
            }
            else{
                Application::matriz[i][j] = 1;
            }
            if(i>6 && j < 5){
                Application::matriz[i][j] = 1;
            }if(i>8 && j < 4 && j > 0){
                Application::matriz[i][j] = 6;
            }
            if(i < 5   && j> 9){
                Application::matriz[i][j] = 1;
            }
        }
    }
}
/**
 *
 */
void Application::imprimirMatriz(){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 15; ++j) {
            std::cout << Application::matriz[i][j] <<" ";
        }
        std::cout << std::endl;
    }
}
/**
 * Limpia las marcas de dejan los soldados
 */
void Application::resetMatriz() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 15; ++j) {
            if(Application::matriz[i][j] == 3 || Application::matriz[i][j] == 4){
                Application::matriz[i][j] = 1;
            }
        }
    }

}
/**
 * Metodo que se debe llamar cuando no
 *  se hayan matado todos los enemigos
 * @param nivel
 */
void Application::subirNivel(int nivel) {
    this->nivel = nivel;
    initMatriz();
    resetMatriz();
}


Application::~Application() {
}