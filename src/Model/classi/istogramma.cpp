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

std::vector<double> istogramma::getNormalizedVal(){
    std::vector<double> val = graficoSemplice::getValori();
    std::vector<double> normVal;
    double somma = 0;
    for(auto it = val.begin(); it!=val.end(); it++){
        somma += *it;
    }
    for(auto it2 = val.begin(); it2!=val.end(); it2++){
        double normValue = (*it2)/somma;
        normVal.push_back(normValue);
    }
    return normVal;
};

std::vector<double> istogramma::getAccumulatedVal(){
    std::vector<double> val = getNormalizedVal();
    std::vector<double> accVal;
    double somma_par = 0;
    for(auto it = val.begin(); it!=val.end(); it++){
        double accValue = (*it) + somma_par;
        somma_par = accValue;
        accVal.push_back(accValue);
    }
    return accVal;
};
