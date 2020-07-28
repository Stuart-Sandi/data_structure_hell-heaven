#include "Ventana_SumarAcciones.h"
#include "ui_Ventana_SumarAcciones.h"

Ventana_SumarAcciones::Ventana_SumarAcciones(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_SumarAcciones)
{
    ui->setupUi(this);

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven: Add actions");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(740,530);
}

Ventana_SumarAcciones::~Ventana_SumarAcciones()
{
    delete ui;
}
