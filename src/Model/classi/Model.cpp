#include "Model.h"

Model::Model(){
    createGrafico(Model::torta); // default
}
Model::~Model(){
    delete G;
}
/*
void Model::createGraficoTorta(){
    graficoCreator* gc;
    G = gc->createTorta();
}

void Model::createGraficoIstogramma(){
    graficoCreator* gc;
    G = gc->createIstogramma();
};

void Model::createGraficoBarre(){
    graficoCreator* gc;
    G = gc->createBarre();
};

void Model::createGraficoLinea(){
    graficoCreator* gc;
    G = gc->createLinea();
};
        
void Model::createGraficoDispersione(){
    graficoCreator* gc;
    G = gc->createDispersione();
};*/

void Model::createGrafico(int t){
    graficoCreator* gc;
    switch(t){
        case 0: G = gc->createTorta(); break;
        case 1: G = gc->createIstogramma(); break;
        case 2: G = gc->createBarre(); break;
        case 3: G = gc->createLinea(); break;
        case 4: G = gc->createDispersione(); break;
        default: G = gc->createTorta();
    }
}

void Model::setGrafico(grafico& g){
    G = &g;
}

grafico* Model::getGrafico()const{
    return G;
}