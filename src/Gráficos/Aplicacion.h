//
// Created by christian on 22/10/18.
//
#pragma once

#include <string>
#include "allegro5/allegro5.h"

class Application{
public:
    Application( int iWidth, int iHeight, std::string sName){

        this->Width = iWidth;
        this->Height = iHeight;
        this->title = sName;

        al_init();
        al_install_mouse();
        al_install_keyboard();
    };

    void initApp();
    virtual ~Application();
    virtual int mainLoop();
    void initMatriz();
    void imprimirMatriz();

protected:
    ALLEGRO_EVENT_QUEUE* EventQueue;
    ALLEGRO_TIMER *timer;
    bool start = false;
    int tempX, tempY;
    int x,y;

    /// Pantalla
    ALLEGRO_DISPLAY *Display = NULL;
    int Width = 0;
    int Height = 0;
    std::string title;
    int matriz[25][50];
};
