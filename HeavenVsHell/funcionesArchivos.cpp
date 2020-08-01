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

QList<Persona*> funcionesArchivos::listaOrdenada(QList<Persona*> pLista){
    /*
     *
     */
    QList<Persona*> lista = pLista;
    int x = lista.size();
    for (int i = 0; i<x; i++){
        int min = i;
        for (int j = i+1; j<x; j++){
            if(lista[j]->id<lista[min]->id){
                min = j;
            }
        }
        lista.swapItemsAt(min, i);
    }
    return lista;
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
