#ifndef GRAFICO_EX_H
#define GRAFICO_EX_H

#include <stdexcept>
#include <string>

class graficoException: public std::invalid_argument{
    private:
        int codice_errore;
    public:
        enum codici{
            UNDEFINED,
            WRONG_DATA_TYPE,
            INVALID_FORMAT,
            WRONG_SIZE
        };

        graficoException(const std::string&,int = 0);
        int codice()const;
};

#endif