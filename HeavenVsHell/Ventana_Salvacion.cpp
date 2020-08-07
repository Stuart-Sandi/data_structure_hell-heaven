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
            a->generacion = "Generación "+QString::number(this->datos->arbolTriArio->nivelActual);
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
        this->mostrarCielo();
    }else{
        QMessageBox msgBox;
        msgBox.setText("No hay suficientes condenados en el infierno para salvar con la siguiente generación de ángeles.");
        msgBox.setIcon(msgBox.Critical);
        msgBox.setWindowTitle("Error");
        msgBox.exec();
    }
}

void Ventana_Salvacion::mostrarCielo(){

    QString mensaje = "";
    int cont = 0;
    for (int i = 0;i<1000;i++) {

        QList<Persona*> tmp = this->datos->cielo.value(i);
        if (!tmp.isEmpty()){
            cont += tmp.size();
            for (int w = 0;w<tmp.size();w++) {
                mensaje += "**************************************************************************************************************\n";
                mensaje += "Id: "+QString::number(tmp[w]->id)+'\n';
                mensaje += "Nombre: "+tmp[w]->nombre+'\n';
                mensaje += "Apellido: "+tmp[w]->apellido+'\n';
                mensaje += "País: "+tmp[w]->pais+'\n';
                mensaje += "Creencia: "+tmp[w]->creencia+'\n';
                mensaje += "Ocupación: "+tmp[w]->profesion+'\n';
                mensaje += "Correo: "+tmp[w]->correo+'\n';
                mensaje += "Continente: "+tmp[w]->continente+'\n';
                mensaje += "Fecha nacimiento: "+tmp[w]->fechaHoraNacimiento+"\n";
                mensaje += "Salvado por el ángel: San "+tmp[w]->angel->nombre+"("+QString::number(tmp[w]->angel->version)+")"+" "+tmp[w]->angel->generacion+"\n\n";

                if (!tmp[w]->listaHijos.isEmpty()){
                    mensaje += "\tHijos:\n";
                    for (int z = 0;z<tmp[w]->listaHijos.size();z++) {

                        if (z != (tmp[w]->listaHijos.size()-1)){
                            mensaje += "\tId: "+QString::number(tmp[w]->listaHijos[z]->id)+", Nombre: "+tmp[w]->listaHijos[z]->nombre+" "+tmp[w]->listaHijos[z]->apellido+"\n";
                        }
                        else{
                            mensaje += "\tId: "+QString::number(tmp[w]->listaHijos[z]->id)+", Nombre: "+tmp[w]->listaHijos[z]->nombre+" "+tmp[w]->listaHijos[z]->apellido;
                        }

                    }
                }

                mensaje += "\n\n";
            }
        }
    }
    this->ui->textBrowser->setText(mensaje);
    this->ui->label_total->setText("SALVADOS: "+QString::number(cont));
    this->ui->label_total_2->setText("GEN ACTUAL: "+QString::number(this->datos->arbolTriArio->nivelActual-1));
}

void Ventana_Salvacion::on_pushButton_2_clicked()
{
    this->setVisible(false);
}

void Ventana_Salvacion::on_pushButton_3_clicked()
{
    this->log();
}

void Ventana_Salvacion::log(){
    QString log = "";
    int cont = 1;

    for (int i = 0; i<1000; i++) {
        QList <Persona*> tmp = this->datos->cielo.value(i);

        if (tmp.size() != 0){

            for (int j = 0;j<tmp.size();j++) {
                log += "**********************************************************************************************************\n";

                Persona * p = tmp[j];
                log += this->datos->fA->obtenerFechaHoraActual()+"\t";
                log += "Humano "+QString::number(cont)+"  "+p->nombre+" "+p->apellido+" "+p->pais+"\n";
                log += "Salvado/a el "+this->datos->fA->obtenerFechaActual()+" por "+QString::number(p->totalPecados)+" pecados vs "+QString::number(p->totalBuenasAcciones)+
                " acciones buenas por el ángel San "+tmp[j]->angel->nombre+"("+QString::number(tmp[j]->angel->version)+")"+" "+tmp[j]->angel->generacion+".\n\n";
                cont++;
            }
        }

    }

    if (log != ""){
        //CREA EL FORMATO DEL NOMBRE DEL ARCHIVO
        int dia = QDate::currentDate().day();
        int anno = QDate::currentDate().year();
        int mes = QDate::currentDate().month();
        int hora = QTime::currentTime().hour();
        int segundo = QTime::currentTime().second();
        int min = QTime::currentTime().minute();
        QString mensaje = QString::number(anno)+QString::number(mes)+QString::number(dia)+"_"+QString::number(hora)+QString::number(min)+QString::number(segundo);

        //ESTE ES EL METODO PARA CREAR LOS ARCHIVOS
        QString nombreArchivo = "../HeavenVsHell/Archivos_Salvacion/"+mensaje+".txt";

        QFile archivo(nombreArchivo);

        if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream datosArchivo(&archivo);
            datosArchivo << log <<"\n";

        }
        archivo.close();
        sendMail(nombreArchivo);
        mailSent("Message sent");

    }else{
        QMessageBox msgBox;
        msgBox.setText("Debe condenar con algun demonio.");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(msgBox.Critical);
        msgBox.exec();
    }

}

void Ventana_Salvacion::sendMail(QString x)
{
    Smtp* smtp = new Smtp("prograhellvsheaven@gmail.com", "progra123", "smtp.gmail.com", 465);
    smtp->sendMail("prograhellvsheaven@gmail.com", "stuartsandi43@gmail.com" , "Reporte total de Salvaciones","Este es el reporte de todas las personas salvadas por los ángeles del cielo.", x );

}

void Ventana_Salvacion::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
