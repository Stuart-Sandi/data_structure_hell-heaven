#ifndef DATA_H
#define DATA_H

#include <Listas_Cargadas.h>

struct Data{
    Listas_Cargadas * listasCargadas;
    Data(){
       this->listasCargadas = new Listas_Cargadas();
    }
};

#endif // DATA_H
