#include <map>
#include <string>
#include "graficoSemplice.h"

//COSTRUTTORI

graficoSemplice::graficoSemplice(std::map<std::string,double> input): s(input){};

//METODI

std::map<std::string,double> graficoSemplice::getData() const {return s;};
