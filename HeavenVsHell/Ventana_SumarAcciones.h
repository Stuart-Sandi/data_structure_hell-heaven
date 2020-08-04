#ifndef VENTANA_SUMARACCIONES_H
#define VENTANA_SUMARACCIONES_H

#include <QMainWindow>
#include "funcionesArchivos.h"
#include <Ventana_Consultas_Acciones.h>
#include "Data.h"
#include <QMessageBox>

namespace Ui {
class Ventana_SumarAcciones;
}

class Ventana_SumarAcciones : public QMainWindow
{
    Q_OBJECT

public:
    Data * datos;
    Ventana_Consultas_Acciones * vConsultas;
    funcionesArchivos * fa = new funcionesArchivos();
    bool pecadosAgregados = false;
    bool buenasAccionesAgregadas = false;

    explicit Ventana_SumarAcciones(QWidget *parent = nullptr, Data* pData = NULL);
    ~Ventana_SumarAcciones();

private slots:

    bool accionesAgregadas(bool, bool);

    void on_btn_BuenasAcciones_clicked();

    void on_btn_Pecados_clicked();

    void on_btn_GoBack_clicked();

    void on_btn_GoBack_2_clicked();

private:
    Ui::Ventana_SumarAcciones *ui;
};

#endif // VENTANA_SUMARACCIONES_H
