#ifndef VENTANA_ARBOL_LEAVES_H
#define VENTANA_ARBOL_LEAVES_H

#include <QMainWindow>
#include <Data.h>

namespace Ui {
class Ventana_Arbol_Leaves;
}

class Ventana_Arbol_Leaves : public QMainWindow
{
    Q_OBJECT

public:
    Data * datos;
    explicit Ventana_Arbol_Leaves(QWidget *parent = nullptr, Data * pDatos = nullptr);
    ~Ventana_Arbol_Leaves();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Ventana_Arbol_Leaves *ui;
};

#endif // VENTANA_ARBOL_LEAVES_H
