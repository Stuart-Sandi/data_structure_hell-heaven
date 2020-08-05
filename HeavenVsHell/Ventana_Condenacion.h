#ifndef VENTANA_CONDENACION_H
#define VENTANA_CONDENACION_H

#include <QMainWindow>
#include <funcionesArchivos.h>
#include <Data.h>

namespace Ui {
class Ventana_Condenacion;
}

class Ventana_Condenacion : public QMainWindow
{
    Q_OBJECT

public:
    funcionesArchivos * fA;
    Data * datos;
    explicit Ventana_Condenacion(QWidget *parent = nullptr, Data * pDatos = nullptr);
    ~Ventana_Condenacion();  
    QString condenar();
    void calcularDatos(QList<Persona*>);
    QList <Persona*> ordenarListaPecados(int,QList<Persona*>);
    void actualizarDemonio(int);
    QString datosPersona(Persona*,int);

private slots:
    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Ventana_Condenacion *ui;
};

#endif // VENTANA_CONDENACION_H
