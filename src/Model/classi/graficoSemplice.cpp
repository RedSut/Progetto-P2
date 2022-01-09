#include <vector>
#include <string>
#include "graficoSemplice.h"

//COSTRUTTORI

graficoSemplice::graficoSemplice(std::vector<std::pair<std::string,double>> input): s(input){};

//METODI

std::vector<std::pair<std::string,double>> graficoSemplice::getData() const {return s;};
