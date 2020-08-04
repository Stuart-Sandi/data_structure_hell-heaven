#ifndef LUGAR_H
#define LUGAR_H

#include <QString>

struct Lugar
{

    QString nombre;
    int totalPecados;
    int totalBuenasAcciones;

    Lugar(QString pNombre){
        this->nombre = pNombre;
        this->totalPecados = 0;
        this->totalBuenasAcciones = 0;
    }

};

#endif // LUGAR_H
