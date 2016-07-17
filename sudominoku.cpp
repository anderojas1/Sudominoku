#include "sudominoku.hpp"
#include "ui_sudominoku.h"
#include <QInputDialog>
#include <QThread>
#include <QFileDialog>
#include <iostream>
#include <QApplication>
#include <QFile>
#include <QFileDialog>
#include <cstdlib>


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
                campo->setTextAlignment(Qt::AlignCenter);
                campo->setText("");
                //campo->setBackgroundColor(QColor(240,240,240));
                campo->setBackgroundColor(QColor(0,0,0));
                campo->setTextColor(QColor(255,255,255));

                ui->tableroJuego->setItem(i, j, campo);

            }
        }
    }

    definirContenedores();
    definirDomino();

    /*definirRuta();
    cout << ruta.toStdString() << endl;*/
}

Sudominoku::~Sudominoku()
{
    delete ui;
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

    definirDomino();
    definirContenedores();
    reiniciarGUI();

    srand(time(NULL));

    int contadorNumeros = 1;

    while (contadorNumeros < 10) {

        int i = rand()%8;
        int j = rand()%8;

        QTableWidgetItem *casilla = ui->tableroJuego->item(i, j);

        if (casilla->text().size() == 0) {

            casilla->setText(QString::number(contadorNumeros++));
            casilla->setBackgroundColor(QColor(255,0,0));

          filas->at(i)->append(casilla->text().toInt());
          columnas->at(j)->append(casilla->text().toInt());
          int cuadro=ubicacionCuadro(i,j);
          cuadros->at(cuadro)->append(casilla->text().toInt());
          cout <<"valor i: "<<i<< endl;
          cout <<"valor j: "<<j<< endl;
          cout <<"cuadro: "<<cuadro<<endl;

         bool validacion=validarsudoku(i,j,casilla->text().toInt());


           if (validacion){
               cout<<"se puede colocar"<<endl;
           }
           else {
               cout<<"NO se puede colocar"<<endl;
           }

        }

    }

}

void Sudominoku::llenarJuego() {

    srand(time(NULL));

    while (domino->size() > 0) {

        bool colocar = false;

        cout << "Ficha: " << domino->at(0)->getNumero1() << " " << domino->at(0)->getNumero2() << endl;

        while (colocar == false) {

            int i = rand()%9;
            int j = rand()%9;
            int rotacion = rand()%3;
            int x, y;

            if (rotacion == 0) {

                x = i;
                y = j+1;

            }

            else if (rotacion == 1) {

                x = i+1;
                y = j;

            }

            else if (rotacion == 2) {

                x = i;
                y = j-1;

            }

            else {

                x = i-1;
                y = j;

            }


            if (verificarCasilla(i, j) && verificarCasilla(x, y)) {

                int G = rand()%255;
                int B = rand()%255;

                ui->tableroJuego->item(i,j)->setText(QString::number(domino->at(0)->getNumero1()));
                ui->tableroJuego->item(i,j)->setBackgroundColor(QColor(0,G,B));
                ui->tableroJuego->item(x,y)->setText(QString::number(domino->at(0)->getNumero2()));
                ui->tableroJuego->item(x,y)->setBackgroundColor(QColor(0,G,B));
                colocar = true;
                cout << "Ficha puesta\n";


                filas->at(i)->append(domino->at(0)->getNumero1());
                columnas->at(j)->append(domino->at(0)->getNumero1());
                int cuadro1=ubicacionCuadro(i,j);
                cuadros->at(cuadro1)->append(domino->at(0)->getNumero1());
                cout <<"valor i: "<<i<< endl;
                cout <<"valor j: "<<j<< endl;
                cout <<"cuadro num1: "<<cuadro1<<endl;

                bool validacion=validarsudoku(i,j,domino->at(0)->getNumero1());

                  if (validacion){
                      cout<<"se puede colocar..................."<<endl;
                  }
                  else {
                      cout<<"NO se puede colocar"<<endl;
                  }



                filas->at(x)->append(domino->at(0)->getNumero2());
                columnas->at(y)->append(domino->at(0)->getNumero2());
                int cuadro2=ubicacionCuadro(x,y);
                cuadros->at(cuadro2)->append(domino->at(0)->getNumero2());
                cout <<"valor x: "<<x<< endl;
                cout <<"valor y: "<<y<< endl;
                cout <<"cuadro num2: "<<cuadro2<<endl;

                bool validacion2=validarsudoku(x,y,domino->at(0)->getNumero2());

                  if (validacion2){
                      cout<<"se puede colocar..................."<<endl;
                  }
                  else {
                      cout<<"NO se puede colocar"<<endl;
                  }

                domino->pop_front();
                qApp->processEvents();



            }

        }

    }

}

void Sudominoku::on_actionJugar_triggered()
{
    llenarJuego();
}

void Sudominoku::definirDomino() {

    domino = new QVector<Ficha*>();

    for (int i = 1; i < 10; i++) {

        for (int j = i +1; j < 10; j++) {

            Ficha *nuevaFicha = new Ficha(i, j);
            domino->append(nuevaFicha);

        }

    }

}

bool Sudominoku::verificarCasilla(int i, int j) {

    bool casillaLibre = false;

    if (i >= 0 && i < 9 && j >= 0 && j < 9) {

        if (ui->tableroJuego->item(i, j)->text().size() == 0)
            casillaLibre = true;

    }

    return casillaLibre;

}

void Sudominoku::on_actionCargar_ambiente_triggered()
{
    cargarArchivo();
}

void Sudominoku::on_actionAleatorio_triggered()
{
    cargarAmbiente();
}

void Sudominoku::cargarArchivo() {

    definirDomino();
    definirContenedores();
    reiniciarGUI();

    QString username = getenv("USER");
    QString path_to_show = "/home/" + username + "/";

    QString path = QFileDialog::getOpenFileName(this, tr("Defina el archivo..."), path_to_show.toStdString().c_str());

    QFile *archivo = new QFile(path);

    if (!archivo->open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    int lineaArchivo = 0;

    while (!archivo->atEnd()) {

        QByteArray line = archivo->readLine();
        QString linea (line);
        QStringList caracteres = linea.split(QRegExp("\\s"));

        for (int j = 0; j < caracteres.size()-1; j++) {

            QString valor = caracteres.at(j).toLocal8Bit().constData();
            QTableWidgetItem *campo = ui->tableroJuego->item(lineaArchivo, j);

            if (valor == "0") {

                campo->setBackgroundColor(QColor(0,0,0));
                campo->setText("");

            }

            else {

                campo->setBackgroundColor(QColor(255,0,0));
                campo->setText(valor);

            }

        }

        lineaArchivo++;

    }

    qApp->processEvents();

}

void Sudominoku::reiniciarGUI() {

    for (int i = 0; i < 9; i++) {

        for (int j = 0; j < 9; j++) {

            ui->tableroJuego->item(i, j)->setText("");
            ui->tableroJuego->item(i, j)->setBackgroundColor(QColor(0,0,0));

        }

    }

}

void Sudominoku::definirContenedores() {

    filas = new QVector<QVector<int>*>();
    columnas = new QVector<QVector<int>*>();
    cuadros = new QVector<QVector<int>*>();

    for (int i = 0; i < 9; i++) {

        filas->append(new QVector<int>());

    }

    for (int i = 0; i < 9; i++) {

        columnas->append(new QVector<int>());

    }

    for (int i = 0; i < 9; i++) {

        cuadros->append(new QVector<int>());

    }

}
int Sudominoku::ubicacionCuadro(int fila, int colum){
    int resultado;

    if (fila <= 2){
        if (colum <=2){
            resultado=0;
        }
        else if((colum>2)&&(colum <=5)){
            resultado=1;
        }
        else {
            resultado=2;
        }
    }
    else if ((fila >2)&&(fila<=5)){

        if (colum <=2){
            resultado=3;
        }
        else if((colum>2)&&(colum <=5)){
            resultado=4;
        }
        else {
            resultado=5;
        }
    }
    else {
        if (colum <=2){
            resultado=6;
        }
        else if((colum>2)&&(colum <=5)){
            resultado=7;
        }
        else {
            resultado=8;
        }
    }
    return resultado;
}

bool Sudominoku::validarsudoku(int i, int j,int num){
    QVector<int> *fila=new QVector<int>();
    fila=filas->at(i);
    QVector<int> *colum=new QVector<int>();
    colum=columnas->at(j);
    int contador=0;
    bool respuesta=true;

    for(int k=0; k<fila->size(); k++){
        if (fila->at(k)==num){
            contador++;
        }
        if (contador>1){
            respuesta=false;
            break;
        }
    }
    contador=0;
    for(int m=0; m<colum->size(); m++){
        if (colum->at(m)==num){
            contador++;
        }
        if (contador>1){
            respuesta=false;
            break;
        }
    }

    return respuesta;

}





