#ifndef DATA_H
#define DATA_H

#include <Listas_Cargadas.h>
#include <ListaDoble_Personas.h>
#include <Arbol_BB.h>
#include <ArbolTriArio.h>
#include <funcionesArchivos.h>
#include <QList>
#include <Lugar.h>

struct Data{
    Arbol_BB * arbol;
    ArbolTriArio * arbolTriArio;
    funcionesArchivos * fA;
    Listas_Cargadas * listasCargadas;
    ListaDoble_Personas * lPersonas;
    QList <Persona*> listaPersonasTMP;
    QList<Lugar*> continentes;
    QList<Lugar*> paises;

    QString nombreContinentes[5] = {"África","América","Asia","Europa","Oceanía"};
    QString nombreDemonios[7] = {"Asmodeo", "Belfegor", "Mammón", "Abadón", "Satán", "Belcebú", "Lucifer"};
    QString nombrePecados[8] = {"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
    QString nombreBuenasAcciones[8] = {"Castidad","Ayuno","Donación","Diligencia","Calma","Solidaridad","Humildad"};
    QString nombreAngeles[10] = {"Miguel",  "Nuriel",  "Aniel",  "Rafael",  "Gabriel", "Shamsiel",  "Raguel",  "Uriel",  "Azrael",  "Sariel"};
    QHash <int, QList<Persona*>> demonios;



    QList<Persona*> infierno;
    QHash <int, QList<Persona*>> cielo;


    Data(){
       this->arbol = new Arbol_BB();
       this->arbolTriArio = new ArbolTriArio();
       this->fA = new funcionesArchivos();
       this->listasCargadas = new Listas_Cargadas();
       this->paises = this->listasCargadas->paises2;
       this->continentes = this->listasCargadas->continetes;
       this->lPersonas = new ListaDoble_Personas(this->listasCargadas);
    }
};

#endif // DATA_H
