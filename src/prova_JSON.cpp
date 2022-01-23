#include <iostream>
#include <fstream>
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include "Model\classi\graficoJSON.h"
#include "Model\classi\Model.h"

int main(){
    Model* m = new Model();
    //m->createGraficoBarre();
    graficoJSON* j = new graficoJSON(m);
    /*std::ifstream file_std("sample.json");
    if(file_std.is_open()){
        std::cout<<"GG";
    }*/

    QString val;
    QFile file("C:/Users/david/OneDrive/Documenti/GitHub/Progetto-P2/src/sample.json");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        val = file.readAll();
        file.close();
        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject o = d.object();

        j->loadDataFromJSON(o);
    }else{
        std::cout<<"Questo file non esiste!";
    }

    barre* t1 = dynamic_cast<barre*>(m->getGrafico());
    if(t1){
        std::cout<<t1->getTitolo()<<std::endl;
        std::cout<<t1->getLegenda().at(0)<<" "<<t1->getLegenda().at(1)<<std::endl;
        std::cout<<t1->getValori().at(0)<<" "<<t1->getValori().at(1)<<std::endl;
        std::cout<<t1->getCategorie().at(0)<<" "<<t1->getCategorie().at(1)<<std::endl;
    }
    
    QJsonObject o1;
    j->saveDataToJSON(o1);
    QJsonDocument d1;
    d1.setObject(o1);
    QFile file1("C:/Users/david/OneDrive/Documenti/GitHub/Progetto-P2/src/save.json");
    if(file1.open(QFile::WriteOnly | QFile::Text)){
        file1.write(d1.toJson());
    }else{
        std::cout<<"ERRORE!";
    }
    

}
