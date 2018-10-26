//
// Created by christian on 22/10/18.
//
#pragma once

#include <string>
#include "allegro5/allegro.h"



class Application{
public:
    Application(unsigned int iWidth, unsigned int iHeight, std::string sName){

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

protected:
    ALLEGRO_DISPLAY *Display = NULL;
    unsigned int Width = 0;
    unsigned int Height = 0;
    std::string title;
    ALLEGRO_EVENT_QUEUE* EventQueue;
};
