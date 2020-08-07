#include "Ventana_Consultas_HellvsHeaven.h"
#include "ui_Ventana_Consultas_HellvsHeaven.h"

Ventana_Consultas_HellvsHeaven::Ventana_Consultas_HellvsHeaven(QWidget *parent, Data * pDatos) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Consultas_HellvsHeaven)
{
    ui->setupUi(this);

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven: Consultas Hell vs Heaven");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(1200,550);

    this->datos = pDatos;
    this->accion = 1;
    this->totalPecados = 0;
    this->totalBuenasAcciones = 0;

    this->ventana = new Ventana_MostrarCI(0,this->datos);

    this->rellernarComboBoxCategorias(0);
    this->rellernarComboBoxFamilias();
}

Ventana_Consultas_HellvsHeaven::~Ventana_Consultas_HellvsHeaven()
{
    delete ui;
}

void Ventana_Consultas_HellvsHeaven::on_pushButton_clicked()
{
    long int pecados[8] = {0,0,0,0,0,0,0,0};
    long int buenasAcciones[8] = {0,0,0,0,0,0,0,0};
    long int netoP = 0;
    long int netoBA = 0;

    QList<QLabel*> labelsP = {this->ui->lbl_p1,this->ui->lbl_p2,this->ui->lbl_p3,this->ui->lbl_p4,this->ui->lbl_p5,this->ui->lbl_p6,this->ui->lbl_p7,this->ui->lbl_totalP};
    QList<QLabel*> labelsbA = {this->ui->lbl_bA1,this->ui->lbl_bA2,this->ui->lbl_bA3,this->ui->lbl_bA4,this->ui->lbl_bA5,this->ui->lbl_bA6,this->ui->lbl_bA7,this->ui->lbl_totalBA};

    int tama = this->datos->infierno.size();

    for (int i = 0;i<tama;i++) {
        Persona * tmp = this->datos->infierno[i];

        for (int j = 0;j<7;j++) {
            pecados[j] += tmp->pecados[j];
            buenasAcciones[j] += tmp->buenasAcciones[j];
        }

        pecados[7] += tmp->totalPecados;
        buenasAcciones[7] += tmp->totalBuenasAcciones;
    }

    for (int i = 0;i<1000;i++) {

        QList <Persona*> listaTMP = this->datos->cielo.value(i);
        if (!listaTMP.isEmpty()){

            for (int k = 0;k<listaTMP.size();k++) {
                Persona * tmp = listaTMP[k];

                for (int j = 0;j<7;j++) {
                    pecados[j] += tmp->pecados[j];
                    buenasAcciones[j] += tmp->buenasAcciones[j];
                }

                pecados[7] += tmp->totalPecados;
                buenasAcciones[7] += tmp->totalBuenasAcciones;
            }
        }
    }

    //SETEO DE DATOS EN LBLS
    for (int i = 0;i<7;i++) {
        labelsP[i]->setText(this->datos->nombrePecados[i]+": "+QString::number(pecados[i]));
        labelsbA[i]->setText(this->datos->nombreBuenasAcciones[i]+": "+QString::number(buenasAcciones[i]));
    }
    labelsP[7]->setText("Total: "+QString::number(pecados[7]));
    labelsbA[7]->setText("Total: "+QString::number(buenasAcciones[7]));

    netoP = pecados[7] - buenasAcciones[7];
    netoBA = buenasAcciones[7] - pecados[7];

    this->ui->lbl_netoP->setText("Neto: "+QString::number(netoP));
    this->ui->lbl_netoBA->setText("Neto: "+QString::number(netoBA));

    if (netoP > netoBA){
        this->ui->lbl_win->setText("GANADOR: INFIERNO");
    }else{
        this->ui->lbl_win->setText("GANADOR: CIELO");
    }

}

void Ventana_Consultas_HellvsHeaven::on_comboBox_5_activated(int index)
{
    if (index == 0){
        this->accion = 1;
    }else{
        this->accion = 2;
    }
}

void Ventana_Consultas_HellvsHeaven::on_comboBox_activated(int index)
{
    rellernarComboBoxCategorias(index);
}

void Ventana_Consultas_HellvsHeaven::rellernarComboBoxCategorias(int x){

    this->ui->cb_opciones->clear();

    switch (x){

    case 0:
    {
        for (int  i = 0;i<this->datos->listasCargadas->apellidos.size();i++) {
            this->ui->cb_opciones->addItem(this->datos->listasCargadas->apellidos[i]);
        }

    }break;

    case 1:
    {
        for (int  i = 0;i<5;i++) {
            this->ui->cb_opciones->addItem(this->datos->nombreContinentes[i]);
        }

    }break;

    case 2:
    {
        for (int  i = 0;i<this->datos->listasCargadas->paises.size();i++) {
            this->ui->cb_opciones->addItem(this->datos->listasCargadas->paises[i]);
        }

    }break;

    case 3:
    {
        for (int  i = 0;i<this->datos->listasCargadas->creencias.size();i++) {
            this->ui->cb_opciones->addItem(this->datos->listasCargadas->creencias[i]);
        }

    }break;

    case 4:
    {
        for (int  i = 0;i<this->datos->listasCargadas->profesiones.size();i++) {
            this->ui->cb_opciones->addItem(this->datos->listasCargadas->profesiones[i]);
        }

    }break;
    }
}

void Ventana_Consultas_HellvsHeaven::rellernarComboBoxFamilias(){

    for (int  i = 0;i<this->datos->listasCargadas->apellidos.size();i++) {
        this->ui->cb_apellidos->addItem(this->datos->listasCargadas->apellidos[i]);
    }

    for (int  i = 0;i<this->datos->listasCargadas->paises.size();i++) {
        this->ui->cb_paises->addItem(this->datos->listasCargadas->paises[i]);
    }

}

void Ventana_Consultas_HellvsHeaven::on_pushButton_6_clicked()
{
    this->setVisible(false);
}

void Ventana_Consultas_HellvsHeaven::on_pushButton_2_clicked()
{
    this->ui->textBrowser->setText("");
    QList <Persona*> mundoTMP = this->datos->lPersonas->listaTMP;
    hallarTotalAcciones(mundoTMP);
    mundoTMP = ordenarMundo(this->accion,mundoTMP);
    QString mensaje = "";
    QString dato = this->ui->cb_opciones->currentText();

    mensaje += "Total Pecados: "+QString::number(this->totalPecados)+"\nTotal Buenas Acciones: "+QString::number(this->totalBuenasAcciones)+"\n\n";
    switch (this->ui->comboBox->currentIndex()) {

    case 0:
    {
        for (int  i = 0;i<mundoTMP.size();i++) {

            if (mundoTMP[i]->apellido == dato){
                mensaje += agregarDatos(mundoTMP[i]);
            }
        }

    }break;

    case 1:
    {
        switch (this->ui->cb_opciones->currentIndex()) {

        case 0:
            dato = "Africa";
            break;
        case 1:
            dato = "America";
            break;
        case 4:
            dato = "Oceania";
            break;
        }

        for (int  i = 0;i<mundoTMP.size();i++) {

            if (mundoTMP[i]->continente == dato){
                mensaje += agregarDatos(mundoTMP[i]);
            }
        }

    }break;

    case 2:
    {
        for (int  i = 0;i<mundoTMP.size();i++) {

            if (mundoTMP[i]->pais == dato){
                mensaje += agregarDatos(mundoTMP[i]);
            }
        }

    }break;

    case 3:
    {
        for (int  i = 0;i<mundoTMP.size();i++) {

            if (mundoTMP[i]->creencia == dato){
                mensaje += agregarDatos(mundoTMP[i]);
            }
        }

    }break;

    case 4:
    {
        for (int  i = 0;i<mundoTMP.size();i++) {

            if (mundoTMP[i]->profesion == dato){
                mensaje += agregarDatos(mundoTMP[i]);
            }
        }

    }break;
    }

    this->ui->textBrowser->setText(mensaje);
}

QList<Persona*> Ventana_Consultas_HellvsHeaven::ordenarMundo(int accion, QList<Persona*> lista){

    int x = lista.size();
    for (int i = 0; i<x; i++){
        int min = i;
        for (int j = i+1; j<x; j++){

            if (accion == 1){
                if(lista[j]->totalBuenasAcciones>lista[min]->totalBuenasAcciones){
                    min = j;
                }
            }else{
                if(lista[j]->totalPecados>lista[min]->totalPecados){
                    min = j;
                }
            }
        }
        lista.swapItemsAt(min, i);
    }
    return lista;
}

QString Ventana_Consultas_HellvsHeaven::agregarDatos(Persona * humano){
    QString mensaje = "";
    double total = 0;

    mensaje += "****************************************************\n";
    mensaje += "Id: "+QString::number(humano->id)+'\n';
    mensaje += "Nombre: "+humano->nombre+'\n';
    mensaje += "Apellido: "+humano->apellido+'\n';
    mensaje += "País: "+humano->pais+'\n';
    mensaje += "Creencia: "+humano->creencia+'\n';
    mensaje += "Ocupación: "+humano->profesion+'\n';
    mensaje += "Correo: "+humano->correo+'\n';
    mensaje += "Continente: "+humano->continente+'\n';
    mensaje += "Fecha nacimiento: "+humano->fechaHoraNacimiento+"\n\n";

    //TOTAL PECADOS
    mensaje += "Total Pecados: " + QString::number(humano->totalPecados) +"\n";
    total = ((double)humano->totalPecados/this->totalPecados)*100;
    mensaje += "Porcentaje que representa en el mundo: "+QString::number(total)+" %"+"\n\n";

    //TOTAL BUENAS ACCIONES
    mensaje += "Total Buenas Acciones: " + QString::number(humano->totalBuenasAcciones) +"\n";
    total = ((double)humano->totalBuenasAcciones/this->totalBuenasAcciones)*100;
    mensaje += "Porcentaje que representa en el mundo: "+QString::number(total)+" %"+"\n\n";

    if (!humano->listaHijos.isEmpty()){
        mensaje += "Hijos: [";
        for (int i = 0;i<humano->listaHijos.size();i++) {
            if (i != (humano->listaHijos.size()-1)){
                mensaje += QString::number(humano->listaHijos[i]->id)+", ";
            }
            else{
                mensaje += QString::number(humano->listaHijos[i]->id)+"]";
            }

        }
    }

    mensaje += "\n\n";
    return mensaje;
}

void Ventana_Consultas_HellvsHeaven::hallarTotalAcciones(QList<Persona*> lista){

    this->totalPecados = 0;
    this->totalBuenasAcciones = 0;

    for (int i = 0;i<lista.size();i++) {
        this->totalPecados += lista[i]->totalPecados;
        this->totalBuenasAcciones += lista[i]->totalBuenasAcciones;
    }

}

void Ventana_Consultas_HellvsHeaven::on_pushButton_3_clicked()
{
    QList<Persona*> listaTMP;
    QList<Persona*> listaFamilia;
    this->vivos = 0;
    this->infierno = 0;
    this->cielo = 0;

    listaFamilia = this->datos->lPersonas->familias.value(this->ui->cb_apellidos->currentText());

    if (!listaFamilia.isEmpty()){

        int validar = 0;
        for (int i = 0;i<listaFamilia.size();i++) {
            if (listaFamilia[i]->pais == this->ui->cb_paises->currentText()){
                listaTMP.append(listaFamilia[i]);
                validar = 1;
            }
        }

        if (validar == 0){
            QMessageBox msgBox;
            msgBox.setText("No existen personas en el mundo con el apellido y país seleccionado.");
            msgBox.setWindowTitle("Error");
            msgBox.setIcon(msgBox.Critical);
            msgBox.exec();
            return;
        }

        listaTMP = ordenarMundo(this->accion, listaTMP);
        QString mensaje = "";
        for (int i = 0;i<listaTMP.size();i++) {
            if (listaTMP[i]->inWorld){
                this->vivos++;
            }else if(listaTMP[i]->inHell){
                this->infierno++;
            }else{
                this->cielo++;
            }
            mensaje += agregarDatosFamilia(listaTMP[i]);
        }
        mensaje += "\n\n";
        mensaje += "Cantidad de familiares: "+QString::number(this->vivos+this->infierno+this->cielo)+"\n";
        mensaje += "Porcentaje familia viva: "+QString::number((double)(this->vivos*100)/listaTMP.size())+" %\n";
        mensaje += "Porcentaje familia en el Infierno: "+QString::number((double)(this->infierno*100)/listaTMP.size())+" %\n";
        mensaje += "Porcentaje familia en el Cielo: "+QString::number((double)(this->cielo*100)/listaTMP.size())+" %\n";

        this->ui->textBrowser_2->setText(mensaje);

    }else{
        QMessageBox msgBox;
        msgBox.setText("No existen personas en el mundo con el apellido seleccionado.");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(msgBox.Critical);
        msgBox.exec();
    }


}

QString Ventana_Consultas_HellvsHeaven::agregarDatosFamilia(Persona * humano){
    QString mensaje = "";

    mensaje += "****************************************************\n";
    mensaje += "Id: "+QString::number(humano->id)+'\n';
    mensaje += "Nombre: "+humano->nombre+'\n';
    mensaje += "Apellido: "+humano->apellido+'\n';
    mensaje += "País: "+humano->pais+'\n';
    mensaje += "Creencia: "+humano->creencia+'\n';
    mensaje += "Ocupación: "+humano->profesion+'\n';
    mensaje += "Correo: "+humano->correo+'\n';
    mensaje += "Continente: "+humano->continente+'\n';
    mensaje += "Fecha nacimiento: "+humano->fechaHoraNacimiento+"\n";
    mensaje += "Ubicación:";

    if (humano->inWorld){
        mensaje +=" Mundo\n\n";
    }else if (humano->inHell){
        mensaje +=" Infierno\n\n";
    }else{
        mensaje +=" Cielo\n\n";
    }

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

    if (!humano->listaHijos.isEmpty()){
        mensaje += "Hijos: \n";
        for (int i = 0;i<humano->listaHijos.size();i++) {
            mensaje += "////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
            mensaje += "Id: "+QString::number(humano->listaHijos[i]->id)+'\n';
            mensaje += "Nombre: "+humano->listaHijos[i]->nombre+'\n';
            mensaje += "Apellido: "+humano->listaHijos[i]->apellido+'\n';
            mensaje += "País: "+humano->listaHijos[i]->pais+'\n';
            mensaje += "Creencia: "+humano->listaHijos[i]->creencia+'\n';
            mensaje += "Ocupación: "+humano->listaHijos[i]->profesion+'\n';
            mensaje += "Correo: "+humano->listaHijos[i]->correo+'\n';
            mensaje += "Continente: "+humano->listaHijos[i]->continente+'\n';
            mensaje += "Fecha nacimiento: "+humano->listaHijos[i]->fechaHoraNacimiento+"\n";
            mensaje += "Ubicación:";

            if (humano->listaHijos[i]->inWorld){
                mensaje +=" Mundo\n\n";
            }else if (humano->listaHijos[i]->inHell){
                mensaje +=" Infierno\n\n";
            }else{
                mensaje +=" Cielo\n\n";
            }

            mensaje += "[Lujuria: "+QString::number(humano->listaHijos[i]->pecados[0])+", ";
            mensaje += "Gula: "+QString::number(humano->listaHijos[i]->pecados[1])+", ";
            mensaje += "Avaricia: "+QString::number(humano->listaHijos[i]->pecados[2])+", ";
            mensaje += "Pereza: "+QString::number(humano->listaHijos[i]->pecados[3])+", ";
            mensaje += "Ira: "+QString::number(humano->listaHijos[i]->pecados[4])+", ";
            mensaje += "Envidia: "+QString::number(humano->listaHijos[i]->pecados[5])+", ";
            mensaje += "Soberbia: "+QString::number(humano->listaHijos[i]->pecados[6])+"]"+ " Total: " + QString::number(humano->listaHijos[i]->totalPecados) +"\n\n";

            mensaje += "[Castidad: "+QString::number(humano->listaHijos[i]->buenasAcciones[0])+", ";
            mensaje += "Ayuno: "+QString::number(humano->listaHijos[i]->buenasAcciones[1])+", ";
            mensaje += "Donación: "+QString::number(humano->listaHijos[i]->buenasAcciones[2])+", ";
            mensaje += "Diligencia: "+QString::number(humano->listaHijos[i]->buenasAcciones[3])+", ";
            mensaje += "Calma: "+QString::number(humano->listaHijos[i]->buenasAcciones[4])+", ";
            mensaje += "Solidaridad: "+QString::number(humano->listaHijos[i]->buenasAcciones[5])+", ";
            mensaje += "Humildad: "+QString::number(humano->listaHijos[i]->buenasAcciones[6])+"]"+ " Total: " + QString::number(humano->totalBuenasAcciones) +"\n\n";

        }
        mensaje += "\n\n";
    }

    return mensaje;
}

void Ventana_Consultas_HellvsHeaven::on_pushButton_4_clicked()
{
    this->ventana->setVisible(true);
}
