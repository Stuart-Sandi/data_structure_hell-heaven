#ifndef PERSONA_H
#define PERSONA_H

#include <QString>
#include <QList>

class Persona
{
public:

    //ENTEROS
    long int id;

    //STRINGS
    QString nombre;
    QString apellido;
    QString pais;
    QString creencia;
    QString profesion;
    QString correo;
    QString fechaHoraNacimiento;
    QString continente;

    //LISTAS
    int pecados[7] = {0,0,0,0,0,0,0};
    int buenasAcciones[7] = {0,0,0,0,0,0,0};
    QList <Persona> listaHijos;

    //BOOLEANOS
    bool isPadre;
    bool isHijo;

    //PERSONA
    Persona * padre;
    Persona * next;
    Persona * before;

    Persona();

    Persona(int pId, QString pNombre, QString pApellido, QString pPais, QString pCreencia, QString pProfesion, QString pCorreo, QString pFechaNacimiento, QString pContinente){

        //ENTEROS
        this->id = pId;
        this->continente = pContinente;

        //STRINGS
        this->nombre = pNombre;
        this->apellido = pApellido;
        this->pais = pPais;
        this->creencia = pCreencia;
        this->profesion = pProfesion;
        this->correo = pCorreo;
        this->fechaHoraNacimiento = pFechaNacimiento;

        //BOOLEANOS
        this->isPadre = false;
        this->isHijo = false;

        //PERSONA
        this->padre = NULL;
        this->next = NULL;
        this->before = NULL;
    }

};

#endif // PERSONA_H
