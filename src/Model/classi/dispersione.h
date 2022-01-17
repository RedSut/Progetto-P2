#ifndef DISPERSIONE_H
#define DISPERSIONE_H

#include "graficoPianoCartesiano.h"

class dispersione: public graficoPianoCartesiano{
    public:
        dispersione(std::string,std::vector<std::pair<double,double>>,std::string,std::string);
        std::vector<double> regressioneLineare();
};

#endif