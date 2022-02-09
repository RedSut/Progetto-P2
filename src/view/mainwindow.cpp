#include "MainWindow.h"
//#include "ui_mainwindow.h"

#include "../Model/classi/grafico.h"
#include "../Model/classi/graficoCreator.h"
#include "Controller.h"
#include <QSize>

void MainWindow::addMenuBar()
{
    menuBar= new QMenuBar(this);
    file= new QMenu("File",menuBar);
    menuBar->addMenu(file);
    file->addAction(new QAction("Nuovo",file));
    file->addAction(new QAction("Apri",file));
    file->addAction(new QAction("Salva",file));
    file->addAction(new QAction("Salva con nome",file));
    file->addAction(new QAction("Chiudi", file));

    file->actions()[0]->setShortcut(Qt::CTRL | Qt::Key_N);
    file->actions()[1]->setShortcut(Qt::CTRL | Qt::Key_O);
    file->actions()[2]->setShortcut(Qt::CTRL | Qt::Key_S);
    file->actions()[3]->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_S);
    file->actions()[4]->setShortcut(Qt::ALT | Qt::Key_F4);


    menuBar->setStyleSheet("background-color: White");// color: black");
    menuBar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    connect(file->actions()[4], SIGNAL(triggered()), this, SLOT(close()));


    return;
}

QHBoxLayout* MainWindow::addMainButtons()
{
    QHBoxLayout* buttonLayout = new QHBoxLayout;


    pieChart= new QPushButton("Grafico a torta");
    histogram= new QPushButton("Istogramma");
    barChart= new QPushButton("Grafico a barre");
    lineChart= new QPushButton("Piano cartesiano");
    dispersionChart= new QPushButton("Grafico a dispersione");

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

    
    QWidget* pulsanti = new QWidget(pagine); 
    buttons = addMainButtons();
    pulsanti->setLayout(buttons);
    pagine->addWidget(pulsanti);
    QWidget* b = new QWidget(pagine);   
    graficoWidget = new graficoView();
    graficoTabella = new tableView();
    QHBoxLayout* paginaGrafico = new QHBoxLayout;
    paginaGrafico->addWidget(graficoTabella);
    paginaGrafico->addWidget(graficoWidget);
    b->setLayout(paginaGrafico);
    
    pagine->addWidget(b);
    mainLayout->addWidget(pagine);
    setLayout(mainLayout);
    resize(QSize(1280, 775));
}

MainWindow::~MainWindow()
{
   // delete ui;
}

void MainWindow::goToSecondPage(){
    pagine->setCurrentIndex(1);
}

void MainWindow::setGrafico(grafico* G){
    graficoTabella->populateTable(G);
    graficoWidget->showGrafico(G);
};

void MainWindow::updateGrafico(grafico* G){
    graficoTabella->extractTable(G);
    graficoWidget->updateGrafico(G);
    graficoTabella->populateTable(G);
};

void MainWindow::aggiungiRigaTabella(grafico* G){
    graficoTabella->aggiungiRiga(G);
}

void MainWindow::aggiungiColonnaTabella(grafico* G){
    graficoTabella->aggiungiColonna(G);
}

void MainWindow::setController(Controller* c){
    graficoTabella->setController(c);
    controller = c;
    connect(pieChart, SIGNAL(clicked()), controller, SLOT(createTorta()));
    connect(histogram, SIGNAL(clicked()), controller, SLOT(createIstogramma()));
    connect(barChart, SIGNAL(clicked()), controller, SLOT(createBarre()));
    connect(lineChart, SIGNAL(clicked()), controller, SLOT(createLinea()));
    connect(dispersionChart, SIGNAL(clicked()), controller, SLOT(createDispersione()));

    connect(file->actions()[0], SIGNAL(triggered()), controller, SLOT(nuovo()));
    connect(file->actions()[1], SIGNAL(triggered()), controller, SLOT(open()));
    connect(file->actions()[2], SIGNAL(triggered()), controller, SLOT(save()));
    connect(file->actions()[3], SIGNAL(triggered()), controller, SLOT(saveAs()));
}
