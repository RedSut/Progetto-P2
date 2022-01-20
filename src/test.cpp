//---------------FILE PER TESTARE LE FUNZIONALITA'-----------------------
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Model\classi\linea.h"
#include "Model\classi\torta.h"
#include "Model\classi\dispersione.h"
#include "Model\classi\istogramma.h"
#include "Model\classi\barre.h"
#include "Model\classi\graficoCreator.h"

int main(){
    std::string Titolo = "Grafico Torta";
    std::vector<std::string> vs = {"Legenda"};
    std::vector<double> vd = {24};
    graficoCreator gc;
    grafico* g1 = gc.createIstogramma("Grafico Istogramma",vs,vd,"NomeLegenda","NomeDati");
    grafico* g2 = gc.createTorta(Titolo,vs,vd);
    grafico* g3 = gc.createBarre("Grafico Barre",vs,vd,{"Categorie"},"X","Y");
    grafico* g4 = gc.createLinea("Grafico Linea",{{24,99},{7,24}},"Asse X", "Asse Y");
    grafico* g5 = gc.createDispersione("Grafico Dispersione",{{24,24},{23,25},{26,22},{20,24}},"Asse X", "Asse Y");

    istogramma* t1 = dynamic_cast<istogramma*>(g1);
    torta* t2 = dynamic_cast<torta*>(g2);

    barre* b1 = dynamic_cast<barre*>(g3);

    linea* l1 = dynamic_cast<linea*>(g4);
    dispersione* d1 = dynamic_cast<dispersione*>(g5);


    if(t1){
        //std::cout<<t1->getInfo().at("titolo")<<std::endl;
        std::cout<<t1->getTitolo()<<std::endl;
        std::cout<<t1->getLegenda().at(0)<<std::endl;
        std::cout<<t1->getValori().at(0)<<std::endl;
        std::cout<<t1->getNomeLegenda()<<std::endl;
        std::cout<<t1->getNomeValori()<<std::endl<<std::endl;

    }
    if(t2){
        //std::cout<<t2->getInfo().at("titolo")<<std::endl;
        std::cout<<t2->getTitolo()<<std::endl;
        std::cout<<t2->getLegenda().at(0)<<std::endl;
        std::cout<<t2->getValori().at(0)<<std::endl<<std::endl;
    }
    if(b1){
        std::cout<<b1->getTitolo()<<std::endl;
        std::cout<<b1->getLegenda().at(0)<<std::endl;
        std::cout<<b1->getValori().at(0)<<std::endl;
        std::cout<<b1->getCategorie().at(0)<<std::endl;
        std::cout<<b1->getNomeAsseX()<<std::endl;
        std::cout<<b1->getNomeAsseY()<<std::endl<<std::endl;
    }
    if(l1){
        std::cout<<l1->getTitolo()<<std::endl;
        l1->ordinaPunti();
        std::cout<<l1->getPunti().at(0).first<<std::endl;
        std::cout<<l1->getPunti().at(0).second<<std::endl;
        std::cout<<l1->getPunti().at(1).first<<std::endl;
        std::cout<<l1->getPunti().at(1).second<<std::endl;
        std::cout<<l1->getNomeAsseX()<<std::endl;
        std::cout<<l1->getNomeAsseY()<<std::endl<<std::endl;
    }
    if(d1){
        std::cout<<d1->getTitolo()<<std::endl;
        std::cout<<d1->getPunti().at(0).first<<std::endl;
        std::cout<<d1->getPunti().at(0).second<<std::endl;
        std::cout<<d1->getNomeAsseX()<<std::endl;
        std::cout<<d1->getNomeAsseY()<<std::endl;
        std::cout<<d1->regressioneLineare().at(0)<<std::endl<<std::endl;
    }




}
