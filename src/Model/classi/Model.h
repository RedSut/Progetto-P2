#ifndef MODEL_H
#define MODEL_H

#include "grafico.h"
#include "graficoCreator.h"

class Model{
    private:
        grafico* G;
    public:
        enum tipologia{
            torta,
            istogramma,
            barre,
            linea,
            dispersione
        };
        Model();
        ~Model();
        /*void createGraficoTorta();
        void createGraficoIstogramma();
        void createGraficoBarre();
        void createGraficoLinea();
        void createGraficoDispersione();*/
        void createGrafico(int);

        grafico* getGrafico()const;
};


#endif