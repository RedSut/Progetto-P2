#ifndef TORTA_H
#define TORTA_H

#include <vector>
#include <string>
#include "graficoSemplice.h"

class torta : public graficoSemplice{
    public:
        torta(std::string,std::vector<std::string>,std::vector<double>);
        //torta(std::vector<std::pair<std::string,double>>);
        
        //std::vector<std::pair<std::string,double>> getDataInPercentage() const;
        //bool checkNegative() const;
};

#endif