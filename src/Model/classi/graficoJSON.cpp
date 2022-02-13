#include "graficoJSON.h"

const QString graficoJSON::JSON_titolo = "titolo";
const QString graficoJSON::JSON_legenda = "legenda";
const QString graficoJSON::JSON_valori = "valori";
const QString graficoJSON::JSON_gruppi = "gruppi";
const QString graficoJSON::JSON_punti = "punti";
const QString graficoJSON::JSON_asse_x = "asse_x";
const QString graficoJSON::JSON_asse_y = "asse_y";
const QString graficoJSON::JSON_nome_leg = "nome_legenda";
const QString graficoJSON::JSON_nome_val = "nome_valori";
const QString graficoJSON::JSON_tipologia = "tipologia";


graficoJSON::graficoJSON(Model* m){
    setModel(*m);
}

void graficoJSON::setModel(Model& m){
    M = &m;
}

grafico* graficoJSON::getGrafico()const{
    return M->getGrafico();
}

void graficoJSON::loadDataFromJSON(const QJsonObject& jsonOBJ){
    QJsonValue tp = jsonOBJ[JSON_tipologia];
    if(!tp.isUndefined()){
        if(tp.isString()){
            if(tp.toString().toStdString() == "barre"){
                M->createGrafico(Model::barre);
            }else if(tp.toString().toStdString() == "torta"){
                M->createGrafico(Model::torta);
            }else if(tp.toString().toStdString() == "istogramma"){
                M->createGrafico(Model::istogramma);
            }else if(tp.toString().toStdString() == "linea"){
                M->createGrafico(Model::linea);
            }else if(tp.toString().toStdString() == "dispersione"){
                M->createGrafico(Model::dispersione);
            }else{
                throw graficoException("La tipologia deve essere una delle seguenti stringhe: 'torta', 'istogramma', 'barre', 'linea', 'dispersione'",graficoException::INVALID_FORMAT);
            }
        }else{
            throw graficoException("La tipologia deve essere una delle seguenti stringhe: 'torta', 'istogramma', 'barre', 'linea', 'dispersione'",graficoException::INVALID_FORMAT);
        }
    }
    grafico* g = M->getGrafico();
    QJsonValue t = jsonOBJ[JSON_titolo];
    if(!t.isUndefined()){
        if(t.isString()){
            g->setTitolo(t.toString().toStdString());
        }else{
            throw graficoException("Il titolo deve essere una stringa", graficoException::WRONG_DATA_TYPE);
        }
    }
    graficoSemplice* gs = dynamic_cast<graficoSemplice*>(g);
    if(gs){
        QJsonValue l = jsonOBJ[JSON_legenda];
        if(!l.isUndefined()){
            if(l.isArray()){
                std::vector<std::string> leg;
                QJsonArray l1 = l.toArray();
                for(int i = 0; i < l1.size(); ++i){
                    if(l1.at(i).isString()){
                        leg.push_back(l1.at(i).toString().toStdString());
                    }else{
                        std::string s = "L'elemento dell'array legenda in posizione " + std::to_string(i);
                        s += " deve essere una stringa";
                        throw graficoException(s,graficoException::WRONG_DATA_TYPE);
                    }
                }
                if(l1.isEmpty()){
                    leg.push_back("");
                }
                gs->setLegenda(leg);
            }else{
                throw graficoException("La legenda deve essere un array di stringhe",graficoException::INVALID_FORMAT);
            }
        }
        QJsonValue v = jsonOBJ[JSON_valori];
        if(!v.isUndefined()){
            if(v.isArray()){
                std::vector<double> val;
                QJsonArray v1 = v.toArray();
                for(int i = 0; i < v1.size(); ++i){
                    if(v1.at(i).isDouble()){
                        val.push_back(v1.at(i).toDouble());
                    }else{
                        std::string s = "L'elemento dell'array valori in posizione " + std::to_string(i);
                        s += " deve essere un numero";
                        throw graficoException(s,graficoException::WRONG_DATA_TYPE);
                    }
                }
                if(v1.isEmpty()){
                    val.push_back(0);
                }
                gs->setValori(val);
            }else{
                throw graficoException("I valori devono essere inseriri in un array",graficoException::INVALID_FORMAT);
            }
        }
        istogramma* gi = dynamic_cast<istogramma*>(g);
        if(gi){
            QJsonValue nl = jsonOBJ[JSON_nome_leg];
            if(!nl.isUndefined()){
                if(nl.isString()){
                    gi->setNomeLegenda(nl.toString().toStdString());
                }else{
                    throw graficoException("Il nome per la categoria legenda deve essere una stringa",graficoException::WRONG_DATA_TYPE);
                }
            }
            QJsonValue nv = jsonOBJ[JSON_nome_val];
            if(!nv.isUndefined()){
                if(nv.isString()){
                    gi->setNomeValori(nv.toString().toStdString());
                }else{
                    throw graficoException("Il nome per la categoria valori deve essere una stringa",graficoException::WRONG_DATA_TYPE);
                }
            }
        }
        graficoComplesso* gc = dynamic_cast<graficoComplesso*>(g);
        if(gc){
            QJsonValue c = jsonOBJ[JSON_gruppi];
            if(!c.isUndefined()){
                if(c.isArray()){
                    QJsonArray c1 = c.toArray();
                    std::vector<std::string> gru;
                    for(int i = 0; i<c1.size();++i){
                        if(c1.at(i).isString()){
                            gru.push_back(c1.at(i).toString().toStdString());
                        }else{
                            std::string s = "L'elemento dell'array gruppi in posizione " + std::to_string(i);
                            s += " deve essere una stringa";
                            throw graficoException(s,graficoException::WRONG_DATA_TYPE);
                        }
                    }
                    if(c1.isEmpty()){
                        gru.push_back("");
                    }
                    gc->setGruppi(gru);
                }else{
                    throw graficoException("I gruppi di dati devono essere inserite in un array",graficoException::INVALID_FORMAT);
                }
            }
            barre* gb = dynamic_cast<barre*>(g);
            if(gb){
                QJsonValue x = jsonOBJ[JSON_asse_x];
                if(!x.isUndefined()){
                    if(x.isString()){
                        gb->setNomeAsseX(x.toString().toStdString());
                    }else{
                        throw graficoException("Il nome dell'asse x deve essere una stringa",graficoException::WRONG_DATA_TYPE);
                    }
                }
                QJsonValue y = jsonOBJ[JSON_asse_y];
                if(!y.isUndefined()){
                    if(y.isString()){
                        gb->setNomeAsseY(y.toString().toStdString());
                    }else{
                        throw graficoException("Il nome dell'asse y deve essere una stringa",graficoException::WRONG_DATA_TYPE);
                    }
                }
            }
        }
        gs->checkSize(); // Controlla se le dimensioni dei vettori sono corrette
    }else{
        graficoPianoCartesiano* gp = dynamic_cast<graficoPianoCartesiano*>(g);
        if(gp){
            QJsonValue d = jsonOBJ[JSON_punti];
            if(!d.isUndefined()){
                if(d.isArray()){
                    std::vector<std::pair<double,double>> pc;
                    QJsonArray dt = d.toArray();
                    for(int i=0;i<dt.size();++i){
                        double d1;
                        double d2;
                        if(dt.at(i).isArray()){
                            QJsonArray dtt = dt.at(i).toArray();
                            if(dtt.at(0).isUndefined() || dtt.at(1).isUndefined() || !dtt.at(2).isUndefined()){
                                std::string s = "Il punto definito dalla coppia in posizione ";
                                s += std::to_string(i);
                                s += " deve avere esattamente due valori";
                                throw graficoException(s,graficoException::INVALID_FORMAT);
                            }
                            if(dtt.at(0).isDouble() && dtt.at(1).isDouble()){
                                d1 = dtt.at(0).toDouble();
                                d2 = dtt.at(1).toDouble();
                                pc.push_back({d1,d2});
                            }else{
                                std::string s = "Il punto definito dalla coppia in posizione ";
                                s += std::to_string(i);
                                s += " deve avere valori numerici";
                                throw graficoException(s,graficoException::WRONG_DATA_TYPE);
                            }
                        }else{
                            throw graficoException("I punti devono essere coppie di valori: [x1,y1],[x2,y2],ecc",graficoException::INVALID_FORMAT);
                        }
                    }
                    if(dt.isEmpty()){
                        pc.push_back({0,0});
                    }
                    gp->setPunti(pc);
                }else{
                    throw graficoException("I punti devono essere inseriti in un array",graficoException::INVALID_FORMAT);
                }
            }
                
            QJsonValue nx = jsonOBJ[JSON_asse_x];
            if(!nx.isUndefined()){
                if(nx.isString()){
                    gp->setNomeAsseX(nx.toString().toStdString());
                }else{
                    throw graficoException("Il nome dell'asse x deve essere una stringa",graficoException::WRONG_DATA_TYPE);
                }
            }
            QJsonValue ny = jsonOBJ[JSON_asse_y];
            if(!ny.isUndefined()){
                if(ny.isString()){
                    gp->setNomeAsseY(ny.toString().toStdString());
                }else{
                    throw graficoException("Il nome dell'asse y deve essere una stringa",graficoException::WRONG_DATA_TYPE);
                }
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
        torta* gt = dynamic_cast<torta*>(g);
        if(gt){    
            jsonOBJ[JSON_tipologia] = QString::fromStdString("torta");
        }
        istogramma* gi = dynamic_cast<istogramma*>(g);
        if(gi){
            jsonOBJ[JSON_tipologia] = QString::fromStdString("istogramma");
            jsonOBJ[JSON_nome_leg] = QString::fromStdString(gi->getNomeLegenda());
            jsonOBJ[JSON_nome_val] = QString::fromStdString(gi->getNomeValori());
        }
        graficoComplesso* gc = dynamic_cast<graficoComplesso*>(g);
        if(gc){
            QJsonArray v;
            std::vector<std::string> c = gc->getGruppi();
            for(auto it=c.begin(); it!=c.end();++it){
                v.push_back(QString::fromStdString(*it));
            }
            jsonOBJ[JSON_gruppi] = v;
            barre* gb = dynamic_cast<barre*>(g);
            if(gb){
                jsonOBJ[JSON_tipologia] = QString::fromStdString("barre");
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
            if(dynamic_cast<linea*>(g)){
                jsonOBJ[JSON_tipologia] = QString::fromStdString("linea");
            }else{
                jsonOBJ[JSON_tipologia] = QString::fromStdString("dispersione");
            }
        }
    }
    return;
}
