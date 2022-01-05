#include <string>
#include <map>
#include "istogramma.h"

istogramma::istogramma(std::map<std::string,double> input): graficoSemplice(input){};


std::string istogramma::getNomeDatoDouble() const{
    return nomeDatoDouble;
};

std::string istogramma::getNomeDatoString() const{
    return nomeDatoString;
};

void istogramma::setNomeDati(std::string d,std::string s){
    nomeDatoDouble = d;
    nomeDatoString = s;
};