

#include <cstdlib>
#include <string>

#include <allegro5/allegro_image.h>
#include "src/pantalla/Aplicacion.h"

int main(int argc, char** argv) {

    std::string Title = "League Of Gems";
    Application* oApp = new Application(1300, 700, Title);

    oApp->initApp();


    oApp->mainLoop();
    delete oApp;

    return 0;
}

