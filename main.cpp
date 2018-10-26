#include <iostream>
#include <allegro5/allegro.h>
#include "src/pantalla/Screen.h"

ALLEGRO_DISPLAY *display;

int main(int argc, char **argv) {

    auto principal = new Screen();

    principal->iniciar();

    return 0;
}
