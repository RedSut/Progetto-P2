//---------------MAIN DI TESTING-----------------------
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Model/classi/linea.h"
#include "Model/classi/torta.h"
#include "Model/classi/dispersione.h"
#include "Model/classi/istogramma.h"
#include "Model/classi/barre.h"

int main(){
    std::map<std::string, double> m; // NO
    std::vector<std::pair<std::string,double>> m_NEW; // MEGLIO QUESTA RAPPRESENTAZIONE PER GRAFICO_SEMPLICE
    std::vector<std::pair<double,double>> v;
    std::vector<std::pair<std::string,graficoSemplice>> mm; // MEGLIO QUESTA RAPPRESENTAZIONE PER GRAFICO_COMLESSO
    std::map<std::string, double> mi; // NO

    m.insert({"gennaio",1}); m.insert({"febbraio",2}); m.insert({"marzo",3}); m.insert({"aprile",4});
    v.push_back({12.6,13.4}); v.push_back({14.2,15.8}); v.push_back({16.1,17.5}); v.push_back({18.2,19.8});
    mi.insert({"gennaio",1});
    mm.push_back(std::make_pair("gennaio",istogramma(mi)));
    m_NEW.push_back({"gennaio",1});

    torta t(m);
    istogramma i(m);

    dispersione d(v);
    linea l(v);

    t.setTitolo("torta"); i.setTitolo("istogramma"); d.setTitolo("dispersione"); l.setTitolo("linea");

    std::cout<<t.getTitolo()<<std::endl;
    std::map<std::string, double> dt = t.getData();
    for(auto it = dt.begin(); it!=dt.end(); ++it){
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }
    std::map<std::string, double> dtp = t.getDataInPercentage();
    for(auto it = dtp.begin(); it!=dtp.end(); ++it){
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }

    std::cout<<std::endl<<i.getTitolo()<<std::endl;
    std::map<std::string, double> di = i.getData();
    for(auto it = di.begin(); it!=di.end(); ++it){
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }
    i.setNomeDati("Valori","Mesi");
    std::cout<<i.getNomeDatoDouble()<<" "<<i.getNomeDatoString()<<std::endl;

    std::cout<<std::endl<<d.getTitolo()<<std::endl;
    std::vector<std::pair<double,double>> dd = d.getData();
    for(auto it = dd.begin(); it!=dd.end(); ++it){
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }
    d.setNomeAssi("AsseX","AsseY");
    std::cout<<d.getNomeAsseX()<<" "<<d.getNomeAsseY()<<std::endl;
    std::vector<double> regl = d.regressioneLineare();
    for(auto itr = regl.begin(); itr!=regl.end(); ++itr){
        std::cout<<*itr<<" ";
    }

    std::cout<<std::endl<<std::endl<<l.getTitolo()<<std::endl;
    std::vector<std::pair<double,double>> dl = l.getData();
    for(auto itl = dl.begin(); itl!=dl.end(); ++itl){
        std::cout<<itl->first<<" "<<itl->second<<std::endl;
    }
    l.setNomeAssi("AsseXl","AsseYl");
    std::cout<<l.getNomeAsseX()<<" "<<l.getNomeAsseY()<<std::endl;



    return 0;
}
