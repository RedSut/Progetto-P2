#ifndef GRAFICO_SEMPLICE_H
#define GRAFICO_SEMPLICE_H

#include <vector>
#include <list>
#include <string>
#include "grafico.h"

class graficoSemplice : public grafico{
    private:
        std::string titolo;
        //std::vector<std::pair<std::string,double>> s;
        std::vector<std::string> legenda;
        std::vector<double> valori;
    public:
        graficoSemplice(std::string,std::vector<std::string>,std::vector<double>);
        //graficoSemplice(std::vector<std::pair<std::string,double>>);

        //std::vector<std::pair<std::string,double>> getData() const;
        
        virtual std::string getTitolo()const override;

        virtual std::map<std::string,std::string> getInfo()const override;

        std::vector<std::string> getLegenda()const;

        std::vector<double> getValori()const;

        //void modifyData(unsigned int,std::string,double);
        //void setData(std::vector<std::pair<std::string,double>>);
        //const graficoSemplice& graficoSemplice::getGrafico();

        //void loadDataFromJSON(const QJsonObject&); // JSON input
        //void saveDataToJSON(QJsonObject&) const; // JSON output
};

#endif