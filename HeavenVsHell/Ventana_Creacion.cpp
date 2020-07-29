#include "Ventana_Creacion.h"
#include "ui_Ventana_Creacion.h"

Ventana_Creacion::Ventana_Creacion(QWidget *parent, Data * pDatos) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Creacion)
{
    ui->setupUi(this);

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven: Generate World");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(740,530);

    this->validar = 0;
    this->datos = pDatos;
}

Ventana_Creacion::~Ventana_Creacion()
{
    delete ui;
}

void Ventana_Creacion::on_pushButton_clicked()
{
    int x = ui->lineEdit->text().toInt();
    if (x>0){
        if (validar == 1 || x>=100){
            validar = 1;
            //GENERA EL MUNDO Y LE ASIGNA FAMILIA
            this->datos->lPersonas->generarMundo(x);
            this->datos->lPersonas->agregarFamilia();

            //GENERA EL ARBOL DESDE 0
            this->datos->arbol->raiz = nullptr;
            this->datos->arbol->lMundo = this->datos->lPersonas;
            this->datos->arbol->lMundoArbol = this->datos->lPersonas->listaTMP;
            this->datos->arbol->crearArbolBB(x);
            this->datos->arbol->asignarPadre(this->datos->arbol->raiz);

            QMessageBox msgBox;
            msgBox.setText(QString::number(x)+" humans generated");
            msgBox.setWindowTitle("Error");
            msgBox.exec();

//            Persona * tmp = this->datos->lPersonas->primerNodo;
//            while(tmp != NULL){
//                qDebug()<<"IDs: "+QString::number(tmp->id);
//                tmp = tmp->next;
//            }

        }
        else{
            QMessageBox msgBox;
            msgBox.setText("Solo se pueden generar un minimo de 100 personas en la primera ronda");
            msgBox.setWindowTitle("Error");
            msgBox.exec();
        }
    }else{
        QMessageBox msgBox;
        msgBox.setText("Debe ingresar solo caracteres numericos mayores a 0");
        msgBox.setWindowTitle("Error");
        msgBox.exec();
    }

}

void Ventana_Creacion::on_pushButton_2_clicked()
{
    this->setVisible(false);
}
