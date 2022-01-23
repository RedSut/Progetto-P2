#ifndef TORTA_H
#define TORTA_H

#include "graficoSemplice.h"

class torta : public graficoSemplice{
    public:
        torta(std::string,std::vector<std::string>,std::vector<double>);
        
        void setValori(std::vector<double>);
        std::vector<double> getValoriInPercentage() const;
        bool checkNegative(std::vector<double>) const;
};

#endif