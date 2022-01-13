#include <string>
#include <vector>
#include "graficoPianoCartesiano.h"

graficoPianoCartesiano::graficoPianoCartesiano(std::vector<std::pair<double,double>> input): pc(input){};

graficoPianoCartesiano::graficoPianoCartesiano(){
    pc.push_back({0,0});
    setNomeAssi("Asse X", "Asse Y");
};

std::vector<std::pair<double,double>> graficoPianoCartesiano::getData()const{return pc;}

std::string graficoPianoCartesiano::getNomeAsseX()const{
    return nome_asse_x;
};

std::string graficoPianoCartesiano::getNomeAsseY()const{
    return nome_asse_y;
};

void graficoPianoCartesiano::setNomeAssi(std::string x,std::string y){
    nome_asse_x = x;
    nome_asse_y = y;
};
