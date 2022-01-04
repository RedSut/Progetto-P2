#include <map>
#include <string>
#include "torta.h"

torta::torta(std::map<std::string,double> input): graficoSemplice(input){};


std::map<std::string,double> torta::getDataInPercentage() const{
    double somma=0;
    std::map<std::string,double> d1 = graficoSemplice::getData();
    if(checkNegative()){
        return d1;
    }
    for(auto it = d1.begin(); it != d1.end(); ++it){
        somma+=it->second;
    }
    for(auto it = d1.begin(); it != d1.end(); ++it){
        it->second = (it->second/somma)*100;
    }
    return d1;
};

bool torta::checkNegative() const {
    std::map<std::string,double> s = graficoSemplice::getData();
    for(auto it = s.begin(); it != s.end(); ++it){
        if(it->second<0){return true;}
    }
    return false;
};