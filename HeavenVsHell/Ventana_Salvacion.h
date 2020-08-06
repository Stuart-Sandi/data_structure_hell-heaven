#ifndef VENTANA_SALVACION_H
#define VENTANA_SALVACION_H

#include <QMainWindow>
#include <Data.h>

namespace Ui {
class Ventana_Salvacion;
}

class Ventana_Salvacion : public QMainWindow
{
    Q_OBJECT

public:
    Data * datos;
    explicit Ventana_Salvacion(QWidget *parent = nullptr, Data * pDatos = nullptr);
    ~Ventana_Salvacion();
    void insertarEnArbolTriArio(NodoTriArio*);
    QList <Persona*> ordenarInfierno(QList<Persona*>);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Ventana_Salvacion *ui;
};

#endif // VENTANA_SALVACION_H
