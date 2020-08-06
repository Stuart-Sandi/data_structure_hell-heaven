#include "Ventana_Salvacion.h"
#include "ui_Ventana_Salvacion.h"

Ventana_Salvacion::Ventana_Salvacion(QWidget *parent, Data * pDatos) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Salvacion)
{
    ui->setupUi(this);

    this->datos = pDatos;

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven: Arbol: Salvacion");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(740,530);
}

Ventana_Salvacion::~Ventana_Salvacion()
{
    delete ui;
}

QList<Persona*> Ventana_Salvacion::ordenarInfierno(QList<Persona *> infierno){

    for (int i = 0;i<infierno.size();i++) {
        infierno[i]->restaAccionesPecados = infierno[i]->totalBuenasAcciones-infierno[i]->totalPecados;
    }

    int x = infierno.size();
    for (int i = 0; i<x; i++){
        int min = i;
        for (int j = i+1; j<x; j++){
            if(infierno[j]->restaAccionesPecados>infierno[min]->restaAccionesPecados){
                min = j;
            }
        }
        infierno.swapItemsAt(min, i);
    }

    return infierno;
}

void Ventana_Salvacion::insertarEnArbolTriArio(NodoTriArio * tmp){

    if (!tmp->hijos.isEmpty()){

        for (int i = 0; i<3; i++) {
            insertarEnArbolTriArio(tmp->hijos[i]);
        }

    }else{
        for (int i = 0;i<3;i++) {
            int random = this->datos->fA->random(0,6);
            Angel * a = new Angel();
            a->nombre = this->datos->nombreAngeles[random];
            a->version = this->datos->arbolTriArio->version;
            a->generacion = "G"+QString::number(this->datos->arbolTriArio->nivelActual);
            NodoTriArio * nodo = new NodoTriArio(a);

            Persona * p = this->datos->infierno[0];
            this->datos->infierno.removeFirst();
            p->angel = a;
            p->inHell = false;
            p->inHeaven = true;
            nodo->persona = p;
            int posicion = p->id%1000;

            QList <Persona*> bucket = this->datos->cielo.value(posicion);
            bucket.append(p);
            this->datos->cielo.insert(posicion,bucket);

            tmp->hijos.append(nodo);

            if (this->datos->arbolTriArio->version == qPow(3,this->datos->arbolTriArio->nivelActual)){
                this->datos->arbolTriArio->version = 1;
            }else{
                this->datos->arbolTriArio->version += 1;
            }
        }
    }
    return;
}

void Ventana_Salvacion::on_pushButton_clicked()
{
    if (this->datos->infierno.size()>= qPow(3,this->datos->arbolTriArio->nivelActual)){
        this->datos->infierno = this->ordenarInfierno(this->datos->infierno);
        this->insertarEnArbolTriArio(this->datos->arbolTriArio->raiz);
        this->datos->arbolTriArio->nivelActual++;
    }else{
        QMessageBox msgBox;
        msgBox.setText("No hay suficientes condenados en el infierno para salvar con la siguiente generación de ángeles.");
        msgBox.setIcon(msgBox.Critical);
        msgBox.setWindowTitle("Error");
        msgBox.exec();
    }
}

void Ventana_Salvacion::on_pushButton_2_clicked()
{
    this->setVisible(false);
}
