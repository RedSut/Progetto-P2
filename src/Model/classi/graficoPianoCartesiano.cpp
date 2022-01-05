#include <string>
#include <vector>
#include "graficoPianoCartesiano.h"

graficoPianoCartesiano::graficoPianoCartesiano(std::vector<std::pair<double,double>> input): pc(input){};


std::vector<std::pair<double,double>> graficoPianoCartesiano::getData()const{return pc;}

