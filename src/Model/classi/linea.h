#ifndef LINEA_H
#define LINEA_H

#include <algorithm>
#include "graficoPianoCartesiano.h"

class linea : public graficoPianoCartesiano{
    public:
        linea(std::string,std::vector<std::pair<double,double>>,std::string,std::string);
        void ordinaPunti();
};

#endif