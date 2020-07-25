#include "ListaPersonasDobleEnlazada.h"

void ListaPersonasDobleEnlazada::insertarAlInicio(Persona * pPersona){
    if (primerNodo == NULL){

     primerNodo = new Nodo(pPersona);
     ultimoNodo = primerNodo;

    }
    else{

     Nodo * nuevo = new Nodo(pPersona);
     nuevo->siguiente = primerNodo;
     primerNodo ->anterior = nuevo;
     primerNodo = nuevo;

    }
}

void ListaPersonasDobleEnlazada::insertarAlFinal(Persona * pPersona){

    if (primerNodo == NULL){

        primerNodo = new Nodo(pPersona);
        ultimoNodo = primerNodo;

    }

    else{

        Nodo *nuevo = new Nodo(pPersona);
        ultimoNodo->siguiente = nuevo;
        nuevo->anterior = ultimoNodo;
        ultimoNodo = nuevo;

    }
}

Nodo * ListaPersonasDobleEnlazada::buscarPersona(int pId){

        Nodo * tmp = this->primerNodo;
        while (tmp != NULL) {
            if (tmp->dato->id == pId){
                return tmp;
            }
            tmp = tmp->siguiente;
        }
        return NULL;

}

