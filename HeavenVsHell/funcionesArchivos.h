#ifndef FUNCIONESARCHIVOS_H
#define FUNCIONESARCHIVOS_H

#include <QList>
#include <Persona.h>

class funcionesArchivos
{
public:
    funcionesArchivos(){}

    int random(int, int);
    void sumarAcciones(QList<Persona*>, bool);
    QList<Persona*> listaOrdenada(QList<Persona*>);

};

#endif // FUNCIONESARCHIVOS_H
