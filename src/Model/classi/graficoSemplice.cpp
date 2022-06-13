#include "graficoSemplice.h"

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

void graficoSemplice::checkSize()const{
    if(graficoSemplice::getLegenda().size() != graficoSemplice::getValori().size()){
        throw graficoException("Il numero di elementi nell'array legenda e nell'array valori deve essere uguale!",graficoException::WRONG_SIZE);
    }
}

void graficoSemplice::checkDuplicates() const{
    std::vector<std::string> l = getLegenda();
    for(unsigned int n=0; n<l.size(); n++){
        std::string s = l.at(n);
        for(auto it=l.begin()+n+1;it!=l.end(); it++){
            if(*it == s){
                std::string err = "Le categorie non possono contenere duplicati!\nLa categoria \"" + s + "\" è già definita!";
                throw graficoException(err,graficoException::DUPLICATED);
            }
        }
    }
};
