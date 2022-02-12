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

        void createGrafico(int);

        void setGrafico(grafico&);
        grafico* getGrafico()const;
};


#endif
