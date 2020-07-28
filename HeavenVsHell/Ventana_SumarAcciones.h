#ifndef VENTANA_SUMARACCIONES_H
#define VENTANA_SUMARACCIONES_H

#include <QMainWindow>

namespace Ui {
class Ventana_SumarAcciones;
}

class Ventana_SumarAcciones : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_SumarAcciones(QWidget *parent = nullptr);
    ~Ventana_SumarAcciones();

private:
    Ui::Ventana_SumarAcciones *ui;
};

#endif // VENTANA_SUMARACCIONES_H
