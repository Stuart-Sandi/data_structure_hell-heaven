#include "Ventana_MostrarCI.h"
#include "ui_Ventana_MostrarCI.h"

Ventana_MostrarCI::Ventana_MostrarCI(QWidget *parent, Data * pDatos) :
    QMainWindow(parent),
    ui(new Ui::Ventana_MostrarCI)
{
    ui->setupUi(this);

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven: Consultas Hell vs Heaven: Mostrar Cielo - Infierno");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(740,530);

    this->datos = pDatos;
}

Ventana_MostrarCI::~Ventana_MostrarCI()
{
    delete ui;
}

void Ventana_MostrarCI::on_pushButton_2_clicked()
{
    this->setVisible(false);
}

void Ventana_MostrarCI::on_pushButton_clicked()
{
    if (this->ui->comboBox->currentIndex() == 0){
        imprimirCielo();
    }else{
        imprimirInfierno();
    }
}

void Ventana_MostrarCI::imprimirCielo(){

    QString mensaje = "";

    for (int i = 0;i<1000;i++) {

        QList<Persona*> tmp = this->datos->cielo.value(i);
        if (!tmp.isEmpty()){
            for (int w = 0;w<tmp.size();w++) {
                mensaje += datosCielo(tmp[w]);
            }
        }
    }

    this->ui->textBrowser->setText(mensaje);
}

void Ventana_MostrarCI::imprimirInfierno(){

    QString mensaje = "";

    QList<Persona*> tmp = this->datos->infierno;
    for (int i = 0;i<tmp.size();i++) {
        mensaje += datosInfierno(tmp[i]);
    }

    this->ui->textBrowser->setText(mensaje);

}

QString Ventana_MostrarCI::datosCielo(Persona * humano){
    QString mensaje = "";
    mensaje += "*************************************************************************************************************\n";
    mensaje += "Id: "+QString::number(humano->id)+'\n';
    mensaje += "Nombre: "+humano->nombre+'\n';
    mensaje += "Apellido: "+humano->apellido+'\n';
    mensaje += "País: "+humano->pais+'\n';
    mensaje += "Creencia: "+humano->creencia+'\n';
    mensaje += "Ocupación: "+humano->profesion+'\n';
    mensaje += "Correo: "+humano->correo+'\n';
    mensaje += "Continente: "+humano->continente+'\n';
    mensaje += "Fecha nacimiento: "+humano->fechaHoraNacimiento+"\n";
    mensaje += "Salvado por el ángel: San "+humano->angel->nombre+"("+QString::number(humano->angel->version)+")"+" "+humano->angel->generacion+"\n\n";

    if (!humano->listaHijos.isEmpty()){
        mensaje += "\tHijos:\n";
        for (int z = 0;z<humano->listaHijos.size();z++) {

            if (z != (humano->listaHijos.size()-1)){
                mensaje += "\tId: "+QString::number(humano->listaHijos[z]->id)+", Nombre: "+humano->listaHijos[z]->nombre+" "+humano->listaHijos[z]->apellido+"\n";
            }
            else{
                mensaje += "\tId: "+QString::number(humano->listaHijos[z]->id)+", Nombre: "+humano->listaHijos[z]->nombre+" "+humano->listaHijos[z]->apellido;
            }

        }
    }

    mensaje += "\n\n";
    return mensaje;
}

QString Ventana_MostrarCI::datosInfierno(Persona * humano){
    QString mensaje = "";

    mensaje += "*************************************************************************************************************\n";
    mensaje += "Id: "+QString::number(humano->id)+'\n';
    mensaje += "Nombre: "+humano->nombre+'\n';
    mensaje += "Apellido: "+humano->apellido+'\n';
    mensaje += "País: "+humano->pais+'\n';
    mensaje += "Creencia: "+humano->creencia+'\n';
    mensaje += "Ocupación: "+humano->profesion+'\n';
    mensaje += "Correo: "+humano->correo+'\n';
    mensaje += "Continente: "+humano->continente+'\n';
    mensaje += "Fecha nacimiento: "+humano->fechaHoraNacimiento+"\n";
    mensaje += "Condenado por: "+humano->demonio+"\n\n";

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
