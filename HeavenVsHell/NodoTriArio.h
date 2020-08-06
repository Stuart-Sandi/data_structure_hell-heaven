#ifndef NODOTRIARIO_H
#define NODOTRIARIO_H

#include <Angel.h>
#include <Persona.h>

class NodoTriArio
{
public:

    Angel * angel; //Informacion del Nodo
    Persona * persona; // Informacion de la persona

    QList<NodoTriArio*> hijos;
    NodoTriArio(Angel* angel){

        this->angel = angel;
        this->persona = NULL;
    }

};

#endif // NODOTRIARIO_H
