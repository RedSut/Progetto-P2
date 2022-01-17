#ifndef GRAFICO_H
#define GRAFICO_H
#include <string>
#include <vector>
#include <map>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

class grafico{ //classe base astratta
    public:
        //grafico();

        virtual std::string getTitolo() const=0;
        virtual void setTitolo(std::string)=0;

        //virtual std::map<std::string,std::string> getInfo()const=0;

        //virtual void loadDataFromJSON(const QJsonObject&)=0; // JSON input
        //virtual void saveDataToJSON(QJsonObject&)const=0; // JSON output
};

#endif
