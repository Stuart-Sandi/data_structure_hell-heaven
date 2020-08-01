#ifndef VENTANA_ARBOL_H
#define VENTANA_ARBOL_H

#include <QMainWindow>
#include <Ventana_Arbol_Leaves.h>
#include <QTreeWidgetItem>
#include <Data.h>

namespace Ui {
class Ventana_Arbol;
}

class Ventana_Arbol : public QMainWindow
{
    Q_OBJECT

public:
    Data * datos;
    Ventana_Arbol_Leaves * vLeaves;
    explicit Ventana_Arbol(QWidget *parent = nullptr, Data * pDatos = nullptr);
    ~Ventana_Arbol();

    void addPadre();
    void crearArbol(Nodo_Arbol*,QTreeWidgetItem*);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Ventana_Arbol *ui;
};

#endif // VENTANA_ARBOL_H
