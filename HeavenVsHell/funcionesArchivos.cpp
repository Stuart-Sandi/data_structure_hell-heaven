#include "funcionesArchivos.h"
#include <QRandomGenerator>

int funcionesArchivos::random(int x, int y){
    /*
     *
     */
    std::uniform_int_distribution<int>d4(x,y);
    int dato = d4(*QRandomGenerator::global());
    return dato;
}

void funcionesArchivos::sumarAcciones(QList <Persona*> pListaPersonas, bool pAccionBuena){

    if (pAccionBuena) {

        for (Persona * persona  : pListaPersonas) {

            for (int i = 0; i < 7; i++) {
                    persona->buenasAcciones[i] = random(0, 100);
            }
        }

    } else {

        for (Persona * persona  : pListaPersonas) {

            for (int i = 0; i < 7; i++) {

                    persona->pecados[i] = random(0, 100);
            }
        }
    }
}
