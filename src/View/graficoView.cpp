#include "graficoView.h"

graficoView::graficoView(QWidget* parent) : QWidget(parent){
    mainLayout = new QVBoxLayout();
    
    chart  = new QChart;
    chartView = new QChartView(chart);
    mainLayout->addWidget(chartView);
    mainLayout->setMargin(0);
    setLayout(mainLayout);
}

graficoView::~graficoView(){
    delete chart;
    delete chartView;
    delete mainLayout;
}

void graficoView::showGrafico(grafico* G){

    torta* gt = dynamic_cast<torta*>(G);
    istogramma* gi = dynamic_cast<istogramma*>(G);
    barre* gb = dynamic_cast<barre*>(G);
    linea* gl = dynamic_cast<linea*>(G);
    dispersione* gd = dynamic_cast<dispersione*>(G);

    chart->setAnimationOptions(QChart::AllAnimations);
    chartView->setRenderHint(QPainter::Antialiasing);
    if(gt){
        QPieSeries* series = new QPieSeries();
        std::vector<double> valori = gt->getValoriInPercentage();
        std::vector<std::string> legenda = gt->getLegenda();
        auto it2 = legenda.begin();
        for(auto it = valori.begin(); it!=valori.end();++it){
            QPieSlice* slice = new QPieSlice();
            slice->setValue(*it);
            slice->setLabel(QString::fromStdString(*it2));
            series->append(slice);
            ++it2;
        }

        chart->addSeries(series);
        chart->setTitle(QString::fromStdString(gt->getTitolo()));
    }else if(gi){
        std::vector<double> valori = gi->getValori();
        std::vector<std::string> legenda = gi->getLegenda();
        QBarSeries* series = new QBarSeries();
        series->setBarWidth(1);
        double maxVal = 1;
        double minVal = 0;
        QBarSet* barSet = new QBarSet("Valori");
        for(auto it = valori.begin(); it != valori.end(); ++it){
            barSet->append(*it);
            if(*it<minVal){
                minVal = *it;
            }else if(*it>maxVal){
                maxVal = *it;
            }
        }
        QBarCategoryAxis* axis_x = new QBarCategoryAxis();
        for(auto it = legenda.begin(); it!=legenda.end(); ++it){
            axis_x->append(QString::fromStdString(*it));
        }
        series->append(barSet);
        chart->addSeries(series);
        chart->createDefaultAxes();
        axis_x->setTitleText(QString::fromStdString(gi->getNomeLegenda()));
        chart->setAxisX(axis_x, series);
        chart->axisY()->setTitleText(QString::fromStdString(gi->getNomeValori()));
        chart->axisY()->setRange(minVal, maxVal);
        chart->legend()->hide();
        chart->setTitle(QString::fromStdString(gi->getTitolo()));

    }else if(gb){
        std::vector<double> valori = gb->getValori();
        std::vector<std::string> legenda = gb->getLegenda();
        std::vector<std::string> gruppi = gb->getGruppi();
        QBarSeries* series = new QBarSeries();
        int nLeg = legenda.size();
        double maxVal = valori.at(0);
        double minVal = 0;
        for(int i=0; i<nLeg; ++i){
            QBarSet* barSet = new QBarSet(QString::fromStdString(legenda.at(i)));
            for(unsigned int j=i; j<=valori.size()-nLeg+i; j+=nLeg){
                barSet->append(valori.at(j));
                if(valori.at(j)<minVal){
                    minVal = valori.at(j);
                }else if(valori.at(j)>maxVal){
                    maxVal = valori.at(j);
                }
            }
            series->append(barSet);
        }
        QBarCategoryAxis* axis_x = new QBarCategoryAxis();
        for(auto it = gruppi.begin(); it!=gruppi.end(); ++it){
            axis_x->append(QString::fromStdString(*it));
        }
        chart->addSeries(series);
        chart->createDefaultAxes();
        axis_x->setTitleText(QString::fromStdString(gb->getNomeAsseX()));
        chart->setAxisX(axis_x, series);

        chart->axisY()->setTitleText(QString::fromStdString(gb->getNomeAsseY()));
        chart->axisY()->setRange(minVal, maxVal+1);
        chart->legend()->show();
        chart->setTitle(QString::fromStdString(gb->getTitolo()));

    }else if(gl){
        std::vector<std::pair<double,double>> punti = gl->getPunti();
        QLineSeries* series = new QLineSeries();
        series->setColor("red");
        series->setPointsVisible();
        QPen pen = series->pen();
        pen.setWidth(4);
        series->setPen(pen);
        double xMax = 0, yMax = 0, xMin = punti.at(0).first, yMin = punti.at(0).second;
        for(auto it = punti.begin(); it!=punti.end(); ++it){
            series->append(it->first,it->second);
            if(it->first > xMax){
                xMax = it->first;
            }else if(it->first < xMin){
                xMin = it->first;
            }
            if(it->second > yMax){
                yMax = it->second;
            }else if(it->second < yMin){
                yMin = it->second;
            }
        }
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->legend()->hide();
        chart->axisX()->setTitleText(QString::fromStdString(gl->getNomeAsseX()));
        chart->axisX()->setRange(xMin-1, xMax+1);
        chart->axisY()->setTitleText(QString::fromStdString(gl->getNomeAsseY()));
        chart->axisY()->setRange(yMin-1, yMax+1);
        chart->setTitle(QString::fromStdString(gl->getTitolo()));
    }else if (gd){
        std::vector<std::pair<double,double>> punti = gd->getPunti();
        std::vector<double> reg = gd->regressioneLineare();
        QScatterSeries* series = new QScatterSeries();
        series->setColor("red");
        QPen pen = series->pen();
        pen.setWidth(2);
        pen.setBrush(QBrush("red"));
        series->setPen(pen);
        double xMax = 0, yMax = 0, xMin = punti.at(0).first, yMin = punti.at(0).second;
        for(auto it = punti.begin(); it!=punti.end(); ++it){
            series->append(it->first,it->second);
            if(it->first > xMax){
                xMax = it->first;
            }else if(it->first < xMin){
                xMin = it->first;
            }
            if(it->second > yMax){
                yMax = it->second;
            }else if(it->second < yMin){
                yMin = it->second;
            }
        }
        QLineSeries* regSer = new QLineSeries();
        regSer->setColor("green");
        QPen pen2 = regSer->pen();
        pen2.setWidth(2);
        pen2.setStyle(Qt::DashLine);
        regSer->setPen(pen2);
        auto it3 = punti.begin();
        for(auto it2 = reg.begin(); it2!=reg.end(); ++it2){
            regSer->append(it3->first,*it2);
            ++it3;
        }
        regSer->setName("Regressione Lineare");
        series->setName("Punti");
        chart->addSeries(series);
        chart->addSeries(regSer);
        chart->createDefaultAxes();
        chart->legend()->show();
        chart->axisX()->setTitleText(QString::fromStdString(gd->getNomeAsseX()));
        chart->axisX()->setRange(xMin-1, xMax+1);
        chart->axisY()->setTitleText(QString::fromStdString(gd->getNomeAsseY()));
        chart->axisY()->setRange(yMin-1, yMax+1);
        chart->setTitle(QString::fromStdString(gd->getTitolo()));
    }
}

void graficoView::resetGrafico(){
    QChart::ChartTheme theme = chart->theme();
    delete chart;
    delete chartView;
    chart  = new QChart;
    chartView = new QChartView(chart);

    chart->setTheme(theme);
    mainLayout->addWidget(chartView);

    setLayout(mainLayout);
}

void graficoView::updateGrafico(grafico* G){
    resetGrafico();

    showGrafico(G);
}

void graficoView::updateRegLin(){
    if(chart->series().at(1)->isVisible()){
        chart->series().at(1)->hide();
    }else{
        chart->series().at(1)->show();
    }
}
