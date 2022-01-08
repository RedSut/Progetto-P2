#ifndef BARRE_H
#define BARRE_H

#include <string>
#include "graficoComplesso.h"

class barre: public graficoComplesso{
    private:
        std::string nome_asse_x;
        std::string nome_asse_y;
    public:
        barre(std::map<std::string,std::map<std::string,double>>);
        std::string getNomeAsseX() const;
        std::string getNomeAsseY() const;
        void setNomeAssi(std::string,std::string);
};

#endif