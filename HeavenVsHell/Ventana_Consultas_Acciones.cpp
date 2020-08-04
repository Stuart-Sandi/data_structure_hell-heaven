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
        this->ui->textBrowser->setText("TOP 10 PAISES MAS PECADORES:\n");
        this->ui->textBrowser_2->setText("TOP 5 PAISES MENOS PECADORES:\n");
    }else{
        this->ui->label_4->setText("ESTADO DE BUENAS ACCIONES DE UNA FAMILIA:");
        this->ui->textBrowser->setText("TOP 10 PAISES CON MAS BUENAS ACCIONES:\n");
        this->ui->textBrowser_2->setText("TOP 5 PAISES CON MENOS BUENAS ACCIONES:\n");
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
                    this->mensaje += "INFORMACION FAMILIA "+tmp->nombre+" "+tmp->apellido+"\n\n";
                    crearMensajeFamilias(tmp);
                    break;
                }
                tmp = tmp->next;
            }

            if (validar == 0){
                msgBox.setText("No se encontro el ID solicitado");
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
    msgBox.setText("Debe ingresar un ID valido.");
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
    this->setVisible(false);
}
