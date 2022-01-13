#ifndef GRAFICO_CREATOR_H
#define GRAFICO_CREATOR_H

#include "barre.h"
#include "istogramma.h"
#include "linea.h"
#include "dispersione.h"
#include "torta.h"

class graficoCreator{
    public:
        barre* createBarre() const;
        istogramma* createIstogramma() const;
        linea* createLinea() const;
        dispersione* createDispersione() const;
        torta* createTorta() const;
};

#endif
