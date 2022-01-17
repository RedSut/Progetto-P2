#include "torta.h"

torta::torta(std::string t,std::vector<std::string> l,std::vector<double> v): graficoSemplice(t,l,v){};

std::vector<double> torta::getValoriInPercentage() const{
    double somma = 0;
    std::vector<double> d1 = graficoSemplice::getValori();
    if(checkNegative()){
        return d1;
    }
    for(auto it = d1.begin(); it != d1.end(); ++it){
        somma+=*it;
    }
    for(auto it = d1.begin(); it != d1.end(); ++it){
        (*it) = ((*it)/somma)*100;
    }
    return d1;
};

bool torta::checkNegative() const {
    std::vector<double> s = graficoSemplice::getValori();
    for(auto it = s.begin(); it != s.end(); ++it){
        if(*it < 0){ return true; }
    }
    return false;
};