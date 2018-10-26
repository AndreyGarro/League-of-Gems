//
// Created by andrew on 06/10/18.
//

#ifndef LEAGUEOFGEMS_SCREEN_H
#define LEAGUEOFGEMS_SCREEN_H
#include <allegro5/allegro.h>

#define screenWidth 800
#define screenHeight 600

class Screen {
    ALLEGRO_DISPLAY *display;
    volatile int closeWindow = false;
    const float fps = 60.0;
    void CloseButtonCallBack(){};

public:
    void iniciar();
};


#endif //LEAGUEOFGEMS_SCREEN_H
