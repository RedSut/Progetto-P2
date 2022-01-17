#ifndef BARRE_H
#define BARRE_H

#include "graficoComplesso.h"

class barre: public graficoComplesso{
    private:
        std::string nome_asse_x;
        std::string nome_asse_y;
    public:
        barre(std::string,std::vector<std::string>,std::vector<double>,std::vector<std::string>,std::string,std::string);
        std::string getNomeAsseX() const;
        std::string getNomeAsseY() const;
        void setNomeAsseX(std::string);
        void setNomeAsseY(std::string);
};

#endif