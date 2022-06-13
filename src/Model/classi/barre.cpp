#include "barre.h"

barre::barre(std::string tit,std::vector<std::string> leg,std::vector<double> val,std::vector<std::string> cat, std::string nx, std::string ny): graficoComplesso(tit,leg,val,cat){
    nome_asse_x = nx;
    nome_asse_y = ny;
}

std::string barre::getNomeAsseX() const{
    return nome_asse_x;
}

std::string barre::getNomeAsseY() const{
    return nome_asse_y;
}

void barre::setNomeAsseX(std::string nx){
    nome_asse_x = nx;
}

void barre::setNomeAsseY(std::string ny){
    nome_asse_y = ny;
}
