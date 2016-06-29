#include "sudominoku.hpp"
#include "ui_sudominoku.h"
#include <QInputDialog>
#include <QThread>
#include <QFileDialog>
#include <iostream>


using namespace std;

Sudominoku::Sudominoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sudominoku)
{
    ui->setupUi(this);
    for (int i = 0; i < 9; i++) {

        for (int j = 0; j < 9; j++) {

            QTableWidgetItem *campo = ui->tableroJuego->item(i, j);

            if (campo == NULL) {

                campo = new QTableWidgetItem();
                campo->setText("0");
                ui->tableroJuego->setItem(i, j, campo);

            }
        }
    }

    espaciosVacios= new QVector<Coordenada*>();

    /*definirRuta();
    cout << ruta.toStdString() << endl;*/
}

Sudominoku::~Sudominoku()
{
    delete ui;
}

void Sudominoku::on_actionCargar_juego_triggered()
{

    cargarAmbiente();
}

/*void Sudominoku::definirRuta() {

    int perfil = -1;

    bool ok;
    QInputDialog* inputDialog = new QInputDialog();

    inputDialog->setOptions(QInputDialog::NoButtons);

    QString text =  inputDialog->getText(NULL ,"QInputDialog::getText() Example",
                                          "Escoja su perfil\n"
                                          "0) Anderson\n"
                                          "1) Paola\n"
                                          "2) Julián\n"
                                          "3) Otro", QLineEdit::Normal,"", &ok);

     if (ok && !text.isEmpty()){
         perfil = text.toInt();
      }

     switch (perfil) {
        case 0:
            ruta = "/home/anderojas/Proyectos/SuDominoKu/Iconos/";
        break;
        case 1:
            ruta = "/home/";
        break;
        case 2:
            ruta = "/home/julian/Desktop/IA/Proyecto copia /MagnobotIA/SuDominoKu/Iconos/";
        break;
        case 3:
            ruta = QFileDialog::getExistingDirectory(this, tr("Abrir directorio iconos"), "/home", QFileDialog::ShowDirsOnly);
        break;

    }

}*/

void Sudominoku::cargarAmbiente() {

    srand(time(NULL));
    for (int i=0; i<9; i++){
        for (int j=0; j<9;j++){
            Coordenada *coor=new Coordenada(i,j);
            espaciosVacios->push_back(coor);
        }
    }


    for (int i = 1; i < 10; i++) {

        int posicionVector = rand()%espaciosVacios->size()-1;

        QTableWidgetItem *campo = ui->tableroJuego->item(espaciosVacios->at(posicionVector)->getx(), espaciosVacios->at(posicionVector)->gety());
        campo->setText(QString::number(i));
        espaciosVacios->remove(posicionVector);

    }

    for (int i = 0; i < 9; i++) {

        QString fila = "";
        for (int j = 0; j < 9; j++) {

            QString valor = ui->tableroJuego->item(i, j)->text();
            fila += valor + " ";

        }

        cout << fila.toStdString() << endl;

    }

}

void Sudominoku::llenarJuego() {

    srand(time(NULL));

    for (int i=1; i<10;i++){
        int contador=0;
        while (contador<8 && !espaciosVacios->empty()){

            int posicion = 0;

            if (espaciosVacios->size() > 1)
                posicion = rand()%(espaciosVacios->size()-1);

            ui->tableroJuego->item(espaciosVacios->at(posicion)->getx(),
                                                    espaciosVacios->at(posicion)->gety())->setText(QString::number(i));
            espaciosVacios->remove(posicion);

            contador++;

        }

    }

}

void Sudominoku::on_actionJugar_triggered()
{
    llenarJuego();
}
