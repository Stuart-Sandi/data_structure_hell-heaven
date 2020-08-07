#ifndef VENTANA_MOSTRARCI_H
#define VENTANA_MOSTRARCI_H

#include <QMainWindow>
#include <Data.h>

namespace Ui {
class Ventana_MostrarCI;
}

class Ventana_MostrarCI : public QMainWindow
{
    Q_OBJECT

public:
    Data * datos;
    explicit Ventana_MostrarCI(QWidget *parent = nullptr, Data * pDatos = nullptr);
    ~Ventana_MostrarCI();

    void imprimirInfierno();
    void imprimirCielo();

    QString datosCielo(Persona*);
    QString datosInfierno(Persona*);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Ventana_MostrarCI *ui;
};

#endif // VENTANA_MOSTRARCI_H
