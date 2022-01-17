#include "graficoPianoCartesiano.h"

graficoPianoCartesiano::graficoPianoCartesiano(std::string t,std::vector<std::pair<double,double>> p,std::string nx,std::string ny){
    titolo = t;
    punti = p;
    nome_asse_x = nx;
    nome_asse_y = ny;
};

std::string graficoPianoCartesiano::getTitolo()const{
    return titolo;
}

void graficoPianoCartesiano::setTitolo(std::string t){
    titolo = t;
}

std::vector<std::pair<double,double>> graficoPianoCartesiano::getPunti()const{
    return punti;
}

void graficoPianoCartesiano::setPunti(std::vector<std::pair<double,double>> p){
    punti = p;
    return;
}

std::string graficoPianoCartesiano::getNomeAsseX()const{
    return nome_asse_x;
};

std::string graficoPianoCartesiano::getNomeAsseY()const{
    return nome_asse_y;
};

void graficoPianoCartesiano::setNomeAsseX(std::string x){
    nome_asse_x = x;
};

void graficoPianoCartesiano::setNomeAsseY(std::string y){
    nome_asse_y = y;
};