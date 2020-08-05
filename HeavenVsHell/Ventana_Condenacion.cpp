#include "Ventana_Condenacion.h"
#include "ui_Ventana_Condenacion.h"

Ventana_Condenacion::Ventana_Condenacion(QWidget *parent, Data * pDatos) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Condenacion)
{
    ui->setupUi(this);

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven: Arbol: Condenacion");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(740,530);

    this->datos = pDatos;
    this->fA = new funcionesArchivos();

    //ASIGNA LA IMAGEN Y EL PECADO POR DEFECTO
    QPixmap pix("../HeavenVsHell/Listas/asmodeo.jpg");
    this->ui->label_3->setPixmap(pix);
    this->ui->label_4->setText("LUJURIA");
    this->ui->label_4->setAlignment(Qt::AlignCenter);

    //CARGA HASH DE DEMONIOS
    for (int i = 0; i < 7 ; i++) {

        QList<Persona*> tmp;

        this->datos->demonios.insert(i, tmp);

    }
}

Ventana_Condenacion::~Ventana_Condenacion()
{
    delete ui;
}

void Ventana_Condenacion::on_comboBox_activated(int index)
{
    this->actualizarDemonio(index);
    QList<Persona*> tmp = this->datos->demonios.value(index);
    this->calcularDatos(tmp);
}

void Ventana_Condenacion::actualizarDemonio(int index){
    QString pecados[7] = {"LUJURIA", "GULA",  "AVARICIA",  "PEREZA" ,  "IRA" , "ENVIDIA" , "SOBERBIA"};
    switch (index){

        case 0:
            {
            QPixmap pix("../HeavenVsHell/Listas/asmodeo.jpg");
            this->ui->label_3->setPixmap(pix);
            }
            break;

        case 1:
            {
            QPixmap pix("../HeavenVsHell/Listas/belfegor.jpg");
            this->ui->label_3->setPixmap(pix);
            }
            break;

        case 2:
            {
            QPixmap pix("../HeavenVsHell/Listas/mammon.jpg");
            this->ui->label_3->setPixmap(pix);
            }
            break;

        case 3:
            {
            QPixmap pix("../HeavenVsHell/Listas/abadon.jpg");
            this->ui->label_3->setPixmap(pix);
            }
            break;

        case 4:
            {
            QPixmap pix("../HeavenVsHell/Listas/satan.jpg");
            this->ui->label_3->setPixmap(pix);
            }
            break;

        case 5:
            {
            QPixmap pix("../HeavenVsHell/Listas/belcebu.jpg");
            this->ui->label_3->setPixmap(pix);
            }
            break;

        case 6:
            {
            QPixmap pix("../HeavenVsHell/Listas/lucifer.jpg");
            this->ui->label_3->setPixmap(pix);
            }
            break;

    }
    this->ui->label_4->setText(pecados[this->ui->comboBox->currentIndex()]);
}

void Ventana_Condenacion::on_pushButton_clicked()
{
    this->condenar();
}

QString Ventana_Condenacion::condenar(){

    QString data = "";
    int demonio = this->ui->comboBox->currentIndex();
    QList <Persona*> listaTmp = this->datos->lPersonas->listaTMP;
    listaTmp = ordenarListaPecados(demonio,listaTmp);

    int tama = listaTmp.size()* 0.05;
    int contador = 0;
    int index = 0;

    while (contador < tama){

        if (index < tama){
            if (listaTmp[index]->inHell == false && listaTmp[index]->inHeaven == false){
                listaTmp[index]->inHell = true;
                listaTmp[index]->inWorld = false;
                this->datos->infierno.append(listaTmp[index]);
                QList <Persona*> listaDemonio = this->datos->demonios.value(demonio);
                listaDemonio.append(listaTmp[index]);
                listaDemonio = ordenarListaPecados(demonio,listaDemonio);
                this->datos->demonios.insert(demonio,listaDemonio);
                contador++;
            }
            index++;

        }else{
            break;
        }

    }
    this->actualizarDemonio(demonio);
    QList <Persona*> listaDemonio = this->datos->demonios.value(demonio);
    this->calcularDatos(listaDemonio);

    return data;
}

void Ventana_Condenacion::calcularDatos(QList<Persona*> listaDemonio){

    if (listaDemonio.size() != 0){
        int demonio = this->ui->comboBox->currentIndex();
        double promedio = 0;
        int maximo = 0;
        int minimo = listaDemonio[0]->pecados[demonio];
        int cantHumanos = listaDemonio.size();
        QString mensaje = "";
        int contador = 1;

        for (Persona * p : listaDemonio) {
            promedio += p->pecados[demonio];
            if (p->pecados[demonio]>maximo){
                maximo = p->pecados[demonio];
            }

            if (p->pecados[demonio]<minimo){
                minimo = p->pecados[demonio];
            }

            mensaje += this->datosPersona(p,contador);
        }

        promedio = promedio/cantHumanos;

        this->ui->label_total->setText("TOTAL CONDENADOS: "+QString::number(cantHumanos));
        this->ui->label_promedio->setText("PROMEDIO: "+QString::number(promedio));
        this->ui->label_max->setText("MÁXIMO: "+QString::number(maximo));
        this->ui->label_min->setText("MÍNIMO: "+QString::number(minimo));
        this->ui->textBrowser->setText(mensaje);
    }

}

QString Ventana_Condenacion::datosPersona(Persona * humano, int cont){
    int demonio = this->ui->comboBox->currentIndex();
    QString mensaje;
//    QString log;
//    log += this->fA->obtenerFechaHoraActual()+"\n";
//    log += "Humano "+QString::number(cont)+tmp->nombre+" "+tmp->apellido+" "+tmp->pais+"\n";
//    log += "Murió el "+this->fA->obtenerFechaActual()+" condenado por "+QString::number(tmp->pecados[demonio])+" pecados de";


    mensaje += "***********************************************************\n";
    mensaje += "Id: "+QString::number(humano->id)+'\n';
    mensaje += "Nombre: "+humano->nombre+'\n';
    mensaje += "Apellido: "+humano->apellido+'\n';
    mensaje += "País: "+humano->pais+'\n';
    mensaje += "Creencia: "+humano->creencia+'\n';
    mensaje += "Ocupacion: "+humano->profesion+'\n';
    mensaje += "Fecha nacimiento: "+humano->fechaHoraNacimiento+"\n\n";
    mensaje += "Condenado por: "+this->datos->nombreDemonios[demonio];

    mensaje += "[Lujuria: "+QString::number(humano->pecados[0])+", ";
    mensaje += "Gula: "+QString::number(humano->pecados[1])+", ";
    mensaje += "Avaricia: "+QString::number(humano->pecados[2])+", ";
    mensaje += "Pereza: "+QString::number(humano->pecados[3])+", ";
    mensaje += "Ira: "+QString::number(humano->pecados[4])+", ";
    mensaje += "Envidia: "+QString::number(humano->pecados[5])+", ";
    mensaje += "Soberbia: "+QString::number(humano->pecados[6])+"]"+ " Total: " + QString::number(humano->totalPecados) +"\n\n";

    mensaje += "[Castidad: "+QString::number(humano->buenasAcciones[0])+", ";
    mensaje += "Ayuno: "+QString::number(humano->buenasAcciones[1])+", ";
    mensaje += "Donación: "+QString::number(humano->buenasAcciones[2])+", ";
    mensaje += "Diligencia: "+QString::number(humano->buenasAcciones[3])+", ";
    mensaje += "Calma: "+QString::number(humano->buenasAcciones[4])+", ";
    mensaje += "Solidaridad: "+QString::number(humano->buenasAcciones[5])+", ";
    mensaje += "Humildad: "+QString::number(humano->buenasAcciones[6])+"]"+ " Total: " + QString::number(humano->totalBuenasAcciones) +"\n\n";

    mensaje += "Hijos: [";
    for (int i = 0;i<humano->listaHijos.size();i++) {
        if (i != (humano->listaHijos.size()-1)){
            mensaje += QString::number(humano->listaHijos[i]->id)+", ";
        }
        else{
            mensaje += QString::number(humano->listaHijos[i]->id);
        }

    }
    mensaje += "]\n\n";
    return mensaje;
}

QList<Persona*> Ventana_Condenacion::ordenarListaPecados(int pecado, QList<Persona *> tmp){
    /*
     *
     */
    int x = tmp.size();
    for (int i = 0; i<x; i++){
        int min = i;
        for (int j = i+1; j<x; j++){
            if(tmp[j]->restaPecados[pecado]>tmp[min]->restaPecados[pecado]){
                min = j;
            }
        }
        tmp.swapItemsAt(min, i);
    }
    return tmp;
}

void Ventana_Condenacion::on_pushButton_2_clicked()
{
    this->setVisible(false);
}
