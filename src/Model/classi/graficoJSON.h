#ifndef GRAFICO_JSON_H
#define GRAFICO_JSON_H

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QString>

#include "Model.h"
#include "linea.h"
#include "torta.h"
#include "dispersione.h"
#include "istogramma.h"
#include "barre.h"

class graficoJSON{
    private:
        Model* M;
        static const QString JSON_titolo;
        static const QString JSON_legenda;
        static const QString JSON_valori;
        static const QString JSON_gruppi;
        static const QString JSON_punti;
        static const QString JSON_asse_x;
        static const QString JSON_asse_y;
        static const QString JSON_nome_leg;
        static const QString JSON_nome_val;
        static const QString JSON_tipologia;

    public:
        graficoJSON(Model* = new Model());
        void setModel(Model&);
        grafico* getGrafico() const;
        void loadDataFromJSON(const QJsonObject&); // JSON input
        void saveDataToJSON(QJsonObject&) const; // JSON output
};

#endif
