#ifndef GRAFICO_H
#define GRAFICO_H

#include <string>
#include <map>

class grafico{ //classe base astratta
    public:
        //grafico();
        virtual std::string getTitolo() const=0;
        virtual void setTitolo(std::string)=0;
};

#endif
