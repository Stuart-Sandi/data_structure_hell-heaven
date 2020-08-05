#ifndef ANGEL_H
#define ANGEL_H


#include <QString>
#include <Persona.h>


class Angel
{
public:

    QString nombre;
    QString version;
    int generacion;
    Persona * humano;
    Angel();
    Angel(QString pNombre, QString pVersion, QString, int pGeneracion){

        this->nombre = pNombre;
        this->version = pVersion;
        this->generacion = pGeneracion;
        this->humano = NULL;

    }

};

#endif // ANGEL_H
