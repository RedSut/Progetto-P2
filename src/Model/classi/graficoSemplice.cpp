#include "graficoSemplice.h"

//COSTRUTTORI

graficoSemplice::graficoSemplice(std::string tit,std::vector<std::string> leg,std::vector<double> val){
    titolo = tit;
    legenda = leg;
    valori = val;
};

std::string graficoSemplice::getTitolo()const{
    return titolo;
};

void graficoSemplice::setTitolo(std::string t){
    titolo = t;
};

/*std::map<std::string,std::string> graficoSemplice::getInfo()const{ // NON SO SE PUO' SERVIRE
    std::map<std::string,std::string> m;
    m.insert({"titolo",titolo});
    return m;
};*/

std::vector<std::string> graficoSemplice::getLegenda()const{
    return legenda;
}

void graficoSemplice::setLegenda(std::vector<std::string> l){
    legenda = l;
};

std::vector<double> graficoSemplice::getValori()const{
    return valori;
}

void graficoSemplice::setValori(std::vector<double> v){
    valori = v;
}