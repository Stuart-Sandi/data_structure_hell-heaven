#ifndef PERSONA_H
#define PERSONA_H

#include <QString>
#include <ListaPersonasDobleEnlazada.h>

class Persona
{
public:

    int id;
    QString nombre;
    QString apellido;
    QString pais;
    QString creencia;
    QString profesion;
    QString correo;
    QString fechaHoraNacimiento;
    int pecados[7] = {0,0,0,0,0,0,0};
    int buenasAcciones[7] = {0,0,0,0,0,0,0};
    ListaPersonasDobleEnlazada * listaHijos;
    Persona * padre;
    bool isPadre;

    Persona();

    Persona(int pId, QString pNombre, QString pApellido, QString pPais, QString pCreencia, QString pProfesion, QString pCorreo, QString pFechaNacimiento, Persona * pPadre){

        this->id = pId;
        this->nombre = pNombre;
        this->apellido = pApellido;
        this->pais = pPais;
        this->creencia = pCreencia;
        this->profesion = pProfesion;
        this->correo = pCorreo;
        this->fechaHoraNacimiento = pFechaNacimiento;
        this->listaHijos = new ListaPersonasDobleEnlazada();
        this->padre = pPadre;
        this->isPadre = false;
    }

};

#endif // PERSONA_H
