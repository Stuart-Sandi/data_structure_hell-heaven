#include "Arbol_BB.h"

void Arbol_BB::crearArbolBB(int x){
    //CALCULA LA POTENCIA DE DOS NECESARIA PARA CREEARLO BALANCEADO
    contador += x;
    x = contador;
    float dato = (x*0.01);
    x = (int)dato;
    //qDebug()<<"El valor a buscar"<<x;
    int c = 0;
    int cantidadArbol = 0;
    while (true){
        int d = qPow(2,c);
        if (d>x){
            cantidadArbol = d;
            break;
        }
        c++;
    }
    cantidadArbol = cantidadArbol-1;

    //CREA LA LISTA CON LA CANTIDAD DE ELEMENTOS DEL ARBOL
    QList <Persona*> temporal;
    int tArbol = temporal.size();
    qDebug()<<"Arbol inicial"+QString::number(cantidadArbol);
    Persona * tmp = this->lMundo->primerNodo;
    for (int x = 0; x<cantidadArbol; x++){
        temporal.append(tmp);
        tmp = tmp->next;
    }

    //ASIGNA LA RAIZ AL ARBOL
    tArbol = temporal.size();
    for (int y = 0;y<tArbol; y++){
        raiz = insertarAVL(raiz,temporal[y]);
    }
}
//Hay que implementar la insercion


/* Descripcion: Hace una rotacion 2 al arbol avl
 * Entradas: Dos punteros al nodo de la persona
 * Salidas: Un puntero a un nodo del arbol avl
 * Restricciones:
 */
Nodo_Arbol *Arbol_BB::rotacionII(Nodo_Arbol *n, Nodo_Arbol *n1){
    n->ramaIzdo(n1->subarbolDcho());
    n1->ramaDcho(n);
    //actualizacion de los factores de equilibrio
    if(n1->Ofe() == -1){//la condicion es true en la insercion
        n->Pfe(0);
        n1->Pfe(0);
    }else{
        n->Pfe(-1);
        n1->Pfe(1);
    }
    return n1;
}


/* Descripcion: Hace doble rotacion a la derecha
 * Entradas: 2 punteros a un nodo del avl
 * Salidas: Un puntero del nodo del arbol
 * Restricciones: Se le deben pasar los 2 punteros
 */
Nodo_Arbol *Arbol_BB::rotacionDD(Nodo_Arbol *n, Nodo_Arbol *n1){
    n->ramaDcho(n1->subarbolIzdo());
    n1->ramaIzdo(n);
    if(n1->Ofe() == +1){
        n->Pfe(0);
        n1->Pfe(0);
    }else{
        n->Pfe(+1);
        n->Pfe(-1);
    }
    return n1;
}


/* Descripcion: Hace la rotacion doble a la izquierda
 * Entradas: 2 punteros del arbol avl
 * Salidas: Un puntero de un nodo del arbol
 * Restricciones: Se le deben pasar 2 punteros de tipo avl
 */
Nodo_Arbol *Arbol_BB::rotacionDI(Nodo_Arbol *n, Nodo_Arbol *n1){
    Nodo_Arbol *n2;
    n2 = n1->subarbolIzdo();
    n->ramaDcho(n2->subarbolIzdo());
    n2->ramaIzdo(n);
    n1->ramaIzdo(n2->subarbolDcho());
    n2->ramaDcho(n1);
    //actualizacion de factores de equilibrio
    if(n2->Ofe() == +1)
       n->Pfe(-1);
    else
       n->Pfe(0);
    if(n2->Ofe() == -1)
       n1->Pfe(+1);
    else
       n1->Pfe(0);
    n2->Pfe(0);
    return n2;
}

/* Descripcion: Hace la rotacion de izquierda a derecha
 * Entradas: Recibe 2 punteros a un nodo del arbol
 * Salidas: Un puntero a un arbol avl
 * Restricciones: Se le deben introducir 2 punteros
 */
Nodo_Arbol *Arbol_BB::rotacionID(Nodo_Arbol *n, Nodo_Arbol *n1){
    Nodo_Arbol *n2;
    n2 = n1->subarbolDcho();
    n->ramaIzdo(n2->subarbolDcho());
    n2->ramaDcho(n);
    n1->ramaDcho(n2->subarbolIzdo());
    n2->ramaIzdo(n1);
    //actualizacion de factores de equilibrio
    if(n2->Ofe() == +1)
        n1->Pfe(-1);
    else
        n1->Pfe(0);
    if(n2->Ofe() == -1)
        n->Pfe(1);
    else
        n->Pfe(0);
    n2->Pfe(0);
    return n2;
}

/* Descripcion: Indice cual es el mayor entre 2 numeros
 * Entradas: 2 numeros int
 * Salidas: El numero mayor
 * Restricciones: Deben ser int
 */
int Arbol_BB::mayor(int num1, int num2){
    return (num1 > num2 ? num1 : num2);
}

/* Descripcion: Sirve para ver la altura de un arbol avl
 * Entradas: La raiz del arbol para ver la altura
 * Salidas:  Un numero int, la altura del arbol
 * Restricciones: Se debe pasar un puntero a la raiz
 */
int Arbol_BB::altura(Nodo_Arbol *_raiz){
    //decide la altura de un árbol
    if(_raiz != nullptr){
        return mayor(altura(_raiz->subarbolIzdo()),altura(_raiz->subarbolDcho())) + 1;
    }else {
        return 0;
    }
}

/* Descripcion: Muestra la cantidad de nodos actuales en el arbol
 * Entradas: Ninguna
 * Salidas: El valor int de la cantidad de nodos
 * Restricciones:
 */
int Arbol_BB::cantidadNodosActual(){//calcula el numero de nodos en un arbol
    return cuantos(raiz);
}

/* Descripcion: Retorna la cantida de nodos
 * Entradas: La raiz del arbol que se quiere ver
 * Salidas: El valor int de la cantidad de nodos
 * Restricciones:
 */
int Arbol_BB::cuantos(Nodo_Arbol *_raiz){
    if(_raiz != nullptr){
        int cuantosIzquierda, cuantosDerecha;
        cuantosIzquierda = cuantos(_raiz->subarbolIzdo());
        cuantosDerecha = cuantos(_raiz->subarbolDcho());
        return cuantosIzquierda + cuantosDerecha + 1;
    }else{
        return 0;
    }
}

/* Descripcion: Imprime en consola los nodos de un arbol
 * Entradas: Ninguna
 * Salidas: Ninguna
 * Restricciones: El arbol debe de existir
 */
void Arbol_BB::mostrarArbol(){
    imprimirArbol(raiz,1);
}

/* Descripcion: Imprime el arbol
 * Entradas: un puntero a la raiz del arbol y la altura a donde se quiere imprimir
 * Salidas: No tiene, solo muestra en consola el arbol
 * Restricciones: Ninguna
 */
void Arbol_BB::imprimirArbol(Nodo_Arbol *_raiz, int altura){
    if(_raiz != nullptr){
        imprimirArbol(_raiz->subarbolDcho(),altura + 1);
        for(int i = 1; i <= altura; i++)
        qDebug() <<"  ";
        qDebug() << _raiz->valorNodo()->id;
        imprimirArbol(_raiz->subarbolIzdo(), altura + 1);
    }
}

/* Descripcion: Inserta una persona al arbol avl
 * Entradas: El puntero a la persona
 * Salidas: El puntero de la raiz del arbol
 * Restricciones: Ninguna
 */
Nodo_Arbol *Arbol_BB::insertarPersona(Persona *dt){
    hc = false;
    return insertarAVL(raiz,dt);
}


/* Descripcion: Reconstruye el arbol avl
 * Entradas: Recibe un puntero a la raiz del arbol y un puntero a un nodo de persona
 * Salidas: Un nodo de persona
 * Restricciones: Ninguna
 */
Nodo_Arbol *Arbol_BB::insertarAVL(Nodo_Arbol *_raiz, Persona *dt){
    Nodo_Arbol *n1;
    if(_raiz == nullptr){
        _raiz = new Nodo_Arbol(dt);
        hc = true;
    }else if(dt->id < _raiz->valorNodo()->id){
        Nodo_Arbol * iz = insertarAVL(_raiz->subarbolIzdo(),dt);
        _raiz->ramaIzdo(iz);

        //regreso por los nodos del camino de busqueda
        if(hc){//siempre comprueba si crecio en altura
        //decrementa el fe por aumentar la altura de la rama izquierda
            switch(_raiz->Ofe()){
                case 1: //tenia +1 y crecio su izquierda
                    _raiz->Pfe(0);
                    hc = false;//arbol deja de crecer
                    break;
                case 0: //tenia 0 y crecio a su izquierda
                    _raiz->Pfe(-1);//arbol sigue creciendo
                    break;
                case -1://aplicar rotacion a la izquierda
                    n1 = _raiz->subarbolIzdo();
                    if (n1->Ofe() == -1)
                        _raiz = rotacionII(_raiz, n1);
                    else
                        _raiz = rotacionID(_raiz, n1);
                    hc = false; // árbol deja de crecer en ambas rotaciones
            }
        }
    }else if(dt->id > _raiz->valorNodo()->id){
        Nodo_Arbol *dr = insertarAVL(_raiz->subarbolDcho(),dt);
        _raiz->ramaDcho(dr);
        //regreso por los nodos del camino de busqueda
        if(hc){//siempre se comprueba si crecio en altura
            switch(_raiz->Ofe()){
                case 1:
                    n1 = _raiz->subarbolDcho();
                    if(n1->Ofe() == +1)
                        _raiz = rotacionDD(_raiz, n1);
                    else
                        _raiz = rotacionDI(_raiz, n1);
                    hc = false; //arbol deja de crecer en ambas rotaciones
                    break;
                case 0: //tenia 0 y crecio a su derecha
                    _raiz->Pfe(+1); //arbol sigue creciendo
                    break;
                case -1:
                    _raiz->Pfe(0);
                    hc = false;
            }
        }
    }
    else if(dt->id == _raiz->valorNodo()->id){
        qDebug() << "No puede haber claves repetidas";
        hc = false;
    }
    return _raiz;
}

void Arbol_BB::asignarPadre(Nodo_Arbol * _raiz){
    if (_raiz != nullptr){
        asignarPadre(_raiz->hijo_izq);
        asignarPadre(_raiz->hijo_der);
        if (_raiz->hijo_der != nullptr && _raiz->hijo_izq != nullptr){
            Nodo_Arbol * tmp2 = new Nodo_Arbol();
            tmp2 = _raiz;
            _raiz->hijo_der->padre = tmp2;
            _raiz->hijo_izq->padre = tmp2;
        }
    }
}

void Arbol_BB::inOrder(Nodo_Arbol * nodo){
    if (nodo != nullptr){
        inOrder(nodo->hijo_izq);
        listaSalvacion.append(nodo);
        inOrder(nodo->hijo_der);
    }
}

void Arbol_BB::limpiar(){
    int x = listaSalvacion.size();
    for (int i = 0; i<x ;i++){
        listaSalvacion.removeOne(listaSalvacion[0]);
    }
    qDebug()<<"Vacio de lista: "<<listaSalvacion.size();
}
