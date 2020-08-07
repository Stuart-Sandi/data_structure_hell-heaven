#ifndef VENTANA_CONSULTAS_HELLVSHEAVEN_H
#define VENTANA_CONSULTAS_HELLVSHEAVEN_H

#include <QMainWindow>
#include <Data.h>
#include <Ventana_MostrarCI.h>

namespace Ui {
class Ventana_Consultas_HellvsHeaven;
}

class Ventana_Consultas_HellvsHeaven : public QMainWindow
{
    Q_OBJECT

public:
    Data * datos;
    int accion;
    int vivos;
    int infierno;
    int cielo;
    long int totalPecados;
    long int totalBuenasAcciones;
    Ventana_MostrarCI * ventana;
    explicit Ventana_Consultas_HellvsHeaven(QWidget *parent = nullptr, Data * pDatos = nullptr);
    ~Ventana_Consultas_HellvsHeaven();

    void rellernarComboBoxCategorias(int);
    void rellernarComboBoxFamilias();
    void hallarTotalAcciones(QList<Persona*>);
    QString agregarDatos(Persona*);
    QString agregarDatosFamilia(Persona*);
    QList<Persona*> ordenarMundo(int, QList<Persona*>);

private slots:


    void on_pushButton_clicked();

    void on_comboBox_5_activated(int index);

    void on_comboBox_activated(int index);

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Ventana_Consultas_HellvsHeaven *ui;
};

#endif // VENTANA_CONSULTAS_HELLVSHEAVEN_H
