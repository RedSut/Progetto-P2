#include "Controller.h"

Controller::Controller(QObject* parent): QObject(parent){

};

void Controller::setModel(Model* M){
    model = M;
}

void Controller::setView(MainWindow* W){
    mainWin= W;
}

void Controller::createTorta() const{
    graficoCreator* gc = new graficoCreator();
    grafico* G = gc->createTorta();
    model->setGrafico(*G);
    mainWin->setGrafico(G);
    mainWin->goToSecondPage();
}

void Controller::createIstogramma() const{
    graficoCreator* gc = new graficoCreator();
    grafico* G = gc->createIstogramma();
    model->setGrafico(*G);
    mainWin->setGrafico(G);
    mainWin->goToSecondPage();
}
void Controller::createBarre() const{
    graficoCreator* gc = new graficoCreator();
    grafico* G = gc->createBarre();
    model->setGrafico(*G);
    mainWin->setGrafico(G);
    mainWin->goToSecondPage();
}
void Controller::createLinea() const{
    graficoCreator* gc = new graficoCreator();
    grafico* G = gc->createLinea();
    model->setGrafico(*G);
    mainWin->setGrafico(G);
    mainWin->goToSecondPage();
}
void Controller::createDispersione() const{
    graficoCreator* gc = new graficoCreator();
    grafico* G = gc->createDispersione();
    model->setGrafico(*G);
    mainWin->setGrafico(G);
    mainWin->goToSecondPage();
}

void Controller::aggiornaGrafico(){
    grafico* G = model->getGrafico();
    mainWin->updateGrafico(G);
}

void Controller::aggiungiRigaTabella(){
    grafico* G = model->getGrafico();
    mainWin->aggiungiRigaTabella(G);
}

void Controller::aggiungiColonnaTabella(){
    grafico* G = model->getGrafico();
    mainWin->aggiungiColonnaTabella(G);
}

void Controller::rimuoviRigaTabella(){
   mainWin->rimuoviRigaTabella();
}

void Controller::rimuoviColonnaTabella(){
   mainWin->rimuoviColonnaTabella();
}

void Controller::modificaSezioneVTabella(int i){
    grafico* G = model->getGrafico();
    mainWin->modificaSezioneVTabella(i,G);
}

void Controller::modificaSezioneHTabella(int i){
    grafico* G = model->getGrafico();
    mainWin->modificaSezioneHTabella(i,G);
}

void Controller::nuovo() const{
    
}
void Controller::open() const{
    graficoJSON* GJson = new graficoJSON(model);
    mainWin->openFile(GJson);
}


void Controller::save() const{
    
}


void Controller::saveAs() const{
    /*QString fileName = QFileDialog::getSaveFileName(
                                this, tr("Salva il file"), "", tr("File JSON (*.json)"));

	if (fileName == "")
        QMessageBox::warning(this,"Attenzione!","File scelto non valido");*/
}
