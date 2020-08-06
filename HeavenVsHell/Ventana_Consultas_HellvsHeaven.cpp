#include "Ventana_Consultas_HellvsHeaven.h"
#include "ui_Ventana_Consultas_HellvsHeaven.h"

Ventana_Consultas_HellvsHeaven::Ventana_Consultas_HellvsHeaven(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Consultas_HellvsHeaven)
{
    ui->setupUi(this);

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven: Consultas Hell vs Heaven");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(1200,550);
}

Ventana_Consultas_HellvsHeaven::~Ventana_Consultas_HellvsHeaven()
{
    delete ui;
}
