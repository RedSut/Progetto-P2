#include "MainWindow.h"
//#include "ui_mainwindow.h"

#include "Controller.h"
#include <QSize>
#include <iostream>


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


    menuBar->setStyleSheet("QMenuBar {background-color: #FFA62B; color:black;}\n"
                           "QMenu {background-color: #FFA62B; color:black;}\n"
                           "QMenu::item:selected {color: white}");
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
    lineChart= new QPushButton("Grafico a linea");
    dispersionChart= new QPushButton("Grafico a dispersione");


    pieChart->setStyleSheet("background-image: url(:/img/torta); width: 220px; background-repeat: norepeat; background-position: central; font-size: 25px; border-radius: 1.5em; height: 200px; border: 2px solid black; font-weight: bold; background-color: white; background-position: bottom center; text-align: top; padding-top: 20px; color:black");
    histogram->setStyleSheet("background-image: url(:/img/istogramma); background-repeat: norepeat; background-position: central; width: 220px; font-size: 25px; border: 2px solid black; border-radius: 1.5em; height: 200px; font-weight: bold; background-color: white; background-position: bottom center; text-align: top; padding-top: 20px; color:black;");
    barChart->setStyleSheet("background-image: url(:/img/barre); width: 220px; background-repeat: norepeat; background-position: central; font-size: 25px; border-radius: 1.5em; height: 200px; border: 2px solid black; font-weight: bold; background-color: white; background-position: bottom center; text-align: top; padding-top: 20px; color:black;");
    lineChart->setStyleSheet("background-image: url(:/img/linea); width: 220px; background-repeat: norepeat; background-position: central; font-size: 23px; border-radius: 1.5em; height: 200px; border: 2px solid black; font-weight: bold; background-color: white; background-position: bottom center; text-align: top; padding-top: 20px; color:black;");
    dispersionChart->setStyleSheet("background-image: url(:/img/dispersione); background-repeat: norepeat; background-position: central; width: 220px; font-size: 18px; border-radius: 1.5em; height: 200px; border: 2px solid black; font-weight: bold; background-color: white; background-position: bottom center; text-align: top; padding-top: 20px; color:black;");
    buttonLayout->addWidget(pieChart);
    buttonLayout->addWidget(histogram);
    buttonLayout->addWidget(barChart);
    buttonLayout->addWidget(lineChart);
    buttonLayout->addWidget(dispersionChart);
    buttonLayout->setSpacing(50);
    buttonLayout->setAlignment(Qt::AlignTop);
    buttonLayout->setContentsMargins(50, 50, 50, 50);
    return buttonLayout;
}

MainWindow::MainWindow(QWidget *parent): QWidget(parent){
    QVBoxLayout* mainLayout = new QVBoxLayout;

    pagine = new QStackedWidget(this);

    addMenuBar();

    setStyleSheet("QWidget{background-color: #0A2342; color:white;}\n"
                  "QPushButton{background-color: #FFA62B; color: black;}\n"); //#FE5F00 #0A2342 #FE621D
    mainLayout->addWidget(menuBar);

    QWidget* home = new QWidget(pagine);
    QWidget* pulsanti = new QWidget(home);
    buttons = addMainButtons();
    //buttons->setMargin(100);
    pulsanti->setLayout(buttons);

    QVBoxLayout* homeLayout = new QVBoxLayout;
    QLabel* testo = new QLabel;
    testo->setText("Crea un nuovo grafico");
    testo->setStyleSheet("color: white; font-weight: bold; font-size: 40px;");
    testo->setAlignment(Qt::AlignCenter);
    testo->setMaximumHeight(200);
    testo->setContentsMargins(50,100,50,50);
    homeLayout->addWidget(testo);
    homeLayout->addWidget(pulsanti);
    homeLayout->setMargin(0);
    home->setLayout(homeLayout);

    pagine->addWidget(home);
    QWidget* b = new QWidget(pagine);   
    graficoWidget = new graficoView();
    graficoTabella = new tableView();
    QHBoxLayout* paginaGrafico = new QHBoxLayout;
    paginaGrafico->addWidget(graficoTabella);
    paginaGrafico->addWidget(graficoWidget);
    b->setLayout(paginaGrafico);
    
    pagine->addWidget(b);
    mainLayout->addWidget(pagine);
    mainLayout->setMargin(0);
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
    try{
        graficoTabella->extractTable(G);
        graficoWidget->updateGrafico(G);
        graficoTabella->populateTable(G);
    }catch(graficoException& e){
        QMessageBox::information(this, tr("ERRORE IN INPUT"), tr(e.what()));
    }
};

void MainWindow::aggiungiRigaTabella(grafico* G){
    graficoTabella->aggiungiRiga(G);
}

void MainWindow::aggiungiColonnaTabella(grafico* G){
    graficoTabella->aggiungiColonna(G);
}

void MainWindow::rimuoviRigaTabella(){
    graficoTabella->rimuoviRiga();
}
void MainWindow::rimuoviColonnaTabella(){
    graficoTabella->rimuoviColonna();
}

void MainWindow::modificaSezioneVTabella(int i, grafico* G){
    graficoTabella->modificaSezioneV(i,G);
}

void MainWindow::modificaSezioneHTabella(int i, grafico* G){
    graficoTabella->modificaSezioneH(i,G);
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

void MainWindow::openFile(graficoJSON* GJson){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Apri il file"), "", tr("File JSON (*.json)"));

    if (fileName == ""){
        QMessageBox::warning(this,"Attenzione!","File scelto non valido");
    }else{
        QFile file(fileName);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
             QString val = file.readAll();
             file.close();
             QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
             QJsonObject o = d.object();

             try{
                 GJson->loadDataFromJSON(o);
                 goToSecondPage();
                 setGrafico(GJson->getGrafico());
             }
             catch(graficoException& e){
                 QMessageBox::information(this, tr("ERRORE IN INPUT FILE JSON"), tr(e.what()));
             }
        }else{
            QMessageBox::information(this, tr("ERRORE"), tr("Impossibile aprire il file!"));
        }
    }

}

void MainWindow::saveFile(graficoJSON* GJson){

}
