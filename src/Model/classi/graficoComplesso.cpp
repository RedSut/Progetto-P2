#include <string>
#include <map>
#include "graficoComplesso.h"

graficoComplesso::graficoComplesso(std::map<std::string,std::map<std::string,double>> input): c(input){};

std::map<std::string,std::map<std::string,double>> graficoComplesso::getData()const{
    return c;
}


