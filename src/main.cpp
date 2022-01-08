//---------------MAIN DI TESTING-----------------------
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Model\classi\linea.h"
#include "Model\classi\torta.h"
#include "Model\classi\dispersione.h"
#include "Model\classi\istogramma.h"
#include "Model\classi\barre.h"

int main(){
    std::map<std::string, double> m;
    std::vector<std::pair<double,double>> v;

    m.insert({"gennaio",1}); m.insert({"febbraio",2}); m.insert({"marzo",3}); m.insert({"aprile",4});
    v.push_back({12.3,13.3}); v.push_back({14.3,15.3}); v.push_back({16.3,17.3}); v.push_back({18.3,19.3});

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


    return 0;
}