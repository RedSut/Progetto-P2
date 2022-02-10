#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QFrame>
#include <QString>
#include <QStackedWidget>
//#include<secondarywindow.h>
#include "graficoView.h"
#include "tableView.h"
//#include "Controller.h"

class Controller;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow :public QWidget
{
    Q_OBJECT
    //SecondaryWindow *secondary;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setController(Controller *c);
    void goToSecondPage();
    void setGrafico(grafico*);
    void updateGrafico(grafico*);

    void aggiungiRigaTabella(grafico*);
    void aggiungiColonnaTabella(grafico*);
    void rimuoviRigaTabella();
    void rimuoviColonnaTabella();
    void modificaSezioneVTabella(int,grafico*);
    void modificaSezioneHTabella(int,grafico*);
private:
    graficoView* graficoWidget;
    tableView* graficoTabella;
    //Ui::MainWindow *ui;
    QMenuBar* menuBar;
    Controller* controller;
    QHBoxLayout* buttons;
    QStackedWidget* pagine;

    QPushButton* pieChart;
    QPushButton* histogram;
    QPushButton* barChart;
    QPushButton* lineChart;
    QPushButton* dispersionChart;

    QMenu* file;
    //Controller* C;

    void addMenuBar();
    QHBoxLayout* addMainButtons();

};
#endif // MAINWINDOW_H
