#include "Model.h"

Model::Model(){
    G = nullptr;
}
Model::~Model(){
    delete G;
}

void Model::createGrafico(int t){
    if(G != nullptr){
        delete G;
    }
    graficoCreator* gc = new graficoCreator;
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
