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
#include <QTextStream>
#include <QThread>
#include <algorithm>


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

        }

    }

    guardarEstado();

}

void Sudominoku::llenarJuego() {

    srand(time(NULL));

    while(validarSudoku() == false){

    /*while (domino->size() > 0) {

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
                int cuadro1=ubicacionCuadro(i,j);
                bool validacion=validarsudoku(i,j,cuadro1,domino->at(0)->getNumero1());
                int cuadro2=ubicacionCuadro(x,y);
                bool validacion2=validarsudoku(x,y,cuadro2,domino->at(0)->getNumero2());

                if (validacion && validacion2){

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
                    cuadros->at(cuadro1)->append(domino->at(0)->getNumero1());
                    cout <<"valor i: "<<i<< endl;
                    cout <<"valor j: "<<j<< endl;


                    filas->at(x)->append(domino->at(0)->getNumero2());
                    columnas->at(y)->append(domino->at(0)->getNumero2());
                    cuadros->at(cuadro2)->append(domino->at(0)->getNumero2());
                    cout <<"valor x: "<<x<< endl;
                    cout <<"valor y: "<<y<< endl;

                    domino->pop_front();
                    qApp->processEvents();

                }

            }

        }

    }*/
    qApp->processEvents();
    for (int i = 0; i < 9; i++) {

        for (int j = 0; j < 9; j++) {


            if (domino->size() > 0) {

                int posicion = 0;

                if (domino->size() > 1)
                    posicion = rand()%(domino->size());
                else {

                }
                //cout << "Obtiene posicion\n";
                qApp->processEvents();
                Ficha *fichaObtenida = domino->at(posicion);
                QTableWidgetItem *casilla = ui->tableroJuego->item(i, j);
                //cout << "Obtiene casilla\n";
                qApp->processEvents();
                QTableWidgetItem *campoContiguo = NULL;
                if (i == 8) {

                    QString msj = "Entrando a posición (" + QString::number(i) + "," + QString::number(j)
                            + ")";
                    //qDebug(msj.toStdString().c_str());
                    QString ms = "Quedan " + QString::number(domino->size()) + " fichas disponibles";
                    //qDebug(ms.toStdString().c_str());

                }

                if (casilla->text() == "") {



                    if (j+1 < 9) {

                        campoContiguo = ui->tableroJuego->item(i, j+1);

                        if (campoContiguo->text() == "") {

                            int G = rand()%255;
                            int B = rand()%255;

                            casilla->setText(QString::number(fichaObtenida->getNumero1()));
                            casilla->setBackgroundColor(QColor(0,G,B));
                            campoContiguo->setText(QString::number(fichaObtenida->getNumero2()));
                            campoContiguo->setBackgroundColor(QColor(0,G,B));
                            domino->remove(posicion);

                        }

                        else if (i+1 < 9) {

                            campoContiguo = ui->tableroJuego->item(i+1, j);

                            if (campoContiguo->text() == "") {

                                int G = rand()%255;
                                int B = rand()%255;
                                casilla->setText(QString::number(fichaObtenida->getNumero1()));
                                casilla->setBackgroundColor(QColor(0,G,B));
                                campoContiguo->setText(QString::number(fichaObtenida->getNumero2()));
                                campoContiguo->setBackgroundColor(QColor(0,G,B));
                                domino->remove(posicion);

                            }

                        }

                    }

                    else if (i+1 < 9) {

                        campoContiguo = ui->tableroJuego->item(i+1, j);

                        if (campoContiguo->text() == "") {

                            int G = rand()%255;
                            int B = rand()%255;
                            casilla->setText(QString::number(fichaObtenida->getNumero1()));
                            casilla->setBackgroundColor(QColor(0,G,B));
                            campoContiguo->setText(QString::number(fichaObtenida->getNumero2()));
                            campoContiguo->setBackgroundColor(QColor(0,G,B));
                            domino->remove(posicion);

                        }

                    }

                    /*else if (i+1 < 9) {

                        campoContiguo = ui->tableroJuego->item(i+1, j);

                        if (campoContiguo->text() == "") {

                            int G = rand()%255;
                            int B = rand()%255;

                            casilla->setText(QString::number(fichaObtenida->getNumero1()));
                            casilla->setBackgroundColor(QColor(0,G,B));
                            campoContiguo->setText(QString::number(fichaObtenida->getNumero2()));
                            campoContiguo->setBackgroundColor(QColor(0,G,B));
                            domino->remove(posicion);

                        }

                    }*/


                }

            }

        }

    }

    qApp->processEvents();
    if (validarSudoku() == true)
        qDebug("Correcto");
    else {

        //qDebug("Entrando a validar si se llenó el sudoku");

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                QString valor = ui->tableroJuego->item(i,j)->text();

                if (valor == "") {
                    qDebug("vacío");
                }

                else {
                //    qDebug(valor.toStdString().c_str());
                }
            }
        }

        //QThread::sleep(3000);
        //this->thread()->start();
        //qApp->processEvents();
        //qDebug("No correcto");

        QString reporte = "No se colocaron " + QString::number(domino->size()) + " fichas";
        qDebug(reporte.toStdString().c_str());
        reiniciarGUI();
        definirDomino();
        definirContenedores();
        obtenerEstado();
        //ui->tableroJuego->item(8,6)->setText("anasn");
        //llenarJuego();

    }

    int matrizJuego[9][9];

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){

            if(matrizJuego[i][j] = ui->tableroJuego->item(i,j)->text() == ""){

                matrizJuego[i][j] = 0;
            }else{

                matrizJuego[i][j] = ui->tableroJuego->item(i,j)->text().toInt();

            }

        }

    }

    validarBuenas(matrizJuego);

}
}

void Sudominoku::on_actionJugar_triggered()
{
    qDebug("Funciona\n");
    llenarJuego();
}

void Sudominoku::definirDomino() {

    //delete domino;

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
    int fila=-1;



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
        fila++;
        int colum=-1;

        for (int j = 0; j < caracteres.size()-1; j++) {

            QString valor = caracteres.at(j).toLocal8Bit().constData();
            QTableWidgetItem *campo = ui->tableroJuego->item(lineaArchivo, j);
            colum++;

            if (valor == "0") {

                campo->setBackgroundColor(QColor(0,0,0));
                campo->setText("");

            }

            else {

                campo->setBackgroundColor(QColor(255,0,0));
                campo->setText(valor);

                filas->at(fila)->append(valor.toInt());
                columnas->at(colum)->append(valor.toInt());
                int cuadro=ubicacionCuadro(fila,colum);
                cuadros->at(cuadro)->append(valor.toInt());

            }

        }

        lineaArchivo++;

    }

    guardarEstado();

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

bool Sudominoku::validarsudoku(int i, int j,int cubo, int num){
    QVector<int> *fila=filas->at(i);
    QVector<int> *colum=columnas->at(j);
    QVector<int> *cuadro=cuadros->at(cubo);

    int contadorFila=0;
    int contadorColum=0;
    int contadorCuadro=0;
    bool respuesta=true;

    for(int k=0; k<fila->size(); k++){
        if (fila->at(k)==num){
            contadorFila++;
        }
        if (contadorFila>=1){
            respuesta=false;
            break;
        }
    }
    if (contadorFila==0){
        for(int m=0; m<colum->size(); m++){
            if (colum->at(m)==num){
                contadorColum++;
            }
            if (contadorColum>=1){
            respuesta=false;
            break;
            }
        }
    }
    if (contadorColum==0){
        for(int n=0; n<cuadro->size(); n++){
            if (cuadro->at(n)==num){
                contadorCuadro++;
            }
            if (contadorCuadro>=1){
            respuesta=false;
            break;
            }
        }
    }

    return respuesta;

}

bool Sudominoku::validarSudoku() {

    bool valido = true;

    for (int i = 0; i < 9 && valido == true; i++) {

        int suma = 0;

        for (int j = 0; j < 9; j++) {

            if (ui->tableroJuego->item(i, j)->text().size() > 0)
                suma += ui->tableroJuego->item(i, j)->text().toInt();

        }

        if (suma != 45)
            valido = false;

    }

    for (int j = 0; j < 9 && valido == true; j++) {

        int suma = 0;

        for (int i = 0; i < 9; i++) {

            if (ui->tableroJuego->item(i,j)->text().size() > 0)
                suma += ui->tableroJuego->item(i, j)->text().toInt();

        }

        if (suma != 45)
            valido = false;

    }

    return valido;

}

void Sudominoku::guardarEstado() {

    QFile estadoInicial("/home/julian/Desktop/Sudominoku/sudominoku/pruebas/prebaTexto.txt");

    estadoInicial.open(QIODevice::WriteOnly | QIODevice::Truncate);

    QTextStream texto(&estadoInicial);

  //  texto << "Hola mundo"<<endl;

    for (int i = 0; i < 9; i++) {

       QString fila = "";

       for (int j = 0; j < 9; j++) {

           QString valor = ui->tableroJuego->item(i, j)->text();

                if (valor.size() == 0)
                    fila += "0 ";

                else
                    fila += valor + " ";

        }

            fila.remove(fila.size()-1);

            texto << fila << endl;

    }

    estadoInicial.close();

    cout<<"Se creo"<<endl;
}


void Sudominoku::obtenerEstado() {

    QFile *archivo = new QFile("/home/julian/Desktop/Sudominoku/sudominoku/pruebas/prebaTexto.txt");

    if (!archivo->open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    int lineaArchivo = 0;
    int fila = -1;

    while (!archivo->atEnd()) {

        QByteArray line = archivo->readLine();
        QString linea (line);
        QStringList caracteres = linea.split(QRegExp("\\s"));
        fila++;
        int colum=-1;

        for (int j = 0; j < caracteres.size()-2; j++) {

            QString valor = caracteres.at(j).toLocal8Bit().constData();
            QTableWidgetItem *campo = ui->tableroJuego->item(lineaArchivo, j);

            colum++;

            if (valor == "0") {

                campo->setBackgroundColor(QColor(0,0,0));
                campo->setText("");

            }

            else {

                if (campo == NULL)
                    qDebug("Más nulo que que hp");
                campo->setBackgroundColor(QColor(255,0,0));
                campo->setText(valor);

                filas->at(fila)->append(valor.toInt());
                columnas->at(colum)->append(valor.toInt());
                int cuadro=ubicacionCuadro(fila,colum);
                cuadros->at(cuadro)->append(valor.toInt());

            }

        }

        lineaArchivo++;

    }

    //qApp->processEvents();

}

void Sudominoku::validarBuenas(int matriz [][9]){

        int numFilas [9];
        int numCol [9];

        bool col = true;
        bool fil = true;

        int cantidadFilaBien = 0;
        int cantidadColBien = 0;


            for(int i = 0; i < 9; i++){

                for(int j = 0; j < 9; j++){

                    numFilas[j] = matriz[i][j];
                    numCol[j] = matriz[j][i];
                }



                vector <int> vectorFila (numFilas, numFilas+9);
                vector <int> vectorCol (numCol, numCol+9);



                sort(vectorFila.begin(), vectorFila.end());
                sort(vectorCol.begin(), vectorCol.end());


                for(int i = 1; i < 10 && fil == true; i++){


                    if(vectorFila[i - 1] != i){

                        fil = false;

                        }

                    }

                for(int i = 1; i < 10 && col == true; i++){

                    if(vectorCol[i -1] != i){

                        col = false;

                        }

                    }

                if(fil == true){

                        cantidadFilaBien ++;
                        fil = true;
                    }else{

                        fil = true;

                        }

                if(col == true){

                        cantidadColBien++;
                        col = true;
                    }else{

                        col = true;

                        }

            }



            cout << "cantidad filas bien:	"<< cantidadFilaBien <<"	" <<endl;
            cout << "cantidad Col bien:	"<< cantidadColBien <<"	" <<endl;
        }

void Sudominoku::llenarJuegoPosicionAleatoria() {

    srand(time(NULL));

    while (validarSudoku() == false) {

        int contador = 0;

        while (domino->size() > 0 && contador < 20) {

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
                    int cuadro1=ubicacionCuadro(i,j);
                    bool validacion=validarsudoku(i,j,cuadro1,domino->at(0)->getNumero1());
                    int cuadro2=ubicacionCuadro(x,y);
                    bool validacion2=validarsudoku(x,y,cuadro2,domino->at(0)->getNumero2());
                    if (validacion && validacion2){
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
                        cuadros->at(cuadro1)->append(domino->at(0)->getNumero1());
                        cout <<"valor i: "<<i<< endl;
                        cout <<"valor j: "<<j<< endl;
                        filas->at(x)->append(domino->at(0)->getNumero2());
                        columnas->at(y)->append(domino->at(0)->getNumero2());
                        cuadros->at(cuadro2)->append(domino->at(0)->getNumero2());
                        cout <<"valor x: "<<x<< endl;
                        cout <<"valor y: "<<y<< endl;
                        domino->pop_front();
                        contador = 0;
                        qApp->processEvents();
                    }
                }

                else
                    contador++;

            }

            int matrizJuego[9][9];

            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){

                    if(matrizJuego[i][j] = ui->tableroJuego->item(i,j)->text() == ""){

                        matrizJuego[i][j] = 0;
                    }else{

                        matrizJuego[i][j] = ui->tableroJuego->item(i,j)->text().toInt();

                    }

                }

            }

            validarBuenas(matrizJuego);
        }
    }
}

void Sudominoku::on_actionFichas_Aleatorias_triggered()
{
    llenarJuego();
}

void Sudominoku::on_actionPosiciones_Aleatorias_triggered()
{
    llenarJuegoPosicionAleatoria();
}
