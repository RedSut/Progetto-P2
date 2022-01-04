#include <string>
#include <map>
#include "graficoSemplice.h"

class istogramma : public graficoSemplice{
    private:
        std::string nomeDatoDouble;
        std::string nomeDatoString;
    public:
        istogramma(std::map<std::string,double>);
};