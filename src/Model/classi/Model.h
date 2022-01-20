#ifndef MODEL_H
#define MODEL_H

#include "grafico.h"
#include "graficoCreator.h"

class Model{
    private:
        grafico* G;
    public:
        Model();
        ~Model();
        void createGraficoTorta();
        void createGraficoIstogramma();
        void createGraficoBarre();
        void createGraficoLinea();
        void createGraficoDispersione();

        grafico* getGrafico()const;
};


#endif