#ifndef PIANO_CARTESIANO_H
#define PIANO_CARTESIANO_H

#include <vector>
#include "grafico.h"

class graficoPianoCartesiano: public grafico{
    private:
        std::string titolo;
        std::vector<std::pair<double,double>> punti;
        std::string nome_asse_x;
        std::string nome_asse_y;
    public:
        graficoPianoCartesiano(std::string,std::vector<std::pair<double,double>>,std::string,std::string);
        std::string getTitolo()const override;
        void setTitolo(std::string) override;
        std::vector<std::pair<double,double>> getPunti() const;
        void setPunti(std::vector<std::pair<double,double>>);
        std::string getNomeAsseX() const;
        std::string getNomeAsseY() const;
        void setNomeAsseX(std::string);
        void setNomeAsseY(std::string);
};

#endif