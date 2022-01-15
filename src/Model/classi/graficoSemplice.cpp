#include <vector>
#include <string>
#include "graficoSemplice.h"

//COSTRUTTORI

//graficoSemplice::graficoSemplice(std::vector<std::pair<std::string,double>> input): s(input){};

graficoSemplice::graficoSemplice(std::string tit,std::vector<std::string> leg,std::vector<double> val){
    titolo = tit;
    legenda = leg;
    valori = val;
};

std::string graficoSemplice::getTitolo()const{
    return titolo;
};

std::map<std::string,std::string> graficoSemplice::getInfo()const{ // NON SO SE VA BENE
    std::map<std::string,std::string> m;
    m.insert({"titolo",titolo});
    return m;
};

std::vector<std::string> graficoSemplice::getLegenda()const{
    return legenda;
}

std::vector<double> graficoSemplice::getValori()const{
    return valori;
}

//METODI

/*std::vector<std::pair<std::string,double>> graficoSemplice::getData() const {
    return s;
};

Dato* graficoSemplice::getData()const{
    return data;
}

void graficoSemplice::modifyData(unsigned int indice, std::string str, double d){ // Modifica i dati di una specifica coppia all'interno del vettore
    if(indice < s.size()){
        s.at(indice) = {str,d};
    }
    return;
}

void graficoSemplice::setData(std::vector<std::pair<std::string,double>> data){
    s = data;
    return;
}*/

/*void graficoSemplice::loadDataFromJSON(const QJsonObject& jsonOBJ){
    QJsonValue t = jsonOBJ["titolo"];
    if(!t.isUndefined() && t.isString()){
        this->setTitolo(t.toString().toStdString());
    }
    QJsonValue data = jsonOBJ["data"];
    if(!data.isUndefined() && data.isArray()){
        std::vector<std::pair<std::string,double>> graficoS;
        QJsonArray dt = data.toArray();
        for(int i=0; i<dt.size(); i+=2){
            std::string s;
            double d;
            if(!dt.at(i).isUndefined() && dt.at(i).isString()){
                s = dt.at(i).toString().toStdString();
            }
            if(!dt.at(i+1).isUndefined() && dt.at(i+1).isDouble()){
                d = dt.at(i+1).toDouble();
            }
            graficoS.push_back({s,d});
        }
        graficoSemplice::s = graficoS;
    }
};*/
