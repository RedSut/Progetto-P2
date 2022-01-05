#ifndef TORTA_H
#define TORTA_H

#include <map>
#include <string>
#include "graficoSemplice.h"

class torta : public graficoSemplice{
    private:
        std::map<std::string,double> p;
    public:
        torta(std::map<std::string,double>);
        std::map<std::string,double> getDataInPercentage() const;
        bool checkNegative() const;
};

#endif