#ifndef GRAFICO_H
#define GRAFICO_H
#include<string>

class grafico{
    private:
        std::string titolo;
    public:
        std::string getTitolo() const;
        void setTitolo(std::string);
};

#endif