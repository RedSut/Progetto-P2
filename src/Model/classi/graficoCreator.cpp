#include "graficoCreator.h"

/*barre* graficoCreator::createBarre()const{
    return new barre();
}*/

istogramma* graficoCreator::createIstogramma(std::string t,std::vector<std::string> l,std::vector<double> d, std::string dd, std::string ds)const{
    return new istogramma(t,l,d,dd,ds);
}

torta* graficoCreator::createTorta(std::string t,std::vector<std::string> l,std::vector<double> d)const{
    return new torta(t,l,d);
}

/*dispersione* graficoCreator::createDispersione()const{
    return new dispersione();
}

linea* graficoCreator::createLinea()const{
    return new linea();
}
*/