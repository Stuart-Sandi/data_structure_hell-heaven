#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Propiedades de la ventana Principal
    this->setWindowTitle("Hell vs Heaven");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(740,530);

    this->datos = new Data();

    //REFERENCIAS DE VENTANAS
    this->vCreacion = new Ventana_Creacion(0, this->datos);
    this->vArbol = new Ventana_Arbol(0, this->datos);
    this->vAcciones = new Ventana_SumarAcciones(0, this->datos);
    this->vCondenacion = new Ventana_Condenacion(0, this->datos);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->vCreacion->setVisible(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (this->datos->arbol->raiz != nullptr){
        this->vArbol->setVisible(true);
    } else {
        QMessageBox msgBox;
        msgBox.setText("Debe crear el mundo primero.");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(msgBox.Critical);
        msgBox.exec();

    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (this->datos->arbol->raiz != nullptr){
        this->vAcciones->setVisible(true);
    } else {
        QMessageBox msgBox;
        msgBox.setText("Debe crear el mundo primero.");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(msgBox.Critical);
        msgBox.exec();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if (this->datos->arbol->raiz != nullptr){
        this->vCondenacion->setVisible(true);
    } else {
        QMessageBox msgBox;
        msgBox.setText("Debe crear el mundo primero.");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(msgBox.Critical);
        msgBox.exec();
    }
}
