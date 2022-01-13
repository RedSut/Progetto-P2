#ifndef GRAFICO_H
#define GRAFICO_H
#include <string>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

class grafico{
    private:
        std::string titolo;
    public:
        std::string getTitolo() const;
        void setTitolo(std::string);

        //virtual void loadDataFromJSON(const QJsonObject&)=0; // JSON input
        //virtual void saveDataToJSON(QJsonObject&)const=0; // JSON output
};

#endif