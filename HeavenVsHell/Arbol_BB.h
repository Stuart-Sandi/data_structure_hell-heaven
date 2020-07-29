#ifndef ARBOL_BB_H
#define ARBOL_BB_H
#include <QtMath>
#include <Nodo_Arbol.h>
#include <ListaDoble_Personas.h>


struct Arbol_BB{
    int contador;
    ListaDoble_Personas * lMundo;
    QList <Persona*> lMundoArbol;
    QList <Nodo_Arbol*> listaSalvacion;
    Nodo_Arbol * raiz;
    QString nombre;
    bool hc;
    Arbol_BB(){
        contador = 0;
        lMundo = nullptr;
        raiz = nullptr;
        hc = false;
    }
    Arbol_BB(Nodo_Arbol *_raiz){
        contador = 0;
        lMundo = nullptr;
        raiz = _raiz;
        hc = false;
    }

    //Funciones del arbol AVL
    Nodo_Arbol *rotacionII(Nodo_Arbol*, Nodo_Arbol*);
    Nodo_Arbol *rotacionDD(Nodo_Arbol*, Nodo_Arbol*);
    Nodo_Arbol *rotacionDI(Nodo_Arbol*, Nodo_Arbol*);
    Nodo_Arbol *rotacionID(Nodo_Arbol*, Nodo_Arbol*);
    Nodo_Arbol *insertarAVL(Nodo_Arbol*,Persona*);
    Nodo_Arbol *insertarPersona(Persona*); //esta funcion es para mayor comodidad

    int mayor(int, int);//calcula el mayor de los numeros que recibe como parametro
    int altura(Nodo_Arbol*);//calcular la altura del arbol
    int cantidadNodosActual();//retorna el numero de nodos en un arbol
    int cuantos(Nodo_Arbol*);//calcula el numero de nodos de un arbol

    void imprimirArbol(Nodo_Arbol*,int); //imprime
    void mostrarArbol();
    void crearArbolBB(int );
    void asignarPadre(Nodo_Arbol*);
    void inOrder(Nodo_Arbol*);
    void limpiar();
};

#endif // ARBOL_BB_H
