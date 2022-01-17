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

void graficoSemplice::setTitolo(std::string t){
    titolo = t;
};

/*std::map<std::string,std::string> graficoSemplice::getInfo()const{ // NON SO SE PUO' SERVIRE
    std::map<std::string,std::string> m;
    m.insert({"titolo",titolo});
    return m;
};*/

std::vector<std::string> graficoSemplice::getLegenda()const{
    return legenda;
}

void graficoSemplice::setLegenda(std::vector<std::string> l){
    legenda = l;
};

std::vector<double> graficoSemplice::getValori()const{
    return valori;
}

void graficoSemplice::setValori(std::vector<double> v){
    valori = v;
}

//METODI
/*

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
