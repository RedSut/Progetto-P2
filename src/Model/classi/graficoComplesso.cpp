#include "graficoComplesso.h"

graficoComplesso::graficoComplesso(std::string tit,std::vector<std::string> leg,std::vector<double> val,std::vector<std::string> gru): graficoSemplice(tit,leg,val), gruppi(gru){}

std::vector<std::string> graficoComplesso::getGruppi()const{
    return gruppi;
}

void graficoComplesso::setGruppi(std::vector<std::string> gru){
    gruppi = gru;
}

void graficoComplesso::checkSize()const{
    if(graficoComplesso::getValori().size() != (graficoComplesso::getGruppi().size() * graficoComplesso::getLegenda().size())){
        throw graficoException("Il numero di elementi nell'array valori deve essere il prodotto tra il numero di elementi nell'array gruppi e il numero di elementi nell'array legenda",graficoException::WRONG_SIZE);
    }
}
