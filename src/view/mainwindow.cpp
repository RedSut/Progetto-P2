#include "MainWindow.h"
//#include "ui_mainwindow.h"

#include "../Model/classi/grafico.h"
#include "../Model/classi/graficoCreator.h"
#include <QSize>

void MainWindow::addMenuBar()
{
    menuBar= new QMenuBar(this);
    QMenu* file= new QMenu("File",menuBar);
    menuBar->addMenu(file);
    file->addAction(new QAction("Nuovo",file));
    file->addAction(new QAction("Apri",file));
    file->addAction(new QAction("Chiudi",file));
    file->addAction(new QAction("Salva",file));
    file->addAction(new QAction("Salva come...",file));
    file->addAction(new QAction("Stampa",file));
    QMenu* modifica= new QMenu("Modifica",menuBar);
    menuBar->addMenu(modifica);
    modifica->addAction(new QAction("Annulla",modifica));
    modifica->addAction(new QAction("Ripeti",modifica));
    modifica->addAction(new QAction("Taglia",modifica));
    modifica->addAction(new QAction("Copia",modifica));
    modifica->addAction(new QAction("Incolla",modifica));
    modifica->addAction(new QAction("Aggiorna dati",modifica));
    modifica->addAction(new QAction("Importa",modifica));
    menuBar->setStyleSheet("background-color: White");// color: black");
    menuBar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    return;
}

QHBoxLayout* MainWindow::addMainButtons()
{
    QHBoxLayout* buttonLayout = new QHBoxLayout;


    pieChart= new QPushButton("Grafico a torta");
    QPushButton* histogram= new QPushButton("Istogramma");
    QPushButton* barChart= new QPushButton("Grafico a barre");
    QPushButton* lineChart= new QPushButton("Piano cartesiano");
    QPushButton* dispersionChart= new QPushButton("Grafico a dispersione");

    //pieChart->setStyleSheet("background-image: url(src/View/img/piechart.gif); width: 200px; font-size: 25px; border-radius: 1.5em; height: 200px; border: 2px solid black;" );
    //histogram->setStyleSheet("background-image: url(img/histogram.png); background-repeat: norepeat; background-position: central; width: 200px; font-size: 25px; border: 2px solid black; border-radius: 1.5em; height: 200px;");
    //barChart->setStyleSheet("background-image: url(img/barchart.png); width: 200px; font-size: 25px; border-radius: 1.5em; height: 200px; border: 2px solid black;");
    //lineChart->setStyleSheet("background-image: url(img/linechart.png); width: 200px; font-size: 25px; border-radius: 1.5em; height: 200px; border: 2px solid black;");
    //dispersionChart->setStyleSheet("background-image: url(img/chart.png); width: 200px; font-size: 20px; border-radius: 1.5em; height: 200px; border: 2px solid black;");
    buttonLayout->addWidget(pieChart);
    buttonLayout->addWidget(histogram);
    buttonLayout->addWidget(barChart);
    buttonLayout->addWidget(lineChart);
    buttonLayout->addWidget(dispersionChart);
    buttonLayout->setSpacing(50);
    buttonLayout->setContentsMargins(50, 20, 50, 20);
    buttonLayout->setAlignment(Qt::AlignCenter);
    return buttonLayout;
}

MainWindow::MainWindow(QWidget *parent): QWidget(parent){
    QVBoxLayout* mainLayout = new QVBoxLayout;

    pagine = new QStackedWidget(this);

    addMenuBar();

    setStyleSheet("background-color: Orange;");
    mainLayout->addWidget(menuBar);

    //
    graficoCreator* gc = new graficoCreator();
    std::vector<std::string> leg = {"Prova","Prova2"};
    std::vector<double> val = {24,12,25,13};
    std::vector<std::pair<double,double>> punti = {{24,12},{25,13},{22,12},{21,13},{25,15},{27,12},{30,15},{32,18},{27,14}};
    std::vector<std::string> cat = {"Maschi","Femmine"};
    grafico* gu = gc->createDispersione("Update",punti,"Asse X","Asse Y");
    //
    QWidget* pulsanti = new QWidget(pagine); 
    buttons = addMainButtons();
    pulsanti->setLayout(buttons);
    pagine->addWidget(pulsanti);
    QWidget* b = new QWidget(pagine);   
    graficoWidget = new graficoView();
    tableView* tv = new tableView();
    QHBoxLayout* paginaGrafico = new QHBoxLayout;
    paginaGrafico->addWidget(tv);
    paginaGrafico->addWidget(graficoWidget);
    b->setLayout(paginaGrafico);
    //
    //gw->showGrafico(gu);
    //tv->populateTable(gu);
    //
    pagine->addWidget(b);
    mainLayout->addWidget(pagine);
    setLayout(mainLayout);
    resize(QSize(1024, 720));
}

MainWindow::~MainWindow()
{
   // delete ui;
}

void MainWindow::goToSecondPage(){
    pagine->setCurrentIndex(1);
}

void MainWindow::setGrafico(grafico* G){
    graficoWidget->showGrafico(G);
};

/*
void MainWindow::creaPieChart(){
    graficoWindow = new graficoView(this);
    graficoCreator* gc;
    grafico* G = gc->createTorta();
    graficoWindow->showGrafico(G);
    graficoWindow->show();
}*/

void MainWindow::setController(Controller* c){
    controller = c;
    connect(pieChart, SIGNAL(clicked()), controller, SLOT(createTorta()));
}
