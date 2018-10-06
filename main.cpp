#include <iostream>
#include <allegro5/allegro.h>

ALLEGRO_DISPLAY *display;

int main(int argc, char **argv) {

    al_init();

    display = al_create_display(640, 480);
    al_clear_to_color(al_map_rgb_f(0,0,0));
    al_flip_display();
    al_rest(5.0);
    al_destroy_display(display);
    return 0;
}

