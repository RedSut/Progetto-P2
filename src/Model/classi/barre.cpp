#include<string>
#include "barre.h"

barre::barre(std::map<std::string,std::map<std::string,double>> input): graficoComplesso(input){};


std::string barre::getNomeAsseX() const{
    return nome_asse_x;
}

std::string barre::getNomeAsseY() const{
    return nome_asse_y;
}

void barre::setNomeAssi(std::string nx,std::string ny){
    if(!nx.empty() && !ny.empty()){
        nome_asse_x = nx;
        nome_asse_y = ny;
    }
    return;
}