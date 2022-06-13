#ifndef GRAFICO_CREATOR_H
#define GRAFICO_CREATOR_H

#include "barre.h"
#include "istogramma.h"
#include "linea.h"
#include "dispersione.h"
#include "torta.h"

class graficoCreator{
    public:
        barre* createBarre(std::string = "Titolo",std::vector<std::string> = {"Categoria 1"},std::vector<double> = {0.00},std::vector<std::string> = {"Gruppo 1"}, std::string = "Gruppi", std::string = "Valori") const;
        istogramma* createIstogramma(std::string = "Titolo",std::vector<std::string> = {""},std::vector<double> = {0.00}, std::string dd ="Valori", std::string ds= "Categorie") const;
        linea* createLinea(std::string = "Titolo",std::vector<std::pair<double,double>> = {{0.00,0.00}},std::string = "Asse X",std::string = "Asse Y") const;
        dispersione* createDispersione(std::string = "Titolo",std::vector<std::pair<double,double>> = {{0.00,0.00}},std::string = "Asse X",std::string = "Asse Y") const;
        torta* createTorta(std::string = "Titolo",std::vector<std::string> = {""},std::vector<double> = {0.00}) const;
};

#endif
