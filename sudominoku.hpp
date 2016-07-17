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
    void cargarArchivo();
    void reiniciarGUI();
    void definirContenedores();
    bool verificarsudoku();
    int ubicacionCuadro(int fila, int colum);
    bool validarsudoku(int i,int j,int cubo,int num);

private slots:
    void on_actionJugar_triggered();
    void on_actionCargar_ambiente_triggered();
    void on_actionAleatorio_triggered();

private:
    Ui::Sudominoku *ui;
    void cargarAmbiente();
    void definirRuta();
    QString ruta;
    void llenarJuego();
    QVector<Ficha*> *domino;
    QVector<QVector<int>*> *filas;
    QVector<QVector<int>*> *columnas;
    QVector<QVector<int>*> *cuadros;

};

#endif // SUDOMINOKU_HPP
