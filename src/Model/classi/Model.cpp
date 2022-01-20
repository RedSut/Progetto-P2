#include "Model.h"

Model::Model(){
    createGraficoTorta(); // default
}

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
};

grafico* Model::getGrafico()const{
    return G;
}