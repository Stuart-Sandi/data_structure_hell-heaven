#include "Ventana_Consultas_Acciones.h"
#include "ui_Ventana_Consultas_Acciones.h"

Ventana_Consultas_Acciones::Ventana_Consultas_Acciones(QWidget *parent, Data * pDatos) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Consultas_Acciones)
{
    ui->setupUi(this);

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven: Consultas Acciones");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(1100,550);

    this->datos = pDatos;
    this->mensaje = "";
}

Ventana_Consultas_Acciones::~Ventana_Consultas_Acciones()
{
    delete ui;
}

void Ventana_Consultas_Acciones::on_comboBox_activated(int index)
{
    if (index == 0){
        this->ui->label_4->setText("ESTADO DE PECADOS DE UNA FAMILIA");
        this->ui->textBrowser->setText("TOP 10 PAÍSES MÁS PECADORES:\n");
        this->ui->textBrowser_2->setText("TOP 5 PAÍSES MENOS PECADORES:\n");
    }else{
        this->ui->label_4->setText("ESTADO DE BUENAS ACCIONES DE UNA FAMILIA:");
        this->ui->textBrowser->setText("TOP 10 PAÍSES CON MÁS BUENAS ACCIONES:\n");
        this->ui->textBrowser_2->setText("TOP 5 PAÍSES CON MENOS BUENAS ACCIONES:\n");
    }
}

void Ventana_Consultas_Acciones::on_pushButton_4_clicked()
{
    this->ui->textBrowser_3->setText("");
    this->lista.clear();

    QMessageBox msgBox;
    QString dato = this->ui->lineEdit->text();

    if (dato != ""){

        long int id = dato.toInt();
        int validar = 0;

        if (id != 0){

            Persona * tmp = this->datos->lPersonas->primerNodo;
            while (tmp != NULL){
                if (tmp->id == id){
                    validar = 1;
                    this->mensaje += "INFORMACIÓN FAMILIA "+tmp->nombre+" "+tmp->apellido+"\n\n";
                    crearMensajeFamilias(tmp);
                    break;
                }
                tmp = tmp->next;
            }

            if (validar == 0){
                msgBox.setText("No se encontro el ID solicitado.");
                msgBox.setWindowTitle("Error");
                msgBox.setIcon(msgBox.Critical);
                msgBox.exec();
            }else{
                this->ui->textBrowser_3->setText(this->mensaje);
                this->mensaje = "";
            }
            return;
        }

    }
    msgBox.setText("Debe ingresar un ID válido.");
    msgBox.setWindowTitle("Error");
    msgBox.setIcon(msgBox.Critical);
    msgBox.exec();
}

void Ventana_Consultas_Acciones::crearMensajeFamilias(Persona * tmp){

    if (!this->lista.contains(tmp)){

        this->lista.append(tmp);
        this->mensaje += "Nombre: "+tmp->nombre+" "+tmp->apellido+" ID: "+QString::number(tmp->id)+'\n';
        this->mensaje += "Lista: \n";

        if (this->ui->comboBox->currentIndex() == 0){

            this->mensaje += "[Lujuria: "+QString::number(tmp->pecados[0])+", ";
            this->mensaje += "Gula: "+QString::number(tmp->pecados[1])+", ";
            this->mensaje += "Avaricia: "+QString::number(tmp->pecados[2])+", ";
            this->mensaje += "Pereza: "+QString::number(tmp->pecados[3])+", ";
            this->mensaje += "Ira: "+QString::number(tmp->pecados[4])+", ";
            this->mensaje += "Envidia: "+QString::number(tmp->pecados[5])+", ";
            this->mensaje += "Soberbia: "+QString::number(tmp->pecados[6])+"]"+"\n\n";

        }
        else{

            this->mensaje += "[Castidad: "+QString::number(tmp->buenasAcciones[0])+", ";
            this->mensaje += "Ayuno: "+QString::number(tmp->buenasAcciones[1])+", ";
            this->mensaje += "Donación: "+QString::number(tmp->buenasAcciones[2])+", ";
            this->mensaje += "Diligencia: "+QString::number(tmp->buenasAcciones[3])+", ";
            this->mensaje += "Calma: "+QString::number(tmp->buenasAcciones[4])+", ";
            this->mensaje += "Solidaridad: "+QString::number(tmp->buenasAcciones[5])+", ";
            this->mensaje += "Humildad: "+QString::number(tmp->buenasAcciones[6])+"]"+"\n\n";

        }

        if (tmp->listaHijos.size() != 0){

            for (int i = 0; i<tmp->listaHijos.size(); i++) {
                crearMensajeFamilias(tmp->listaHijos[i]);
            }

        }
    }
    return;
}

void Ventana_Consultas_Acciones::on_pushButton_5_clicked()
{
    //LIMPIA LOS DATOS DE LA PANTALLA
    this->ui->label_4->setText("ESTADO DE PECADOS DE UNA FAMILIA");
    this->ui->textBrowser->setText("TOP 10 PAÍSES MÁS PECADORES:\n");
    this->ui->textBrowser_2->setText("TOP 5 PAÍSES MENOS PECADORES:\n");
    this->ui->comboBox->setCurrentIndex(0);
    this->ui->lineEdit->setText("");
    this->ui->textBrowser_3->setText("");
    this->ui->america_label->clear();
    this->ui->europa_label->clear();
    this->ui->africa_label->clear();
    this->ui->asia_label->clear();
    this->ui->oceania_label->clear();


    this->setVisible(false);
}

void Ventana_Consultas_Acciones::limpiarListas(){
    int tama = this->datos->paises.size();

    for (int i = 0;i<tama;i++) {
        this->datos->paises[i]->totalPecados = 0;
        this->datos->paises[i]->totalBuenasAcciones = 0;
    }

    tama = this->datos->continentes.size();
    for (int i = 0;i<tama;i++) {
        this->datos->continentes[i]->totalPecados = 0;
        this->datos->continentes[i]->totalBuenasAcciones = 0;
    }

}

void Ventana_Consultas_Acciones::asignarAccionesAListas(){
    Persona * tmp = this->datos->lPersonas->primerNodo;
    while (tmp != NULL){

        int tama = this->datos->paises.size();
        for (int i = 0;i<tama;i++) {

            if(this->datos->paises[i]->nombre == tmp->pais){

                if (this->ui->comboBox->currentIndex() == 0){
                    this->datos->paises[i]->totalPecados += tmp->totalPecados;
                }else{
                    this->datos->paises[i]->totalBuenasAcciones += tmp->totalBuenasAcciones;
                }
                break;
            }
        }

        tama = this->datos->continentes.size();
        for (int i = 0;i<tama;i++) {

            if (this->datos->continentes[i]->nombre == tmp->continente){

                if (this->ui->comboBox->currentIndex() == 0){
                    this->datos->continentes[i]->totalPecados += tmp->totalPecados;
                }else{
                    this->datos->continentes[i]->totalBuenasAcciones += tmp->totalBuenasAcciones;
                }
                break;
            }
        }
        tmp = tmp->next;
    }
}

QList<Lugar*> Ventana_Consultas_Acciones::ordenarLista(QList<Lugar*> tmp){
    QList<Lugar*> modify = tmp;
    int x = modify.size();

    for (int i = 0; i<x; i++){
        int min = i;
        for (int j = i+1; j<x; j++){

            if (this->ui->comboBox->currentIndex() == 0){
                if(modify[j]->totalPecados<modify[min]->totalPecados){
                    min = j;
                }
            }else{
                if(modify[j]->totalBuenasAcciones<modify[min]->totalBuenasAcciones){
                    min = j;
                }
            }

        }
        modify.swapItemsAt(min, i);
    }
    return modify;
}

void Ventana_Consultas_Acciones::mostrarDatosPaises(){

    QString mensaje = "";
    if (this->ui->comboBox->currentIndex() == 0){
        this->ui->textBrowser->setText("TOP 10 PAÍSES MÁS PECADORES:\n");
        this->ui->textBrowser_2->setText("TOP 5 PAÍSES MENOS PECADORES:\n");
    }else{
        this->ui->textBrowser->setText("TOP 10 PAÍSES CON MÁS BUENAS ACCIONES:\n");
        this->ui->textBrowser_2->setText("TOP 5 PAÍSES CON MENOS BUENAS ACCIONES:\n");
    }
    int contador = 1;

    int tama = this->datos->paises.size()-11;
    for (int i = 24;i>tama;i--) {
        if (this->ui->comboBox->currentIndex() == 0){
            mensaje += QString::number(contador)+"/ "+this->datos->paises[i]->nombre+", Total: "+QString::number(this->datos->paises[i]->totalPecados)+"\n";
        }else{
            mensaje += QString::number(contador)+"/ "+this->datos->paises[i]->nombre+", Total: "+QString::number(this->datos->paises[i]->totalBuenasAcciones)+"\n";
        }
        contador++;
    }
    this->ui->textBrowser->append(mensaje);
    mensaje = "";

    contador = 1;
    for (int i = 0;i<5;i++) {
        if (this->ui->comboBox->currentIndex() == 0){
            mensaje += QString::number(contador)+"/ "+this->datos->paises[i]->nombre+", Total: "+QString::number(this->datos->paises[i]->totalPecados)+"\n";
        }else{
            mensaje += QString::number(contador)+"/ "+this->datos->paises[i]->nombre+", Total: "+QString::number(this->datos->paises[i]->totalBuenasAcciones)+"\n";
        }
        contador++;
    }
    this->ui->textBrowser_2->append(mensaje);
}

void Ventana_Consultas_Acciones::on_pushButton_6_clicked()
{
        qDebug()<<"tamano paises: "+QString::number(this->datos->paises.size());
        limpiarListas();
        asignarAccionesAListas();
        this->datos->paises = ordenarLista(this->datos->paises);
        this->datos->continentes = ordenarLista(this->datos->continentes);
        mostrarDatosPaises();
        mostrarDatosContinentes();

        for (int i = 0;i<this->datos->continentes.size();i++) {
            qDebug()<<this->datos->continentes[i]->nombre<<this->datos->continentes[i]->totalPecados;
            qDebug()<<this->datos->continentes[i]->nombre<<this->datos->continentes[i]->totalBuenasAcciones;
        }

}

void Ventana_Consultas_Acciones::mostrarDatosContinentes(){

    for (int i = 1;i<=this->datos->continentes.size();i++) {
        QString continente = this->datos->continentes[i-1]->nombre;
        QString datoNombre = continente+QString::number(i)+".png";
        QPixmap pix("../HeavenVsHell/Listas/"+datoNombre);

        if (continente == "America"){
            this->ui->america_label->setPixmap(pix);
        }else if (continente == "Europa"){
            this->ui->europa_label->setPixmap(pix);
        }else if (continente == "Africa"){
            this->ui->africa_label->setPixmap(pix);
        }else if (continente == "Asia"){
            this->ui->asia_label->setPixmap(pix);
        }else{
            this->ui->oceania_label->setPixmap(pix);
        }
    }
}
