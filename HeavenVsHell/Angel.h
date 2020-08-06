#ifndef ANGEL_H
#define ANGEL_H


#include <QString>

class Angel
{
public:

    QString nombre;
    int version;
    QString generacion;
    Angel(){
        this->nombre = "";
        this->version = 0;
        this->generacion = "";
    };
    Angel(QString pNombre, int pVersion, QString pGeneracion){

        this->nombre = pNombre;
        this->version = pVersion;
        this->generacion = pGeneracion;

    }

};

#endif // ANGEL_H
