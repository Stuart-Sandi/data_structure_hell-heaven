#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H
#include <Persona.h>
#include <QDebug>

struct Nodo_Arbol{
    int fe; //factor de equilibrio

    Persona * humano; //Informacion del Nodo
    Nodo_Arbol * padre;
    Nodo_Arbol * hijo_izq; //Puntero a un nodoPersona
    Nodo_Arbol * hijo_der;   //Puntero a un nodoPersona

    Nodo_Arbol(){ //constructor
        fe = 0; //factor de equilibrio
        hijo_izq = hijo_der = nullptr;
        humano = nullptr;
        padre = nullptr;
    }

    Nodo_Arbol(Persona *_personaAct){
        fe = 0; //factor de equilibrio
        humano = _personaAct;
        hijo_izq = hijo_der = nullptr;
        padre = nullptr;
    }
    Nodo_Arbol(Persona *_personaAct, int vfe){
        humano = _personaAct;
        hijo_izq = hijo_der = nullptr;
        fe = vfe;
        padre = nullptr;
    }
    Nodo_Arbol(Nodo_Arbol * ramaIzdo,Persona *_personaAct, Nodo_Arbol* ramaDcho){
        humano = _personaAct;
        hijo_izq = ramaIzdo;
        hijo_der = ramaDcho;
        fe = 0;
        padre = nullptr;
    }
    Nodo_Arbol(Nodo_Arbol * ramaIzdo, int _fe, Persona *_personaAct,Nodo_Arbol * ramaDcho){
        humano = _personaAct;
        hijo_izq = ramaIzdo;
        hijo_der = ramaDcho;
        fe = _fe;
        padre = nullptr;
    }

    // operaciones de acceso
    Persona *valorNodo(){ return humano; }
    Nodo_Arbol* subarbolIzdo(){ return hijo_izq; }
    Nodo_Arbol* subarbolDcho(){ return hijo_der; }
    void nuevoValor(Persona *d){ humano = d; }
    void ramaIzdo(Nodo_Arbol* n){ hijo_izq = n; }
    void ramaDcho(Nodo_Arbol* n){ hijo_der = n; }
    void visitar(){ qDebug()<<humano->nombre;}
    void Pfe(int vfe) { fe = vfe;}
    int Ofe(){ return fe;}
};

#endif // NODO_ARBOL_H
