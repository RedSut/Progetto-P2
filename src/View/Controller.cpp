#include "Controller.h"

Controller::Controller(QObject* parent): QObject(parent){

}

void Controller::setModel(Model* M){
    model = M;
}

void Controller::setView(MainWindow* W){
    mainWin = W;
}

void Controller::createTorta() const{
    model->createGrafico(Model::torta);
    grafico* G = model->getGrafico();
    mainWin->setGrafico(G);
    mainWin->goToSecondPage();
}

void Controller::createIstogramma() const{
    model->createGrafico(Model::istogramma);
    grafico* G = model->getGrafico();
    mainWin->setGrafico(G);
    mainWin->goToSecondPage();
}
void Controller::createBarre() const{
    model->createGrafico(Model::barre);
    grafico* G = model->getGrafico();
    mainWin->setGrafico(G);
    mainWin->goToSecondPage();
}
void Controller::createLinea() const{
    model->createGrafico(Model::linea);
    grafico* G = model->getGrafico();
    mainWin->setGrafico(G);
    mainWin->goToSecondPage();
}
void Controller::createDispersione() const{
    model->createGrafico(Model::dispersione);
    grafico* G = model->getGrafico();
    mainWin->setGrafico(G);
    mainWin->goToSecondPage();
}

void Controller::aggiornaGrafico(){
    grafico* G = model->getGrafico();
    mainWin->updateGraficoFromTable(G);
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

void Controller::updateRegressioneLineare(){
    mainWin->updateRegressioneLineare();
}

void Controller::updateOrdinaPuntiFlag(){
    mainWin->updateOrdinaPuntiTabella();
}

void Controller::nuovo() const{
    mainWin->goToFirstPage();
}

void Controller::open() const{
    graficoJSON* GJson = new graficoJSON(model);
    mainWin->openFile(GJson);
}


void Controller::save() const{
    graficoJSON* GJson = new graficoJSON(model);
    mainWin->saveFile(GJson);
}


void Controller::saveAs() const{
    graficoJSON* GJson = new graficoJSON(model);
    mainWin->saveFileAs(GJson);
}

void Controller::close() const{
    mainWin->closeApp();
}


void Controller::addNumeroRighe() const{
    grafico* G = model->getGrafico();
    mainWin->addRighe(G);
}

void Controller::removeNumeroRighe() const{
    mainWin->removeRighe();
}

void Controller::addNumeroColonne() const{
    grafico* G = model->getGrafico();
    mainWin->addColonne(G);
}

void Controller::removeNumeroColonne() const{
    grafico* G = model->getGrafico();
    mainWin->removeColonne(G);
}

void Controller::rinomina() const{
    grafico* G = model->getGrafico();
    mainWin->rename(G);
}
