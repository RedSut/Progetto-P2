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
        graficoPianoCartesiano();
        graficoPianoCartesiano(std::vector<std::pair<double,double>>);
        std::vector<std::pair<double,double>> getData() const;
        std::string getNomeAsseX() const;
        std::string getNomeAsseY() const;
        void setNomeAssi(std::string,std::string);
};

#endif