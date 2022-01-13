#ifndef BARRE_H
#define BARRE_H

#include <string>
#include <tuple>
#include "graficoComplesso.h"

class barre: public graficoComplesso{
    private:
        std::string nome_asse_x;
        std::string nome_asse_y;
    public:
        //barre(std::vector<std::pair<std::string,graficoSemplice>>);
        barre(std::vector<std::tuple<std::string,std::string,double>>);
        barre();
        std::string getNomeAsseX() const;
        std::string getNomeAsseY() const;
        void setNomeAssi(std::string,std::string);
};

#endif