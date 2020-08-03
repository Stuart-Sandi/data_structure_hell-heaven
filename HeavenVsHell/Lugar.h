#ifndef LUGAR_H
#define LUGAR_H

#include <QString>

struct Lugar
{

    QString nombre;
    int totalPecados;

    Lugar(QString pNombre, int pTotalPEcados){
        this->nombre = pNombre;
        this->totalPecados = pTotalPEcados;
    }

};

#endif // LUGAR_H
