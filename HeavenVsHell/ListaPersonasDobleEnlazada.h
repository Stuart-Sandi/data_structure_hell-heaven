#ifndef LISTAPERSONASDOBLEENLAZADA_H
#define LISTAPERSONASDOBLEENLAZADA_H

#include <Persona.h>

class Nodo
{
    public:
    Persona * dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo();

    Nodo(Persona * pPersona) {
      dato = pPersona;
      siguiente = anterior = NULL;
    }

};

class ListaPersonasDobleEnlazada
{
public:

    Nodo * primerNodo, * ultimoNodo;
    ListaPersonasDobleEnlazada(){
        primerNodo = ultimoNodo = NULL;
    }

    void insertarAlInicio(Persona *);
    void insertarAlFinal(Persona *);
    Nodo * buscarPersona(int);

};

#endif // LISTAPERSONASDOBLEENLAZADA_H
