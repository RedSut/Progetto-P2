#include "istogramma.h"

istogramma::istogramma(std::string t,std::vector<std::string> l,std::vector<double> v, std::string dd, std::string ds) : graficoSemplice(t,l,v), nomeValori(dd), nomeLegenda(ds){
    try{
        checkDuplicates(l);
    }
    catch(graficoException& e){
        throw e;
    }
}


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

void istogramma::setLegenda(std::vector<std::string> l){
    try{
        checkDuplicates(l);
        graficoSemplice::setLegenda(l);
    }
    catch(graficoException& e){
        throw e;
    }
};

void istogramma::checkDuplicates(std::vector<std::string> l) const{
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
