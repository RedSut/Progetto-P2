#include "dispersione.h"

dispersione::dispersione(std::string t,std::vector<std::pair<double,double>> p,std::string nx,std::string ny): graficoPianoCartesiano(t,p,nx,ny){};

std::vector<double> dispersione::regressioneLineare(){
    std::vector<double> X, Y;
    std::vector<std::pair<double,double>> pc1 = graficoPianoCartesiano::getPunti();
    for(auto it = pc1.begin(); it != pc1.end(); ++it){
        X.push_back(it->first);
        Y.push_back(it->second);
    }
    if (X.size() != Y.size()) throw graficoException("Errore Inaspettato: i punti hanno valori di x non associati a valori di y",graficoException::WRONG_SIZE);
    if (X.empty() || Y.empty()) throw graficoException("Non ci sono punti presenti nel grafico",graficoException::EMPTY_ARGUMENT);
    std::vector<double> regres;
    int n = X.size();
    double sumX, sumY;
    for(int i=0; i<n; i++){
        sumX += X[i];
        sumY += Y[i];
    }
    double mx = sumX/n; // media delle x
    double my = sumY/n; // media delle y
    double sxy = 0;
    double sxsqr = 0; 
    for (int j=0; j<n; j++){
        sxy += (X[j] - mx) * (Y[j] - my);
        sxsqr += pow((X[j] - mx),2); // somma degli scarti quadratici medi
    } 
    double m = sxy / sxsqr; // coefficiente angolare
    double q = my - m * mx; // termine noto 
    for (int k=0 ; k<n; k++){
        regres.push_back(m * X[k] + q);
    }  
    return regres; // ritorna un vettore con le Y della retta di regressione (le X sono da 1 a n)
}
