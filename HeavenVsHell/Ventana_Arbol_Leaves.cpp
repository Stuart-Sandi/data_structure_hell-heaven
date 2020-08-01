#include "Ventana_Arbol_Leaves.h"
#include "ui_Ventana_Arbol_Leaves.h"

Ventana_Arbol_Leaves::Ventana_Arbol_Leaves(QWidget *parent, Data * pDatos) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Arbol_Leaves)
{
    ui->setupUi(this);

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven: Tree Leaves's Information");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(740,530);

    this->datos = pDatos;
}

Ventana_Arbol_Leaves::~Ventana_Arbol_Leaves()
{
    delete ui;
}

void Ventana_Arbol_Leaves::on_pushButton_2_clicked()
{
    this->setVisible(false);
}

void Ventana_Arbol_Leaves::on_pushButton_3_clicked()
{
    this->datos->arbol->infoHojas = "";
    this->datos->arbol->inOrderHojas(this->datos->arbol->raiz);
    this->ui->textBrowser->setText(this->datos->arbol->infoHojas);
}
