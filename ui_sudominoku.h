/********************************************************************************
** Form generated from reading UI file 'sudominoku.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOMINOKU_H
#define UI_SUDOMINOKU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sudominoku
{
public:
    QAction *actionSalir;
    QAction *actionJugar;
    QAction *actionCargar_ambiente;
    QAction *actionAleatorio;
    QWidget *centralWidget;
    QTableWidget *tableroJuego;
    QMenuBar *menuBar;
    QMenu *menuOpciones;
    QMenu *menuCargar_juego;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Sudominoku)
    {
        if (Sudominoku->objectName().isEmpty())
            Sudominoku->setObjectName(QStringLiteral("Sudominoku"));
        Sudominoku->resize(603, 631);
        actionSalir = new QAction(Sudominoku);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionJugar = new QAction(Sudominoku);
        actionJugar->setObjectName(QStringLiteral("actionJugar"));
        actionCargar_ambiente = new QAction(Sudominoku);
        actionCargar_ambiente->setObjectName(QStringLiteral("actionCargar_ambiente"));
        actionAleatorio = new QAction(Sudominoku);
        actionAleatorio->setObjectName(QStringLiteral("actionAleatorio"));
        centralWidget = new QWidget(Sudominoku);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableroJuego = new QTableWidget(centralWidget);
        if (tableroJuego->columnCount() < 9)
            tableroJuego->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableroJuego->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableroJuego->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableroJuego->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableroJuego->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableroJuego->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableroJuego->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableroJuego->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableroJuego->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableroJuego->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (tableroJuego->rowCount() < 9)
            tableroJuego->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableroJuego->setVerticalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableroJuego->setVerticalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableroJuego->setVerticalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableroJuego->setVerticalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableroJuego->setVerticalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableroJuego->setVerticalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableroJuego->setVerticalHeaderItem(6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableroJuego->setVerticalHeaderItem(7, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableroJuego->setVerticalHeaderItem(8, __qtablewidgetitem17);
        tableroJuego->setObjectName(QStringLiteral("tableroJuego"));
        tableroJuego->setGeometry(QRect(10, 20, 472, 482));
        tableroJuego->setMinimumSize(QSize(472, 482));
        tableroJuego->setMaximumSize(QSize(472, 482));
        tableroJuego->setAutoScroll(false);
        tableroJuego->setIconSize(QSize(50, 50));
        tableroJuego->horizontalHeader()->setDefaultSectionSize(50);
        tableroJuego->horizontalHeader()->setMinimumSectionSize(50);
        tableroJuego->verticalHeader()->setDefaultSectionSize(50);
        tableroJuego->verticalHeader()->setMinimumSectionSize(50);
        Sudominoku->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Sudominoku);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 603, 29));
        menuOpciones = new QMenu(menuBar);
        menuOpciones->setObjectName(QStringLiteral("menuOpciones"));
        menuCargar_juego = new QMenu(menuOpciones);
        menuCargar_juego->setObjectName(QStringLiteral("menuCargar_juego"));
        Sudominoku->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Sudominoku);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Sudominoku->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Sudominoku);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Sudominoku->setStatusBar(statusBar);

        menuBar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(menuCargar_juego->menuAction());
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionJugar);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);
        menuCargar_juego->addSeparator();
        menuCargar_juego->addAction(actionCargar_ambiente);
        menuCargar_juego->addAction(actionAleatorio);

        retranslateUi(Sudominoku);

        QMetaObject::connectSlotsByName(Sudominoku);
    } // setupUi

    void retranslateUi(QMainWindow *Sudominoku)
    {
        Sudominoku->setWindowTitle(QApplication::translate("Sudominoku", "Sudominoku", 0));
        actionSalir->setText(QApplication::translate("Sudominoku", "Salir", 0));
        actionJugar->setText(QApplication::translate("Sudominoku", "Jugar", 0));
        actionCargar_ambiente->setText(QApplication::translate("Sudominoku", "Cargar ambiente", 0));
        actionAleatorio->setText(QApplication::translate("Sudominoku", "Aleatorio", 0));
        QTableWidgetItem *___qtablewidgetitem = tableroJuego->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Sudominoku", "0", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableroJuego->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Sudominoku", "1", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableroJuego->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Sudominoku", "2", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableroJuego->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Sudominoku", "3", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableroJuego->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Sudominoku", "4", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableroJuego->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Sudominoku", "5", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableroJuego->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Sudominoku", "6", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableroJuego->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Sudominoku", "7", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableroJuego->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Sudominoku", "8", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableroJuego->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("Sudominoku", "0", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableroJuego->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("Sudominoku", "1", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableroJuego->verticalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("Sudominoku", "2", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableroJuego->verticalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("Sudominoku", "3", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableroJuego->verticalHeaderItem(4);
        ___qtablewidgetitem13->setText(QApplication::translate("Sudominoku", "4", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableroJuego->verticalHeaderItem(5);
        ___qtablewidgetitem14->setText(QApplication::translate("Sudominoku", "5", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableroJuego->verticalHeaderItem(6);
        ___qtablewidgetitem15->setText(QApplication::translate("Sudominoku", "6", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableroJuego->verticalHeaderItem(7);
        ___qtablewidgetitem16->setText(QApplication::translate("Sudominoku", "7", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableroJuego->verticalHeaderItem(8);
        ___qtablewidgetitem17->setText(QApplication::translate("Sudominoku", "8", 0));
        menuOpciones->setTitle(QApplication::translate("Sudominoku", "Opciones", 0));
        menuCargar_juego->setTitle(QApplication::translate("Sudominoku", "Cargar juego", 0));
    } // retranslateUi

};

namespace Ui {
    class Sudominoku: public Ui_Sudominoku {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOMINOKU_H
