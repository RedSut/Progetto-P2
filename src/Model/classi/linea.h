#ifndef LINEA_H
#define LINEA_H

#include <string>
#include <vector>
#include "graficoPianoCartesiano.h"

class linea : public graficoPianoCartesiano{
    public:
        linea(std::vector<std::pair<double,double>>);
};

#endif