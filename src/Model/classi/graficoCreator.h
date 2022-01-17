#ifndef GRAFICO_CREATOR_H
#define GRAFICO_CREATOR_H

#include "barre.h"
#include "istogramma.h"
#include "linea.h"
#include "dispersione.h"
#include "torta.h"

class graficoCreator{
    public:
        barre* createBarre(std::string = "Titolo",std::vector<std::string> = {""},std::vector<double> = {0.00},std::vector<std::string> = {""}, std::string = "", std::string = "") const;
        istogramma* createIstogramma(std::string = "Titolo",std::vector<std::string> = {""},std::vector<double> = {0.00}, std::string dd ="", std::string ds= "") const;
        linea* createLinea(std::string = "Titolo",std::vector<std::pair<double,double>> = {{0.00,0.00}},std::string = "",std::string = "") const;
        dispersione* createDispersione(std::string = "Titolo",std::vector<std::pair<double,double>> = {{0.00,0.00}},std::string = "",std::string = "") const;
        torta* createTorta(std::string = "Titolo",std::vector<std::string> = {""},std::vector<double> = {0.00}) const;
};

#endif
