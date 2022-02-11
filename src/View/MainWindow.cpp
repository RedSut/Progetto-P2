#include "MainWindow.h"
#include "Controller.h"

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

    modifica= new QMenu("Modifica",menuBar);
    menuBar->addMenu(modifica);
    modifica->addAction(new QAction("Aggiungi righe",modifica));
    modifica->addAction(new QAction("Rimuovi righe",modifica));
    modifica->addAction(new QAction("Aggiungi colonne",modifica));
    modifica->addAction(new QAction("Rimuovi colonne",modifica));
    modifica->addAction(new QAction("Rinomina", modifica));

    menuBar->setStyleSheet("QMenuBar {background-color: #FFA62B; color:black;}\n"
                           "QMenu {background-color: #FFA62B; color:black;}\n"
                           "QMenu::item:selected {color: white}");
    menuBar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

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
    mainLayout->addWidget(menuBar);

    //QVBoxLayout* fileLayout = new QVBoxLayout

    nomeFileAperto = "untitled.json";
    displayFileName = new QLabel;
    QString f = "File aperto: ";
    f.append(nomeFileAperto);
    displayFileName->setText(f);
    displayFileName->setAlignment(Qt::AlignCenter);
    displayFileName->setStyleSheet("background-color: #EDDEA4; color: black; font-size: 15px; padding: 5px 3px;"); //#F4E9CD #7A2A29
    mainLayout->addWidget(displayFileName);
    displayFileName->hide();

    QWidget* home = new QWidget(pagine);
    QWidget* pulsanti = new QWidget(home);
    buttons = addMainButtons();
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
    setStyleSheet("QWidget{background-color: #0A2342; color:white;}\n"
                  "QPushButton{background-color: #FFA62B; color: black;}\n"); //#FE5F00 #0A2342 #FE621D
    resize(QSize(1280, 775));
}

MainWindow::~MainWindow(){
    delete pagine;
    delete menuBar;
}

void MainWindow::goToFirstPage(){
    if(pagine->currentIndex() == 1){
        QMessageBox msgBox(QMessageBox::Warning, tr("Attenzione!"),tr("Perderai tutte le modifiche non salvate"), 0, this);
        msgBox.addButton(tr("Continua"), QMessageBox::AcceptRole);
        msgBox.addButton(tr("Annulla"), QMessageBox::RejectRole);
        if (msgBox.exec() == QMessageBox::AcceptRole){
            nomeFileAperto = "untitled.json";
            displayFileName->hide();
            pagine->setCurrentIndex(0);
        }
    }
}

void MainWindow::goToSecondPage(){
    pagine->setCurrentIndex(1);    
    QString f = "File aperto: ";
    f.append(nomeFileAperto);
    displayFileName->setText(f);
    displayFileName->show();
}

void MainWindow::setGrafico(grafico* G){
    graficoTabella->populateTable(G);
    graficoWidget->updateGrafico(G);
};

void MainWindow::updateGraficoFromTable(grafico* G){
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

void MainWindow::addRighe(grafico* G){
    if(pagine->currentIndex() == 1){
        int n = QInputDialog::getInt(this, tr("Aggiungere righe"),tr("Numero di righe da aggiungere"));
        for(int i=0;i<n;i++){
            aggiungiRigaTabella(G);
        }
    }
    else{
        QMessageBox::warning(this,"Attenzione!","Nessun grafico selezionato! \n Scegli prima un grafico!");
    }
}

void MainWindow::aggiungiColonnaTabella(grafico* G){
    graficoTabella->aggiungiColonna(G);
}


void MainWindow::addColonne(grafico* G){
    if(pagine->currentIndex() == 0){
        QMessageBox::warning(this,"Attenzione!","Nessun grafico selezionato! \n Scegli prima un grafico!");
    }
    else if(dynamic_cast<barre*>(G)){
        int n = QInputDialog::getInt(this, tr("Aggiungere colonne"),tr("Numero di colonne da aggiungere"));
        for(int i=0;i<n;i++){
            aggiungiColonnaTabella(G);
        }
    }
    else{
        QMessageBox::warning(this,"Attenzione!","Al grafico corrente non possono essere aggiunte colonne!");
    }
}

void MainWindow::rimuoviRigaTabella(){
    graficoTabella->rimuoviRiga();
}

void MainWindow::removeRighe(){
    if(pagine->currentIndex() == 1){
        int n = QInputDialog::getInt(this, tr("Rimuovore righe"),tr("Numero di righe da rimuovere"));
        for(int i=0;i<n;i++){
            rimuoviRigaTabella();
        }
    }
    else{
        QMessageBox::warning(this,"Attenzione!","Nessun grafico selezionato! \n Scegli prima un grafico!");
    }
}

void MainWindow::rimuoviColonnaTabella(){
    graficoTabella->rimuoviColonna();
}

void MainWindow::removeColonne(grafico* G){
    if(pagine->currentIndex() == 0){
        QMessageBox::warning(this,"Attenzione!","Nessun grafico selezionato! \n Scegli prima un grafico!");
    }
    else if(dynamic_cast<barre*>(G)){
        int n = QInputDialog::getInt(this, tr("Aggiungere colonne"),tr("Numero di colonne da aggiungere"));
        for(int i=0;i<n;i++){
            rimuoviColonnaTabella();
        }
    }
    else{
        QMessageBox::warning(this,"Attenzione!","Al grafico corrente non possono essere aggiunte colonne!");
    }
}

void MainWindow::modificaSezioneVTabella(int i, grafico* G){
    graficoTabella->modificaSezioneV(i,G);
}

void MainWindow::modificaSezioneHTabella(int i, grafico* G){
    graficoTabella->modificaSezioneH(i,G);
}

void MainWindow::updateRegressioneLineare(){
    graficoTabella->updateRegLin();
    graficoWidget->updateRegLin();
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

    connect(modifica->actions()[0], SIGNAL(triggered()), controller, SLOT(addNumeroRighe()));
    connect(modifica->actions()[1], SIGNAL(triggered()), controller, SLOT(removeNumeroRighe()));
    connect(modifica->actions()[2], SIGNAL(triggered()), controller, SLOT(addNumeroColonne()));
    connect(modifica->actions()[3], SIGNAL(triggered()), controller, SLOT(removeNumeroColonne()));
    connect(modifica->actions()[4], SIGNAL(triggered()), controller, SLOT(rinomina()));


}

void MainWindow::openFile(graficoJSON* GJson){
    /*bool flag = true;
    if(pagine->currentIndex() == 1){
        QMessageBox msgBox(QMessageBox::Warning, tr("Attenzione!"),tr("Perderai tutte le modifiche non salvate"), 0, this);
        msgBox.addButton(tr("Continua"), QMessageBox::AcceptRole);
        msgBox.addButton(tr("Annulla"), QMessageBox::RejectRole);
        if (msgBox.exec() == QMessageBox::RejectRole){
            flag = false;
        }
    }
    if(pagine->currentIndex() == 0 || flag){*/
        nomeFileAperto = QFileDialog::getOpenFileName(this, tr("Apri il file"), "", tr("File JSON (*.json)"));
        if (nomeFileAperto == ""){
            QMessageBox::warning(this,"Attenzione!","File scelto non valido");
            nomeFileAperto = "untitled.json";
        }else{
            QFile file(nomeFileAperto);
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
    //}
}

void MainWindow::saveFileAs(graficoJSON* GJson){
    if(pagine->currentIndex() == 1){
        nomeFileAperto = QFileDialog::getSaveFileName(this, tr("Salva il file"), "", tr("File JSON (*.json)"));
        if (nomeFileAperto == ""){
            QMessageBox::warning(this,"Attenzione!","File non salvato!");
        }else{
            QJsonObject o1;
            GJson->saveDataToJSON(o1);
            QJsonDocument d1;
            d1.setObject(o1);
            QFile file(nomeFileAperto);
            if(file.open(QFile::WriteOnly | QFile::Text)){
                file.write(d1.toJson());
            }else{
                QMessageBox::information(this, tr("ERRORE"), tr("Impossibile scrivere sul file!"));
            }
        }
    }else{
        QMessageBox::information(this, tr("Attenzione!"), tr("Nessun file aperto!"));
    }
}

void MainWindow::saveFile(graficoJSON* GJson){
    if(pagine->currentIndex() == 1){
        if(nomeFileAperto != "untitled.json"){
            QJsonObject o1;
            GJson->saveDataToJSON(o1);
            QJsonDocument d1;
            d1.setObject(o1);
            QFile file(nomeFileAperto);
            if(file.open(QFile::WriteOnly | QFile::Text)){
                file.write(d1.toJson());
            }else{
                QMessageBox::information(this, tr("ERRORE"), tr("Impossibile scrivere sul file!"));
            }
        }else{
            saveFileAs(GJson);
        }
    }else{
        QMessageBox::information(this, tr("Attenzione!"), tr("Nessun file aperto!"));
    }
}
