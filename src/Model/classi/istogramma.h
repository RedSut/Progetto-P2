#ifndef ISTOGRAMMA_H
#define ISTOGRAMMA_H

#include <string>
#include <vector>
#include "graficoSemplice.h"

class istogramma : public graficoSemplice{
    private:
        std::string nomeDatoDouble;
        std::string nomeDatoString;
    public:
        //istogramma()
        istogramma(std::string t,std::vector<std::string> l,std::vector<double> v, std::string dd, std::string ds);
        //istogramma(std::vector<std::pair<std::string,double>>);
        std::string getNomeDatoDouble() const;
        std::string getNomeDatoString() const;
        void setNomeDati(std::string,std::string);
};

#endif