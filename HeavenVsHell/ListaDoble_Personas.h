#ifndef LISTAPERSONASDOBLEENLAZADA_H
#define LISTAPERSONASDOBLEENLAZADA_H

#include <Persona.h>
#include <qrandom.h>
#include <QHash>
#include <QList>
#include <QDateTime>
#include <Listas_Cargadas.h>

class ListaDoble_Personas
{
public:

    Persona * primerNodo, * ultimoNodo;
    Listas_Cargadas * lCargadas;
    QList<long int> identificaciones;
    QList<Persona*> listaTMP;
    QHash <QString,QList<Persona*>> familias;
    ListaDoble_Personas(Listas_Cargadas* pLCargadas){
        lCargadas = pLCargadas;
        primerNodo = ultimoNodo = NULL;
    }

    void generarMundo(int);
    int random(int,int);
    void insertarAlInicio(Persona *);
    void insertarAlFinal(Persona *);
    void listaOrdenada();
    void agregarFamilia();
    Persona * buscarPersona(int);
    QString obtenerFechaHoraActual();
    QString hallarContinente(int);

};

#endif // LISTAPERSONASDOBLEENLAZADA_H
