#ifndef GRAFICO_CREATOR_H
#define GRAFICO_CREATOR_H

#include "barre.h"
#include "istogramma.h"
#include "linea.h"
#include "dispersione.h"
#include "torta.h"

class graficoCreator{
    public:
        //barre* createBarre() const;
        istogramma* createIstogramma(std::string = "Titolo",std::vector<std::string> = {""},std::vector<double> = {0.00}, std::string dd ="", std::string ds= "") const;
        //linea* createLinea() const;
        //dispersione* createDispersione() const;
        torta* createTorta(std::string = "Titolo",std::vector<std::string> = {""},std::vector<double> = {0.00}) const;
};

#endif
