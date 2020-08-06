#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Ventana_Creacion.h>
#include <Ventana_Arbol.h>
#include <Ventana_SumarAcciones.h>
#include <Ventana_Condenacion.h>
#include <Ventana_Salvacion.h>
#include <Ventana_Consultas_HellvsHeaven.h>
#include <Data.h>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Data * datos;
    Ventana_Creacion * vCreacion;
    Ventana_Arbol * vArbol;
    Ventana_SumarAcciones * vAcciones;
    Ventana_Condenacion * vCondenacion;
    Ventana_Salvacion * vSalvacion;
    Ventana_Consultas_HellvsHeaven * vConsultasHVSH;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
