#ifndef GRAFICO_SEMPLICE_H
#define GRAFICO_SEMPLICE_H

#include <vector>
#include "grafico.h"

class graficoSemplice : public grafico{
    private:
        std::string titolo;
        std::vector<std::string> legenda;
        std::vector<double> valori;
    public:
        graficoSemplice(std::string,std::vector<std::string>,std::vector<double>);
        
        virtual std::string getTitolo()const override;
        virtual void setTitolo(std::string) override;

        std::vector<std::string> getLegenda()const;
        void setLegenda(std::vector<std::string>);

        std::vector<double> getValori()const;
        void setValori(std::vector<double>);
};

#endif