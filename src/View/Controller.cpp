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
}


void Controller::nuovo() const{
    
}
void Controller::open() const{
    QString fileName = QFileDialog::getOpenFileName(
                                this, tr("Apri il file"), "", tr("File JSON (*.json)"));

	if (fileName == "")
		throw std::runtime_error("Nessun file scelto");

	return fileName;
}
void Controller::save() const{

}
void Controller::saveAs() const{

}