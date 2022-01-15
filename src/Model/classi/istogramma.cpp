#include <string>
#include <vector>
#include "istogramma.h"

//istogramma::istogramma(std::vector<std::pair<std::string,double>> input): graficoSemplice(input){};

/*istogramma::istogramma(){
    graficoSemplice();
    setNomeDati("Categorie","Valori");
};*/

istogramma::istogramma(std::string t,std::vector<std::string> l,std::vector<double> v, std::string dd, std::string ds) : graficoSemplice(t,l,v), nomeDatoDouble(dd), nomeDatoString(ds){};


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