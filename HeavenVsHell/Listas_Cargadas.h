#ifndef LISTAS_CARGADAS_H
#define LISTAS_CARGADAS_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QList>
#include <Lugar.h>

struct Listas_Cargadas{

    QList <QString> nombres;
    QList <QString> apellidos;
    QList <QString> creencias;
    QList <QString> paises;
    QList <QString> profesiones;
    QList <Lugar*> paises2;
    QList <Lugar*> continetes;

    Listas_Cargadas();
    void CargarListas();
};

#endif // LISTAS_CARGADAS_H
