#ifndef VENTANA_CONSULTAS_ACCIONES_H
#define VENTANA_CONSULTAS_ACCIONES_H

#include <QMainWindow>
#include <Data.h>
#include <QList>
#include <QMessageBox>

namespace Ui {
class Ventana_Consultas_Acciones;
}

class Ventana_Consultas_Acciones : public QMainWindow
{
    Q_OBJECT

public:
    QList <Persona*> lista;
    Data * datos;
    QString mensaje;

    explicit Ventana_Consultas_Acciones(QWidget *parent = nullptr, Data * pDatos = nullptr);
    ~Ventana_Consultas_Acciones();

    void crearMensajeFamilias(Persona*);
    void limpiarListas();
    void asignarAccionesAListas();
    QList <Lugar*> ordenarLista(QList<Lugar*>);
    void mostrarDatosPaises();
    void mostrarDatosContinentes();

private slots:
    void on_comboBox_activated(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Ventana_Consultas_Acciones *ui;
};

#endif // VENTANA_CONSULTAS_ACCIONES_H
