#ifndef GRAFICO_COMPLESSO
#define GRAFICO_COMPLESSO

#include "graficoSemplice.h"

class graficoComplesso: public graficoSemplice{
    private:
        std::vector<std::string> gruppi;
    public:
        graficoComplesso(std::string,std::vector<std::string>,std::vector<double>,std::vector<std::string>);
        std::vector<std::string> getGruppi()const;
        void setGruppi(std::vector<std::string>);

        void checkSize()const;
        
};

#endif
