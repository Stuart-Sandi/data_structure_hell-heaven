#ifndef DATA_H
#define DATA_H

#include <Listas_Cargadas.h>
#include <ListaDoble_Personas.h>

struct Data{
    Listas_Cargadas * listasCargadas;
    ListaDoble_Personas * lPersonas;
    Data(){
       this->listasCargadas = new Listas_Cargadas();
       this->lPersonas = new ListaDoble_Personas(this->listasCargadas);
    }
};

#endif // DATA_H
