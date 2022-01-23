#include "graficoComplesso.h"

graficoComplesso::graficoComplesso(std::string tit,std::vector<std::string> leg,std::vector<double> val,std::vector<std::string> cat): graficoSemplice(tit,leg,val), categorie(cat){};

std::vector<std::string> graficoComplesso::getCategorie()const{
    return categorie;
};

void graficoComplesso::setCategorie(std::vector<std::string> cat){
    categorie = cat;
};

void graficoComplesso::checkSize()const{
    if(graficoComplesso::getValori().size() != (graficoComplesso::getCategorie().size() * graficoComplesso::getLegenda().size())){
        throw graficoException("Il numero di elementi nell'array valori deve essere il prodotto tra il numero di elementi nell'array categorie e il numero di elementi nell'array legenda",graficoException::WRONG_SIZE);
    }
}