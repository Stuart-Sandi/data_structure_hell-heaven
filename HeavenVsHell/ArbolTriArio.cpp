#include "ArbolTriArio.h"


void ArbolTriArio::insertarEnArbolTriArioPrede(){

    Angel * a1 = new Angel();a1->nombre = "DIOS";
    Angel * a2 = new Angel();a2->nombre = "SERAFINES";
    Angel * a3 = new Angel();a3->nombre = "QUERUBINES";
    Angel * a4 = new Angel();a4->nombre = "TRONOS";
    this->raiz = new NodoTriArio(a1);
    this->raiz->hijos.append(new NodoTriArio(a2));
    this->raiz->hijos.append(new NodoTriArio(a3));
    this->raiz->hijos.append(new NodoTriArio(a4));
}

void ArbolTriArio::insertarEnArbolTriArio(NodoTriArio * tmp){

    if (tmp->hijos.size() != 0){

        for (int i = 0; i<3; i++) {
            insertarEnArbolTriArio(tmp->hijos[i]);
        }

    }else{
        for (int i = 0;i<3;i++) {
            int random = this->fA->random(0,6);
            Angel * a = new Angel();
            a->nombre = this->nombreAngeles[random];
            a->version = this->version;
            a->generacion = "G"+QString::number(this->nivelActual);


            if (this->version == qPow(3,this->nivelActual)){
                this->version = 1;
            }else{
                this->version +=1;
            }
        }
    }
    return;
}
