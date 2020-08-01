#include "Ventana_Arbol.h"
#include "ui_Ventana_Arbol.h"

Ventana_Arbol::Ventana_Arbol(QWidget *parent, Data * pDatos) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Arbol)
{
    ui->setupUi(this);

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven: Tree");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(740,530);

    this->datos = pDatos;
    this->vLeaves = new Ventana_Arbol_Leaves(0, this->datos);

}

Ventana_Arbol::~Ventana_Arbol()
{
    delete ui;
}

void Ventana_Arbol::addPadre(){

    QTreeWidgetItem * tmp = new QTreeWidgetItem(ui->treeWidget);
    QString num = QString::number(datos->arbol->raiz->humano->id);
    tmp->setText(0,num);
    ui->treeWidget->addTopLevelItem(tmp);
    crearArbol(datos->arbol->raiz->hijo_der,tmp);
    crearArbol(datos->arbol->raiz->hijo_izq,tmp);

}

void Ventana_Arbol::crearArbol(Nodo_Arbol * raiz, QTreeWidgetItem * parent){
    QTreeWidgetItem * tmp = new QTreeWidgetItem();
    if (raiz == nullptr){
        return;
    }
    else{
        QString num = QString::number(raiz->humano->id);
        tmp->setText(0,num);

        parent->addChild(tmp);
        crearArbol(raiz->hijo_der,tmp);
        crearArbol(raiz->hijo_izq,tmp);
    }

}

void Ventana_Arbol::on_pushButton_clicked()
{
    ui->treeWidget->clear();
    ui->label_3->setText("LEVELS: "+QString::number(this->datos->arbol->altura(this->datos->arbol->raiz)-1));
    ui->label_4->setText("NODES: "+QString::number(this->datos->arbol->cantNodos));
    addPadre();
}

void Ventana_Arbol::on_pushButton_2_clicked()
{
    this->vLeaves->setVisible(true);
}

void Ventana_Arbol::on_pushButton_3_clicked()
{
    this->setVisible(false);
}
