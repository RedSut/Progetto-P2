#ifndef PIANO_CARTESIANO_H
#define PIANO_CARTESIANO_H

#include <string>
#include <vector>
#include "grafico.h"

class graficoPianoCartesiano: public grafico{
    private:
        std::vector<std::pair<double,double>> pc;
        std::string nome_asse_x;
        std::string nome_asse_y;
    public:
        graficoPianoCartesiano(std::vector<std::pair<double,double>>);
        std::vector<std::pair<double,double>> getData() const;
};

#endif