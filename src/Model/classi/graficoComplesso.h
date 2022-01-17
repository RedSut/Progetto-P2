#ifndef GRAFICO_COMPLESSO
#define GRAFICO_COMPLESSO

#include "graficoSemplice.h"

class graficoComplesso: public graficoSemplice{
    private:
        std::vector<std::string> categorie;
    public:
        graficoComplesso(std::string,std::vector<std::string>,std::vector<double>,std::vector<std::string>);
        std::vector<std::string> getCategorie()const;
        void setCategorie(std::vector<std::string>);
        
};

#endif