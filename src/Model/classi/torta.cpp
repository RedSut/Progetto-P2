#include "torta.h"

torta::torta(std::string t,std::vector<std::string> l,std::vector<double> v): graficoSemplice(t,l,v){
    try{
        checkNegative(v);
    }
    catch(graficoException& e){
        throw e;
    }
};

void torta::setValori(std::vector<double> v){
    try{
        if(!checkNegative(v)){
            graficoSemplice::setValori(v);
        }
        return;
    }
    catch(graficoException& e){
        throw e;
    }
}

std::vector<double> torta::getValoriInPercentage() const{
    double somma = 0;
    std::vector<double> d1 = graficoSemplice::getValori();
    for(auto it = d1.begin(); it != d1.end(); ++it){
        somma+=*it;
    }
    for(auto it = d1.begin(); it != d1.end(); ++it){
        (*it) = ((*it)/somma)*100;
    }
    return d1;
};

bool torta::checkNegative(std::vector<double> s) const {
    for(auto it = s.begin(); it != s.end(); ++it){
        if(*it < 0){ 
            throw graficoException("Impossibile creare il grafico a torta: sono presenti valori negativi!", graficoException::INVALID_FORMAT);
            return true; 
        }
    }
    return false;
};