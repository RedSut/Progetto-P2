#include<string>
#include <tuple>
#include "barre.h"

//barre::barre(std::vector<std::pair<std::string,graficoSemplice>> input): graficoComplesso(input){};
barre::barre(std::vector<std::tuple<std::string,std::string,double>> input): graficoComplesso(input){};

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