#ifndef GRAFICO_COMPLESSO
#define GRAFICO_COMPLESSO

#include <string>
#include <map>
#include "grafico.h"

class graficoComplesso: public grafico{
    private:
        std::map<std::string,std::map<std::string,double>> c;
    public:
        graficoComplesso(std::map<std::string,std::map<std::string,double>>);
        std::map<std::string,std::map<std::string,double>> getData()const;
};

#endif