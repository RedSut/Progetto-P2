#ifndef GRAFICO_COMPLESSO
#define GRAFICO_COMPLESSO

#include <string>
#include <vector>
#include <tuple>
#include "grafico.h"

class graficoComplesso: public grafico{
    private:
        //std::vector<std::pair<std::string,std::pair<std::string,double>>> c;
        std::vector<std::tuple<std::string,std::string,double>> c;
    public:
        //graficoComplesso(std::vector<std::pair<std::string,std::pair<std::string,double>>>);
        //std::vector<std::pair<std::string,std::pair<std::string,double>>> getData()const;
        graficoComplesso();
        graficoComplesso(std::vector<std::tuple<std::string,std::string,double>>);
        std::vector<std::tuple<std::string,std::string,double>> getData()const;
};

#endif