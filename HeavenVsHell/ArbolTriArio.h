#ifndef ARBOLTRIARIO_H
#define ARBOLTRIARIO_H

#include <NodoTriArio.h>
#include <funcionesArchivos.h>
#include <QtMath>

class ArbolTriArio
{
public:

    int nivelActual;
    int version;

    QString nombreAngeles[10] = {"Miguel",  "Nuriel",  "Aniel",  "Rafael",  "Gabriel", "Shamsiel",  "Raguel",  "Uriel",  "Azrael",  "Sariel"};
    NodoTriArio * raiz;
    funcionesArchivos * fA;

    ArbolTriArio(){
        this->version = 1;
        this->nivelActual = 2;
        this->fA = new funcionesArchivos();
        this->raiz = NULL;
        this->insertarEnArbolTriArioPrede();
    };
    void insertarEnArbolTriArioPrede();
    void insertarEnArbolTriArio(NodoTriArio*);

};

#endif // ARBOLTRIARIO_H
