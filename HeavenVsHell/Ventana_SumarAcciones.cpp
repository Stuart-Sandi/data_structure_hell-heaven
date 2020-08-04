#include "Ventana_SumarAcciones.h"
#include "ui_Ventana_SumarAcciones.h"

Ventana_SumarAcciones::Ventana_SumarAcciones(QWidget *parent, Data * pDatos) :
    QMainWindow(parent),
    ui(new Ui::Ventana_SumarAcciones)
{
    ui->setupUi(this);

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven: Añadir Acciones");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(740,530);

    this->datos = pDatos;
    this->vConsultas = new Ventana_Consultas_Acciones(0, this->datos);
}

Ventana_SumarAcciones::~Ventana_SumarAcciones()
{
    delete ui;
}

void Ventana_SumarAcciones::on_btn_BuenasAcciones_clicked()
{
    QMessageBox msgBox;
    fa->sumarAcciones(this->datos->lPersonas, true);
    msgBox.setText("Se agregaron buenas acciones con éxito.");
    msgBox.setWindowTitle("Información");
    msgBox.setIcon(msgBox.Information);
    msgBox.exec();
}

void Ventana_SumarAcciones::on_btn_Pecados_clicked()
{
    QMessageBox msgBox;
    fa->sumarAcciones(this->datos->lPersonas, false);
    msgBox.setText("Se agregaron pecados con éxito.");
    msgBox.setWindowTitle("Información");
    msgBox.setIcon(msgBox.Information);
    msgBox.exec();
}

void Ventana_SumarAcciones::on_btn_GoBack_clicked()
{
    this->setVisible(false);
}

void Ventana_SumarAcciones::on_btn_GoBack_2_clicked()
{
    this->vConsultas->setVisible(true);
}
