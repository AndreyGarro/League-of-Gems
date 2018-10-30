

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


//
//#include "../LOG/src/LineaVista/LineaVista.h"
//#include <iostream>
//
//int main() {
//    Cola<int > rutaX;
//    Cola<int > rutaY;
//    LineaVista a ;
//    a.lineaVista(0,2,5,7, &rutaX, &rutaY);
//
//}