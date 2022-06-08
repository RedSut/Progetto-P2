#include "linea.h"

linea::linea(std::string t,std::vector<std::pair<double,double>> p,std::string nx,std::string ny):graficoPianoCartesiano(t,p,nx,ny){}

void linea::ordinaPunti(){
    std::vector<std::pair<double,double>> punti = graficoPianoCartesiano::getPunti();
    std::sort(punti.begin(),punti.end());
    graficoPianoCartesiano::setPunti(punti);
}
