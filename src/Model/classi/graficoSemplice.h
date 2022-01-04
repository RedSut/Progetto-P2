#include <map>
#include <string>
#include "grafico.h"

class graficoSemplice : public grafico{
    private:
        std::map<std::string,double> s;
    public:
        graficoSemplice(std::map<std::string,double>);
        std::map<std::string,double> getData() const;
};