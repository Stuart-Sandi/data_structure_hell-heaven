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

void funcionesArchivos::sumarAcciones(ListaDoble_Personas * pListaPersonas, bool pAccionBuena){

    Persona * tmp = pListaPersonas->primerNodo;

    if (pAccionBuena) {// Si pAccionBuena es true agrega buenas acciones

        while (tmp != NULL) {

            for (int i = 0; i < 7; i++) {
                    tmp->buenasAcciones[i] += random(0, 100);
            }

            tmp = tmp->next;

        }

        obtenerTotalAcciones(pListaPersonas, true); //Calcula total de buenasAcciones y los asigna a cada persona

    } else { // Si pAccionBuena es false agrega pecados

        int numHeredado = 0;
        int numAleatorio = 0;

        while (tmp != NULL) {

            for (int i = 0; i < 7; i++) {

                    numAleatorio = random(0, 100); // Calcula el número aleatorio para asignar en los pecados
                    tmp->pecados[i] += numAleatorio;

                    //Empieza la herencia
                    if (!tmp->listaHijos.empty()){ //Si la lista de hijos del padre no está vacía

                        numHeredado = numAleatorio * 0.5; //Obtiene el 50% de los pecados

                        for(Persona * hijo : tmp->listaHijos){ //For que recorre a los hijos

                            hijo->pecados[i] += numHeredado; // Asigna el 50% de pecados del padre

                            if(!hijo->listaHijos.empty()){ //Si la lista de nietos del padre no está vacía

                                numHeredado = numAleatorio * 0.25; //Obtiene el 25% de los pecados

                                for(Persona * nieto : hijo->listaHijos){ //For que recorre a los nietos

                                    nieto->pecados[i] += numHeredado; // Asigna el 25% de pecados del padre

                                }

                            }

                        }
                    }

            }

            tmp = tmp->next;

        }
        obtenerTotalAcciones(pListaPersonas, false); //Calcula total de pecados y los asigna a cada persona

    }

}

void funcionesArchivos::obtenerTotalAcciones(ListaDoble_Personas * pListaPersonas, bool pAccionBuena){

    Persona * tmp = pListaPersonas->primerNodo;
    int acciones;

    if(pAccionBuena){ //Si pAccionBuena es true, suma el total de buenas acciones

        while (tmp != NULL) {
            acciones = 0;

            for (int i = 0; i < 7; i++) {
                    acciones += tmp->buenasAcciones[i];
            }

            tmp->totalBuenasAcciones = acciones;

            tmp = tmp->next;

        }

    } else { //Si pAccionBuena es true, suma el total de pecados

        while (tmp != NULL) {
            acciones = 0;

            for (int i = 0; i < 7; i++) {
                    acciones += tmp->pecados[i];
            }

            tmp->totalPecados = acciones;

            tmp = tmp->next;

        }

    }

    this->obtenerResta(pListaPersonas);//CALCULA LA RESTA DE LAS ACCIONES

}

void funcionesArchivos::obtenerResta(ListaDoble_Personas * pLista){

    Persona * tmp = pLista->primerNodo;

    while (tmp != NULL){

        for (int i = 0;i<7;i++) {
            tmp->restaPecados[i] = tmp->pecados[i]- tmp->buenasAcciones[i];
            tmp->restaBuenasAcciones[i] = tmp->buenasAcciones[i] - tmp->pecados[i];
        }
        tmp  = tmp->next;
    }
}

QString funcionesArchivos::obtenerFechaHoraActual(){
    /*
     *
     */
    QString fechaHoraExacta = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ap");
    return fechaHoraExacta;

}

QString funcionesArchivos::obtenerFechaActual(){
    /*
     *
     */
    QString fechaHoraExacta = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    return fechaHoraExacta;

}
