#include "graficoComplesso.h"

graficoComplesso::graficoComplesso(std::string tit,std::vector<std::string> leg,std::vector<double> val,std::vector<std::string> cat): graficoSemplice(tit,leg,val), categorie(cat){};

std::vector<std::string> graficoComplesso::getCategorie()const{
    return categorie;
};

void graficoComplesso::setCategorie(std::vector<std::string> cat){
    categorie = cat;
};

