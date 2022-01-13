#include "graficoCreator.h"

barre* graficoCreator::createBarre()const{
    return new barre();
}

istogramma* graficoCreator::createIstogramma()const{
    return new istogramma();
}

torta* graficoCreator::createTorta()const{
    return new torta();
}

dispersione* graficoCreator::createDispersione()const{
    return new dispersione();
}

linea* graficoCreator::createLinea()const{
    return new linea();
}
