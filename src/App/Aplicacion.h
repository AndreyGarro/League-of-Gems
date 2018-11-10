#pragma once

#include <string>
#include "allegro5/allegro5.h"

class Application{
public:
    Application( int iWidth, int iHeight, std::string sName){

        this->Width = iWidth;
        this->Height = iHeight;
        this->title = sName;
    };

    void initApp();
    virtual ~Application();
    virtual int mainLoop();
    void initMatriz();
    void imprimirMatriz();
    void resetMatriz();

    // 2 enemigo, 3 soldado, 0 obstaculo, 1 espacio libre
    static int matriz[10][15];

private:
    ALLEGRO_EVENT_QUEUE* EventQueue;
    ALLEGRO_TIMER *timer;
    bool start = false;
    int x,y;
    ALLEGRO_EVENT oEvent;

    /// Pantalla
    ALLEGRO_DISPLAY *Display = NULL;
    int Width = 0;
    int Height = 0;
    std::string title;
    int iFPS;
    ALLEGRO_BITMAP *fondo;
};

