#include "Listas_Cargadas.h"

Listas_Cargadas::Listas_Cargadas()
{
    this->CargarListas();
}

void Listas_Cargadas::CargarListas(){
//###########################FUNCIONES ENCARGADAS DE CARGAR LOS DATOS DE LOS ARCHIVOS#######################

    /*
     * Funcion encargada de asignar los nombres a la lista de nombres
    */
    {
        QFile names("../HeavenVsHell/Listas/Nombres.txt");
        if (!names.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug()<<"No se pudo leer Nombres";
            return;
        }
        QTextStream in(&names);
        while (!in.atEnd()) {
             QString line = in.readLine();
             nombres.append(line);
        }
    }

    /*
     * Funcion encargada de asignar los apellidos a las lista de apellidos
    */
    {
        QFile file("../HeavenVsHell/Listas/Apellidos.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug()<<"No se pudo leer Apellidos";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
             QString line = in.readLine();
             apellidos.append(line);
        }
    }
    /*
     * Funcion encargada de asignar los paises a la lista de paises
    */
    {
        QFile file("../HeavenVsHell/Listas/Paises.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug()<<"No se pudo leer Paises";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
             QString line = in.readLine();
             paises.append(line);
        }
    }
    /*
     * Funcion encargada de asignar las creencias a la lista de creencias
    */
    {
        QFile file("../HeavenVsHell/Listas/Creencias.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug()<<"No se pudo leer Creencias";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
             QString line = in.readLine();
             creencias.append(line);
        }
    }
    /*
     * Funcion encargada de asignar las profesiones a la lista de profesiones
    */
    {
        QFile file("../HeavenVsHell/Listas/Profesiones.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug()<<"No se pudo leer Profesiones";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
             QString line = in.readLine();
             profesiones.append(line);
        }
    }

    {
    /*
     * Funcion encargada de asignar los paises y continentes a las listas de paises y continentes
    */
        int tama = this->paises.size();
        Lugar * tmp;

        for (int i = 0; i<tama ;i++) {
            tmp = new Lugar(this->paises[i]);
            this->paises2.append(tmp);
        }

        tmp =  new Lugar("America");
        this->continetes.append(tmp);
        tmp =  new Lugar("Africa");
        this->continetes.append(tmp);
        tmp =  new Lugar("Europa");
        this->continetes.append(tmp);
        tmp =  new Lugar("Asia");
        this->continetes.append(tmp);
        tmp =  new Lugar("Oceania");
        this->continetes.append(tmp);
    }

}
