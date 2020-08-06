#ifndef VENTANA_CONSULTAS_HELLVSHEAVEN_H
#define VENTANA_CONSULTAS_HELLVSHEAVEN_H

#include <QMainWindow>

namespace Ui {
class Ventana_Consultas_HellvsHeaven;
}

class Ventana_Consultas_HellvsHeaven : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_Consultas_HellvsHeaven(QWidget *parent = nullptr);
    ~Ventana_Consultas_HellvsHeaven();

private:
    Ui::Ventana_Consultas_HellvsHeaven *ui;
};

#endif // VENTANA_CONSULTAS_HELLVSHEAVEN_H
