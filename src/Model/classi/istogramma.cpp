#include <string>
#include <vector>
#include "istogramma.h"

istogramma::istogramma(std::string t,std::vector<std::string> l,std::vector<double> v, std::string dd, std::string ds) : graficoSemplice(t,l,v), nomeDati(dd), nomeLegenda(ds){};


std::string istogramma::getNomeDati() const{
    return nomeDati;
};

void istogramma::setNomeDati(std::string nd){
    nomeDati = nd;
};

std::string istogramma::getNomeLegenda() const{
    return nomeLegenda;
};

void istogramma::setNomeLegenda(std::string nl){
    nomeLegenda = nl;
};
