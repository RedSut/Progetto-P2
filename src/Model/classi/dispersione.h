#ifndef DISPERSIONE_H
#define DISPERSIONE_H

#include <string>
#include <vector>
#include "graficoPianoCartesiano.h"

class dispersione: public graficoPianoCartesiano{
    public:
        dispersione();
        dispersione(std::vector<std::pair<double,double>>);
        std::vector<double> regressioneLineare();
};

#endif