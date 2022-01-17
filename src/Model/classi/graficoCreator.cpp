#include "graficoCreator.h"

torta* graficoCreator::createTorta(std::string t,std::vector<std::string> l,std::vector<double> d)const{
    return new torta(t,l,d);
}

istogramma* graficoCreator::createIstogramma(std::string t,std::vector<std::string> l,std::vector<double> d, std::string dd, std::string ds)const{
    return new istogramma(t,l,d,dd,ds);
}

barre* graficoCreator::createBarre(std::string t,std::vector<std::string> l,std::vector<double> d,std::vector<std::string> c, std::string nx, std::string ny)const{
    return new barre(t,l,d,c,nx,ny);
}

dispersione* graficoCreator::createDispersione(std::string t,std::vector<std::pair<double,double>> p,std::string nx,std::string ny)const{
    return new dispersione(t,p,nx,ny);
}

linea* graficoCreator::createLinea(std::string t,std::vector<std::pair<double,double>> p,std::string nx,std::string ny)const{
    return new linea(t,p,nx,ny);
}