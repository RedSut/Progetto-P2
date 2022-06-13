#ifndef ISTOGRAMMA_H
#define ISTOGRAMMA_H

#include "graficoSemplice.h"

class istogramma : public graficoSemplice{
    private:
        std::string nomeValori;
        std::string nomeLegenda;
    public:
        istogramma(std::string t,std::vector<std::string> l,std::vector<double> v, std::string dd, std::string ds);
        
        std::string getNomeValori() const;
        std::string getNomeLegenda() const;
        void setNomeValori(std::string);
        void setNomeLegenda(std::string);
};

#endif
