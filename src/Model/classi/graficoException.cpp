#include "graficoException.h"

graficoException::graficoException(const std::string& error_msg, int ec): std::invalid_argument(error_msg){
    if(codice_errore < 0 || codice_errore > 3)
        this->codice_errore = UNDEFINED;
    else
        this->codice_errore = ec;
};

