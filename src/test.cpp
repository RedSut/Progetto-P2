//---------------FILE PER TESTARE LE FUNZIONALITA'-----------------------
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include "Model\classi\linea.h"
#include "Model\classi\torta.h"
#include "Model\classi\dispersione.h"
#include "Model\classi\istogramma.h"
#include "Model\classi\barre.h"
#include "Model\classi\graficoCreator.h"

int main(){
    std::string Titolo = "Grafico Torta";
    std::vector<std::string> vs = {"Prova"};
    std::vector<double> vd = {24};
    graficoCreator gc;
    grafico* g1 = gc.createTorta();
    grafico* g2 = gc.createTorta(Titolo,vs,vd);

    torta* t1 = dynamic_cast<torta*>(g1);
    torta* t2 = dynamic_cast<torta*>(g2);

    if(t1){
        //std::cout<<t1->getInfo().at("titolo")<<std::endl;
        std::cout<<t1->getTitolo()<<std::endl;
        std::cout<<t1->getLegenda().at(0)<<std::endl;
        std::cout<<t1->getValori().at(0)<<std::endl;
    }
    if(t2){
        //std::cout<<t2->getInfo().at("titolo")<<std::endl;
        std::cout<<t2->getTitolo()<<std::endl;
        std::cout<<t2->getLegenda().at(0)<<std::endl;
        std::cout<<t2->getValori().at(0)<<std::endl;
    }




}