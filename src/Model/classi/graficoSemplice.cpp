#include <vector>
#include <string>
#include "graficoSemplice.h"

//COSTRUTTORI

graficoSemplice::graficoSemplice(std::vector<std::pair<std::string,double>> input): s(input){};

graficoSemplice::graficoSemplice(){
    s.push_back({"",0});
};

//METODI

std::vector<std::pair<std::string,double>> graficoSemplice::getData() const {
    if(!s.empty()){
        return s;
    }
};

/*void graficoSemplice::setData(int indice, std::string s, double d){

}


void graficoSemplice::loadDataFromJSON(const QJsonObject& jsonOBJ){
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
