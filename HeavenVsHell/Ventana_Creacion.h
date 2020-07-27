#ifndef VENTANA_CREACION_H
#define VENTANA_CREACION_H

#include <QMainWindow>
#include <Data.h>
#include <QMessageBox>

namespace Ui {
class Ventana_Creacion;
}

class Ventana_Creacion : public QMainWindow
{
    Q_OBJECT

public:
    int validar;
    Data * datos;
    explicit Ventana_Creacion(QWidget *parent = nullptr, Data* pData = NULL);
    ~Ventana_Creacion();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Ventana_Creacion *ui;
};

#endif // VENTANA_CREACION_H
