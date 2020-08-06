#ifndef NODOTRIARIO_H
#define NODOTRIARIO_H

#include <Angel.h>

class NodoTriArio
{
public:

    Angel * angel; //Informacion del Nodo

    NodoTriArio * hijo_izq; //Puntero a un nodoPersona
    NodoTriArio * hijo_centro;   //Puntero a un nodoPersona
    NodoTriArio * hijo_der;   //Puntero a un nodoPersona

    NodoTriArio(){

        this->angel = NULL;
        this->hijo_izq = NULL;
        this->hijo_centro = NULL;
        this->hijo_der = NULL;

    }

    void insertar(Angel*);

};

#endif // NODOTRIARIO_H
