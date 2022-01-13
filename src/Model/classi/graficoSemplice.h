#ifndef GRAFICO_SEMPLICE_H
#define GRAFICO_SEMPLICE_H

#include <vector>
#include <string>
#include "grafico.h"

class graficoSemplice : public grafico{
    private:
        std::vector<std::pair<std::string,double>> s;
    public:
        graficoSemplice();
        graficoSemplice(std::vector<std::pair<std::string,double>>);
        std::vector<std::pair<std::string,double>> getData() const;
        //void setData(int,std::string,double);

        //void loadDataFromJSON(const QJsonObject&); // JSON input
        //void saveDataToJSON(QJsonObject&) const; // JSON output
};

#endif