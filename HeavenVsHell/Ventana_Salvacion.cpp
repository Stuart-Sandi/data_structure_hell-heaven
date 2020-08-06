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
