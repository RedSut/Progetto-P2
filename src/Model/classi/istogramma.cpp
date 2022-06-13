#include "istogramma.h"

istogramma::istogramma(std::string t,std::vector<std::string> l,std::vector<double> v, std::string dd, std::string ds) : graficoSemplice(t,l,v), nomeValori(dd), nomeLegenda(ds){}

std::string istogramma::getNomeValori() const{
    return nomeValori;
};

void istogramma::setNomeValori(std::string nd){
    nomeValori = nd;
};

std::string istogramma::getNomeLegenda() const{
    return nomeLegenda;
};

void istogramma::setNomeLegenda(std::string nl){
    nomeLegenda = nl;
};

