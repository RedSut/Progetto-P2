#include <string>
#include "grafico.h"


std::string grafico::getTitolo()const{
    return titolo;
}

void grafico::setTitolo(std::string t){
    if(!t.empty()) {
        titolo = t;
    }
    return;
}