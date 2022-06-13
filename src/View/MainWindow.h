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
#include <QMessageBox>
#include <QFileDialog>
#include "graficoView.h"
#include "tableView.h"
#include "../Model/classi/graficoJSON.h"

class Controller;

class MainWindow :public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setController(Controller *c);
    void setGrafico(grafico*);
    void updateGraficoFromTable(grafico*);

    void goToSecondPage();
    void goToFirstPage();
    void goToFirstPageAccept();

    void aggiungiRigaTabella(grafico*);
    void aggiungiColonnaTabella(grafico*);
    void rimuoviRigaTabella();
    void rimuoviColonnaTabella();
    void modificaSezioneVTabella(int,grafico*);
    void modificaSezioneHTabella(int,grafico*);
    void updateRegressioneLineare();
    void updateOrdinaPuntiTabella();

    void addRighe(grafico*);
    void removeRighe();
    void addColonne(grafico*);
    void removeColonne(grafico*);
    void rename(grafico*);

    void openFile(graficoJSON*);
    void saveFileAs(graficoJSON*);
    void saveFile(graficoJSON*);
    void closeApp();

private:
    graficoView* graficoWidget;
    tableView* graficoTabella;
    //Ui::MainWindow *ui;

    Controller* controller;
    QHBoxLayout* buttons;
    QStackedWidget* pagine;

    QPushButton* pieChart;
    QPushButton* histogram;
    QPushButton* barChart;
    QPushButton* lineChart;
    QPushButton* dispersionChart;

    QMenuBar* menuBar;
    QMenu* file,*modifica;

    QString nomeFileAperto;
    QLabel* displayFileName;

    void addMenuBar();
    QHBoxLayout* addMainButtons();

};
#endif // MAINWINDOW_H
