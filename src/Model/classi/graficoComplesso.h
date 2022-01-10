#ifndef GRAFICO_COMPLESSO
#define GRAFICO_COMPLESSO

#include <string>
#include <vector>
#include "graficoSemplice.h"

class graficoComplesso: public grafico{ //FORSE VA BENE ANCHE COSI' OPPRURE DERIVARE DA GRAFICO_SEMPLICE
    private:
        //std::vector<std::pair<std::string,graficoSemplice>> c;
        //std::vector<std::pair<std::string,std::pair<std::string,double>>> c;
        std::vector<std::tuple<std::string,std::string,double>> c;
    public:
        //graficoComplesso(std::vector<std::pair<std::string,graficoSemplice>>);
        //std::vector<std::pair<std::string,graficoSemplice>> getData()const;
        //graficoComplesso(std::vector<std::pair<std::string,std::pair<std::string,double>>>);
        //std::vector<std::pair<std::string,std::pair<std::string,double>>> getData()const;
        graficoComplesso(std::vector<std::tuple<std::string,std::string,double>>);
        std::vector<std::tuple<std::string,std::string,double>> getData()const;
};

#endif