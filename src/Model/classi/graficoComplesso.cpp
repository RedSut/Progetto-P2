#include <string>
#include <vector>
#include <tuple>
#include "graficoComplesso.h"

//graficoComplesso::graficoComplesso(std::vector<std::pair<std::string,graficoSemplice>> input): c(input){};
graficoComplesso::graficoComplesso(std::vector<std::tuple<std::string,std::string,double>> input): c(input){};

/*std::vector<std::pair<std::string,graficoSemplice>> graficoComplesso::getData()const{
    return c;
}*/
std::vector<std::tuple<std::string,std::string,double>> graficoComplesso::getData()const{
    return c;
}

