#include "mainwindow.h"
#include "ui_mainwindow.h"


QMenuBar * MainWindow::AddMenuBar()
{
    QMenuBar* menuBar= new QMenuBar(this);
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
    return menuBar;
}

QHBoxLayout* MainWindow::AddButtons()
{
    QHBoxLayout* buttonLayout = new QHBoxLayout;


    QPushButton* pieChart= new QPushButton("Grafico a torta");
    QPushButton* histogram= new QPushButton("Istogramma");
    QPushButton* barChart= new QPushButton("Grafico a barre");
    QPushButton* lineChart= new QPushButton("Piano cartesiano");
    QPushButton* dispersionChart= new QPushButton("Grafico a dispersione");

    pieChart->setStyleSheet("background-image: url(piechart.gif); width: 200px; font-size: 25px; border-radius: 1.5em; height: 200px; border: 2px solid black;" );
    histogram->setStyleSheet("background-image: url(histogram.png); background-repeat: norepeat; background-position: central; width: 200px; font-size: 25px; border: 2px solid black; border-radius: 1.5em; height: 200px;");
    barChart->setStyleSheet("background-image: url(barchart.png); width: 200px; font-size: 25px; border-radius: 1.5em; height: 200px; border: 2px solid black;");
    lineChart->setStyleSheet("background-image: url(linechart.png); width: 200px; font-size: 25px; border-radius: 1.5em; height: 200px; border: 2px solid black;");
    dispersionChart->setStyleSheet("background-image: url(chart.png); width: 200px; font-size: 20px; border-radius: 1.5em; height: 200px; border: 2px solid black;");
    buttonLayout->addWidget(pieChart);
    buttonLayout->addWidget(histogram);
    buttonLayout->addWidget(barChart);
    buttonLayout->addWidget(lineChart);
    buttonLayout->addWidget(dispersionChart);
    buttonLayout->setSpacing(50);
    buttonLayout->setContentsMargins(50, 20, 50, 20);
    buttonLayout->setAlignment(Qt::AlignCenter);
    //connect(pieChart, SIGNAL(clicked()), secondary, SLOT(crea()));
    return buttonLayout;
}

MainWindow::MainWindow(QWidget *parent): QWidget(parent){
    QVBoxLayout* mainLayout = new QVBoxLayout;

    QMenuBar* menuBar = AddMenuBar();

    setStyleSheet("background-color: MediumPurple;");
    mainLayout->addWidget(menuBar);


    QHBoxLayout* buttonLayout=AddButtons();
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
    resize(QSize(1024, 720));
}

MainWindow::~MainWindow()
{
    delete ui;
}

