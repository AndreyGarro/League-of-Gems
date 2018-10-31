//
// Created by andrew on 30/10/18.
//

#ifndef LEAGUEOFGEMS_PLAYER_H
#define LEAGUEOFGEMS_PLAYER_H

#include <allegro5/allegro_primitives.h>


class Player {
private:
    int curFrame = 0;
    int frameCount = 0;
    int frameDelay = 5;

    ALLEGRO_BITMAP *image[12];

public:

    void caminaEste();
    void loadCaminaEste();
    void dibujaCaminaEste();
};


#endif //LEAGUEOFGEMS_PLAYER_H
