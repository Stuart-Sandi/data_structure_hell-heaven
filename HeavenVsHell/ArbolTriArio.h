#ifndef ARBOLTRIARIO_H
#define ARBOLTRIARIO_H

#include <NodoTriArio.h>

class ArbolTriArio
{
public:

    NodoTriArio raiz;

    ArbolTriArio();

    ArbolTriArio(NodoTriArio pRaiz){

        this->raiz = pRaiz;

    }


};

#endif // ARBOLTRIARIO_H
