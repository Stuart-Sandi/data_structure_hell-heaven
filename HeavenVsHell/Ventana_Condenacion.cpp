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

void Ventana_Condenacion::condenar(){

    int demonio = this->ui->comboBox->currentIndex();
    QList <Persona*> listaTmp = this->datos->lPersonas->listaTMP;
    listaTmp = this->ordenarListaRestaPecados(demonio,listaTmp);

    int tama = listaTmp.size()* 0.05;
    qDebug()<<tama;
    int contador = 0;
    int index = 0;

    QList <Persona*> listaDemonio = this->datos->demonios.value(demonio);

    while (contador < tama){

        if (index < listaTmp.size()){

            if (listaTmp[index]->inHell == false && listaTmp[index]->inHeaven == false){

                listaTmp[index]->inHell = true;
                listaTmp[index]->inWorld = false;
                this->datos->infierno.append(listaTmp[index]);
                listaDemonio.append(listaTmp[index]);
                contador++;

            }
            index++;

        }else{
            break;
        }

    }

    listaDemonio = ordenarListaPecados(demonio,listaDemonio);
    this->actualizarDemonio(demonio);
    this->calcularDatos(listaDemonio);
    this->datos->demonios.insert(demonio,listaDemonio);
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
    }else{
        this->ui->label_total->setText("TOTAL CONDENADOS: ");
        this->ui->label_promedio->setText("PROMEDIO: ");
        this->ui->label_max->setText("MÁXIMO: ");
        this->ui->label_min->setText("MÍNIMO: ");
        this->ui->textBrowser->setText("");
    }

}

QString Ventana_Condenacion::datosPersona(Persona * humano, int cont){
    int demonio = this->ui->comboBox->currentIndex();
    QString mensaje;

    mensaje += "***********************************************************\n";
    mensaje += "Id: "+QString::number(humano->id)+'\n';
    mensaje += "Nombre: "+humano->nombre+'\n';
    mensaje += "Apellido: "+humano->apellido+'\n';
    mensaje += "País: "+humano->pais+'\n';
    mensaje += "Creencia: "+humano->creencia+'\n';
    mensaje += "Ocupacion: "+humano->profesion+'\n';
    mensaje += "Fecha nacimiento: "+humano->fechaHoraNacimiento+"\n";
    mensaje += "Condenado por: "+this->datos->nombreDemonios[demonio]+"\n\n";

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

QList<Persona*> Ventana_Condenacion::ordenarListaRestaPecados(int pecado, QList<Persona *> tmp){
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

QList<Persona*> Ventana_Condenacion::ordenarListaPecados(int pecado, QList<Persona *> tmp){
    /*
     *
     */
    int x = tmp.size();
    for (int i = 0; i<x; i++){
        int min = i;
        for (int j = i+1; j<x; j++){
            if(tmp[j]->pecados[pecado]>tmp[min]->pecados[pecado]){
                min = j;
            }
        }
        tmp.swapItemsAt(min, i);
    }
    return tmp;
}

void Ventana_Condenacion::log(){
    QString log = "";

    for (int i = 0; i<7; i++) {
        QList <Persona*> tmp = this->datos->demonios.value(i);

        if (tmp.size() != 0){
            log += "**********************************************************************************************************\n";
            log += "Demonio: "+this->datos->nombreDemonios[i]+"\n\n";
            int cont = 1;

            for (int j = 0;j<tmp.size();j++) {
                Persona * p = tmp[j];
                log += this->fA->obtenerFechaHoraActual()+"\t";
                log += "Humano "+QString::number(cont)+"  "+p->nombre+" "+p->apellido+" "+p->pais+"\n";
                log += "Murió el "+this->fA->obtenerFechaActual()+" condenado por "+QString::number(p->pecados[i])+" pecados de "+this->datos->nombrePecados[i]+" y "
                +QString::number(p->buenasAcciones[i])+" acciones de "+this->datos->nombreBuenasAcciones[i]+" por el demonio "+this->datos->nombreDemonios[i]+"\n\n";
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
        qDebug()<<mensaje;

        //ESTE ES EL METODO PARA CREAR LOS ARCHIVOS
        QString nombreArchivo = "../HeavenVsHell/Archivos_Condenacion/"+mensaje+".txt";

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

void Ventana_Condenacion::on_pushButton_2_clicked()
{
    this->setVisible(false);
}

void Ventana_Condenacion::sendMail(QString x)
{
    Smtp* smtp = new Smtp("prograhellvsheaven@gmail.com", "progra123", "smtp.gmail.com", 465);
    smtp->sendMail("prograhellvsheaven@gmail.com", "stuartsandi43@gmail.com" , "Reporte total de Condenaciones","Este es el reporte de todas las muertes causadas por los demonios del infierno", x );

}

void Ventana_Condenacion::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void Ventana_Condenacion::on_pushButton_3_clicked()
{
    this->log();
}
