#ifndef GRAFICO_VIEW_H
#define GRAFICO_VIEW_H

#include <QWidget>
#include <QPushButton>
#include <QMenu>
#include <QVBoxLayout>

#include <QtCharts>

#include "../Model/classi/barre.h"
#include "../Model/classi/dispersione.h"
#include "../Model/classi/istogramma.h"
#include "../Model/classi/torta.h"
#include "../Model/classi/linea.h"

class graficoView: public QWidget{
    Q_OBJECT
    private:
        QChart* chart;
        QChartView* chartView;
        QVBoxLayout* mainLayout;
    public:
        explicit graficoView(QWidget* = nullptr);
        ~graficoView();
        void showGrafico(grafico*);
        void updateGrafico(grafico*);
        void resetGrafico();
        void updateRegLin();
};

#endif
