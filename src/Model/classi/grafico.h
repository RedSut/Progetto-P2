#ifndef GRAFICO_H
#define GRAFICO_H

#include <string>
#include <map>

#include "graficoException.h"

class grafico{ //classe base astratta
    public:
        //grafico();
        virtual std::string getTitolo() const=0;
        virtual void setTitolo(std::string)=0;
};

#endif
