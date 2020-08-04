#ifndef DATA_H
#define DATA_H

#include <Listas_Cargadas.h>
#include <ListaDoble_Personas.h>
#include <Arbol_BB.h>
#include <QList>
#include <Lugar.h>

struct Data{
    Arbol_BB * arbol;
    Listas_Cargadas * listasCargadas;
    ListaDoble_Personas * lPersonas;
    QList<Lugar*> continentes;
    QList<Lugar*> paises;


    Data(){
       this->arbol = new Arbol_BB();
       this->listasCargadas = new Listas_Cargadas();
       this->paises = this->listasCargadas->paises2;
       this->continentes = this->listasCargadas->continetes;
       this->lPersonas = new ListaDoble_Personas(this->listasCargadas);
    }
};

#endif // DATA_H
