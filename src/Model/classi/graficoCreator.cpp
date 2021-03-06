#include "graficoCreator.h"

torta* graficoCreator::createTorta(std::string t,std::vector<std::string> l,std::vector<double> d)const{
    torta* tr = new torta(t,l,d);
    try{
        tr->checkSize();
        return tr;
    }
    catch(graficoException& e){
        delete tr;
        throw e;
    }
}

istogramma* graficoCreator::createIstogramma(std::string t,std::vector<std::string> l,std::vector<double> d, std::string dd, std::string ds)const{
    istogramma* i = new istogramma(t,l,d,dd,ds);
    try{
        i->checkSize();
        return i;
    }
    catch(graficoException& e){
        delete i;
        throw e;
    }
}

barre* graficoCreator::createBarre(std::string t,std::vector<std::string> l,std::vector<double> d,std::vector<std::string> c, std::string nx, std::string ny)const{
    barre* b = new barre(t,l,d,c,nx,ny);
    try{
        b->checkSize();
        return b;
    }
    catch(graficoException& e){
        delete b;
        throw e;
    }
}

dispersione* graficoCreator::createDispersione(std::string t,std::vector<std::pair<double,double>> p,std::string nx,std::string ny)const{
    return new dispersione(t,p,nx,ny);
}

linea* graficoCreator::createLinea(std::string t,std::vector<std::pair<double,double>> p,std::string nx,std::string ny)const{
    return new linea(t,p,nx,ny);
}
