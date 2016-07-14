#ifndef SUDOMINOKU_HPP
#define SUDOMINOKU_HPP

#include <QMainWindow>
#include <QVector>
#include "ficha.hpp"


namespace Ui {
class Sudominoku;
}

class Sudominoku : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sudominoku(QWidget *parent = 0);
    ~Sudominoku();
    void definirDomino();
    bool verificarCasilla(int, int);

private slots:
    void on_actionCargar_juego_triggered();

    void on_actionJugar_triggered();



private:
    Ui::Sudominoku *ui;
    void cargarAmbiente();
    void definirRuta();
    QString ruta;
    void llenarJuego();
    QVector<Ficha*> *domino;

};

#endif // SUDOMINOKU_HPP
