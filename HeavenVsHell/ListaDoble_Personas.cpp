#include "ListaDoble_Personas.h"

void ListaDoble_Personas::generarMundo(int cGenerar){

    //RESETEA LA LISTA DE PERSONAS PARA CREAR DE NUEVO EL ARBOL
    this->primerNodo = NULL;

    // DECLARACION DE VARIABLES DE USO TMP
    QString nombre, apellido, pais, creencia, profesion, correo, fHNacimiento, continente;
    QString correo2 = "@gmail.com";
    long int ide;

    //FOR ENCARGADO DE CREAR ALA CANTIDAD DE PERSONAS DADA
    for (int i=0; i<cGenerar; i++) {

        //GENERACION DE RANDOMS
        int iNombre = random(0,999);  int iApellido = random(0,199);
        int iPais = random(0,24);      int iCreencia = random(0,9);
        int iProfesion = random(0,49);

        //ASIGNACION DE DATOS ALEATORIOS A VARIABLES
        nombre = this->lCargadas->nombres[iNombre];
        apellido = this->lCargadas->apellidos[iApellido];
        pais = this->lCargadas->paises[iPais];
        creencia = this->lCargadas->creencias[iCreencia];
        profesion = this->lCargadas->profesiones[iProfesion];
        correo = (nombre+apellido)+correo2;
        fHNacimiento = this->obtenerFechaHoraActual();
        continente = this->hallarContinente(iPais);


        //GENERACION Y VALIDACION DEL ID UNICO
        while (true){
            std::uniform_int_distribution<long>d13(1000000,9999999);int iD = d13(*QRandomGenerator::global());
            ide = iD;
            if (!this->identificaciones.contains(ide)){
                break;
            }
        }
        this->identificaciones.append(ide);

        //CREA LA PERSONA CON LOS DATOS Y LA ASIGNA A LA LISTA TEMPORAL
        Persona * nuevo = new Persona(ide,nombre,apellido,pais,creencia,profesion,correo,fHNacimiento,continente);
        this->listaTMP.append(nuevo);

        //INGRESA EN EL HASH DE FAMILIAS
        if (!this->familias.contains(nuevo->apellido)){
            QList<Persona*> lista;
            lista.append(nuevo);
            this->familias.insert(nuevo->apellido, lista);
            //this->familias.take(nuevo->apellido).append(nuevo);
        }else{
            QList<Persona*> lista;
            lista = this->familias.take(nuevo->apellido);
            lista.append(nuevo);
            this->familias.insert(nuevo->apellido,lista);
        }
    }

    //ORDENA LA LISTA POR IDS DE MENOR A MAYOR
    this->listaOrdenada();

    //CREA LA LISTA PLANA DEL MUNDO
    for (int i = 0;i<this->listaTMP.size();i++) {
        this->insertarAlFinal(this->listaTMP[i]);
    }


}

void ListaDoble_Personas::insertarAlInicio(Persona * pPersona){
    /*
     *
     */
    if (primerNodo == NULL){
     primerNodo = ultimoNodo = pPersona;

    }
    else{

     pPersona->next = primerNodo;
     primerNodo->before = pPersona;
     primerNodo = pPersona;

    }
}

void ListaDoble_Personas::insertarAlFinal(Persona * pPersona){
    /*
     *
     */
    if (primerNodo == NULL){
        primerNodo = ultimoNodo = pPersona;

    }

    else{

        ultimoNodo->next = pPersona;
        pPersona->before = ultimoNodo;
        ultimoNodo = pPersona;

    }
}

Persona * ListaDoble_Personas::buscarPersona(int pId){
    /*
     *
     */
    Persona * tmp = this->primerNodo;
    while (tmp != NULL) {
        if (tmp->id == pId){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;

}

void ListaDoble_Personas::listaOrdenada(){
    /*
     *
     */
    int x = this->listaTMP.size();
    for (int i = 0; i<x; i++){
        int min = i;
        for (int j = i+1; j<x; j++){
            if(listaTMP[j]->id<listaTMP[min]->id){
                min = j;
            }
        }
        listaTMP.swap(min,i);
    }
}

void ListaDoble_Personas::agregarFamilia(){
    /*
     *
     */
    for (int i = 0;i<this->listaTMP.size();i++) {

        Persona * tmp = this->listaTMP[i];
        int cantHijos = random(0,5);
        QList <Persona*> tmpHijos = this->familias.value(tmp->apellido);

        //PREGUNTA SI YA ES PADRE
        if (!tmp->isPadre){
            //ASIGNA LA CANTIDAD ALEATORIA DE HIJOS
            for (int w = 0;w< cantHijos;w++) {
                //RECORRE LA LISTA DEL HASH DEL MISMO APELLIDO
                for (int j=0;j<tmpHijos.size();j++) {

                    Persona * tmp2 = tmpHijos[j];
                    //PREGUNTA SI ES LA MISMA PERSONA A LA QUE SE LE VA A ASIGNAR HIJOS
                    if (tmp != tmp2){
                        //PREGUNTA SI EL APELLIDO ES EL MISMO DE LA PERSONA QUE SE LE VA A AGREGAR HIJOS
                        if(tmp2->apellido == tmp->apellido){
                            //PREGUNTA SI EL PAIS ES EL MISMO DE LA PERSONA QUE SE LE VA A AGREGAR HIJOS
                            if(tmp2->pais == tmp->pais){
                                //PREGUNTA SI NO ES HIJO DE ALGUIEN
                                if (!tmp2->isHijo){
                                    //PREGUNTA SI EL FUTURO HIJO ES EL PADRE
                                    if (tmp->padre != tmp2){
                                        tmp->listaHijos.append(tmp2);
                                        tmp2->isHijo = true;
                                        tmp2->padre = tmp;
                                        tmp->isPadre = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }


    }
}

int ListaDoble_Personas::random(int x, int y){
    /*
     *
     */
    std::uniform_int_distribution<int>d4(x,y);
    int dato = d4(*QRandomGenerator::global());
    return dato;
}

QString ListaDoble_Personas::obtenerFechaHoraActual(){
    /*
     *
     */
    QString fechaHoraExacta = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ap");
    return fechaHoraExacta;

}

QString ListaDoble_Personas::hallarContinente(int x){
    /*
     *
     */
    QString continente;
    if (x<10){
        continente = "America";
    }else if(x<20){
        continente = "Europa";
    }else if(x<30){
        continente = "Asia";
    }else if(x<40){
        continente = "Africa";
    }else{
        continente = "Oceania";
    }
    return continente;
}

