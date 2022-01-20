#include "graficoJSON.h"

const QString graficoJSON::JSON_titolo = "titolo";
const QString graficoJSON::JSON_legenda = "legenda";
const QString graficoJSON::JSON_valori = "valori";
const QString graficoJSON::JSON_categorie = "categorie";
const QString graficoJSON::JSON_punti = "punti";
const QString graficoJSON::JSON_asse_x = "asse_x";
const QString graficoJSON::JSON_asse_y = "asse_y";
const QString graficoJSON::JSON_nome_leg = "nome_legenda";
const QString graficoJSON::JSON_nome_val = "nome_valori";


graficoJSON::graficoJSON(Model* m){
    setModel(m);
}

void graficoJSON::setModel(Model* m){
    M = m;
}

void graficoJSON::loadDataFromJSON(const QJsonObject& jsonOBJ){
    grafico* g = M->getGrafico();
    QJsonValue t = jsonOBJ[JSON_titolo];
    if(!t.isUndefined() && t.isString()){
        g->setTitolo(t.toString().toStdString());
    }
    graficoSemplice* gs = dynamic_cast<graficoSemplice*>(g);
    if(gs){
        QJsonValue l = jsonOBJ[JSON_legenda];
        if(!l.isUndefined() && l.isArray()){
            std::vector<std::string> leg;
            QJsonArray l1 = l.toArray();
            for(int i = 0; i < l1.size(); ++i){
                leg.push_back(l1.at(i).toString().toStdString());
            }
            gs->setLegenda(leg);
        }
        QJsonValue v = jsonOBJ[JSON_valori];
        if(!v.isUndefined() && v.isArray()){
            std::vector<double> val;
            QJsonArray v1 = v.toArray();
            for(int i = 0; i < v1.size(); ++i){
                val.push_back(v1.at(i).toDouble());
            }
            gs->setValori(val);
        }
        istogramma* gi = dynamic_cast<istogramma*>(g);
        if(gi){
            QJsonValue nl = jsonOBJ[JSON_nome_leg];
            if(!nl.isUndefined() && nl.isString()){
                gi->setNomeLegenda(nl.toString().toStdString());
            }
            QJsonValue nv = jsonOBJ[JSON_nome_val];
            if(!nv.isUndefined() && nv.isString()){
                gi->setNomeValori(nv.toString().toStdString());
            }
        }
        graficoComplesso* gc = dynamic_cast<graficoComplesso*>(g);
        if(gc){
            QJsonValue c = jsonOBJ[JSON_categorie];
            if(!c.isUndefined() && c.isArray()){
                QJsonArray c1 = c.toArray();
                std::vector<std::string> cat;
                for(int i = 0; i<c1.size();++i){
                    cat.push_back(c1.at(i).toString().toStdString());
                }
                gc->setCategorie(cat);
            }
            barre* gb = dynamic_cast<barre*>(g);
            if(gb){
                QJsonValue x = jsonOBJ[JSON_asse_x];
                if(!x.isUndefined() && x.isString()){
                    gb->setNomeAsseX(x.toString().toStdString());
                }
                QJsonValue y = jsonOBJ[JSON_asse_y];
                if(!y.isUndefined() && y.isString()){
                    gb->setNomeAsseY(y.toString().toStdString());
                }
            }
        }
    }else{
        graficoPianoCartesiano* gp = dynamic_cast<graficoPianoCartesiano*>(g);
        if(gp){
            QJsonValue d = jsonOBJ[JSON_punti];
            if(!d.isUndefined() && d.isArray()){
                std::vector<std::pair<double,double>> pc;
                QJsonArray dt = d.toArray();
                /*for(int i=0; i<dt.size(); i+=2){ // VERSIONE PUNTI IN UN UNICO ARRAY
                    double d1;
                    double d2;
                    if(!dt.at(i).isUndefined() && dt.at(i).isDouble()){
                        d1 = dt.at(i).toDouble();
                    }
                    if(!dt.at(i+1).isUndefined() && dt.at(i+1).isDouble()){
                        d2 = dt.at(i+1).toDouble();
                    }
                    pc.push_back({d1,d2});
                }*/
                for(int i=0;i<dt.size();++i){
                    double d1;
                    double d2;
                    if(dt.at(i).isArray()){
                        QJsonArray dtt = dt.at(i).toArray();
                        if(dtt.at(0).isDouble() && dtt.at(1).isDouble()){
                            d1 = dtt.at(0).toDouble();
                            d2 = dtt.at(1).toDouble();
                            pc.push_back({d1,d2});
                        }
                    }
                }
                gp->setPunti(pc);
            }
            QJsonValue nx = jsonOBJ[JSON_asse_x];
            if(!nx.isUndefined() && nx.isString()){
                gp->setNomeAsseX(nx.toString().toStdString());
            }
            QJsonValue ny = jsonOBJ[JSON_asse_y];
            if(!ny.isUndefined() && ny.isString()){
                gp->setNomeAsseY(ny.toString().toStdString());
            }
        }
    }
    return;
};

void graficoJSON::saveDataToJSON(QJsonObject& jsonOBJ) const{
    grafico* g = M->getGrafico();
    jsonOBJ[JSON_titolo] = QString::fromStdString(g->getTitolo());
    graficoSemplice* gs = dynamic_cast<graficoSemplice*>(g);
    if(gs){
        QJsonArray a, b;
        std::vector<std::string> l = gs->getLegenda();
        for(auto it=l.begin(); it!=l.end();++it){
            a.push_back(QString::fromStdString(*it));
        }
        jsonOBJ[JSON_legenda] = a;
        std::vector<double> v = gs->getValori();
        for(auto it=v.begin(); it!=v.end();++it){
            b.push_back(*it);
        }
        jsonOBJ[JSON_valori] = b;
        istogramma* gi = dynamic_cast<istogramma*>(g);
        if(gi){
            jsonOBJ[JSON_nome_leg] = QString::fromStdString(gi->getNomeLegenda());
            jsonOBJ[JSON_nome_val] = QString::fromStdString(gi->getNomeValori());
        }
        graficoComplesso* gc = dynamic_cast<graficoComplesso*>(g);
        if(gc){
            QJsonArray v;
            std::vector<std::string> c = gc->getCategorie();
            for(auto it=c.begin(); it!=c.end();++it){
                v.push_back(QString::fromStdString(*it));
            }
            jsonOBJ[JSON_categorie] = v;
            barre* gb = dynamic_cast<barre*>(g);
            if(gb){
                jsonOBJ[JSON_asse_x] = QString::fromStdString(gb->getNomeAsseX());
                jsonOBJ[JSON_asse_y] = QString::fromStdString(gb->getNomeAsseY());
            }
        }
    }else{
        graficoPianoCartesiano* gp = dynamic_cast<graficoPianoCartesiano*>(g);
        if(gp){
            QJsonArray pc;
            std::vector<std::pair<double,double>> p = gp->getPunti();
            for(auto it=p.begin(); it!=p.end();++it){
                QJsonArray cp;
                cp.push_back(it->first);
                cp.push_back(it->second);
                pc.push_back(cp);
            }
            jsonOBJ[JSON_punti] = pc;
            jsonOBJ[JSON_asse_x] = QString::fromStdString(gp->getNomeAsseX());
            jsonOBJ[JSON_asse_y] = QString::fromStdString(gp->getNomeAsseY());
        }
    }
    return;
}