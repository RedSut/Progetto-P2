#include "tableView.h"

tableView::tableView(QWidget* parent): QWidget(parent){
    mainLayout = new QVBoxLayout;
    tabella = new QTableWidget;
    //tableVista = new QTableView(tabella);
    aggiornaButton = new QPushButton("Aggiorna");

    mainLayout->addWidget(tabella);
    mainLayout->addWidget(aggiornaButton);
    setLayout(mainLayout);
    //resize(QSize(300,720));

}

void tableView::populateTable(grafico* G){
    torta* gt = dynamic_cast<torta*>(G);
    istogramma* gi = dynamic_cast<istogramma*>(G);
    barre* gb = dynamic_cast<barre*>(G);
    linea* gl = dynamic_cast<linea*>(G);
    dispersione* gd = dynamic_cast<dispersione*>(G);

    if(gt){
        std::vector<std::string> leg = gt->getLegenda();
        std::vector<double> val = gt->getValori();
        tabella->setRowCount(val.size());
        tabella->setColumnCount(2);
        setMaximumWidth(300);
        QStringList headerLabels;
        headerLabels << "Legenda" <<"Valori";
        tabella->setHorizontalHeaderLabels(headerLabels);
        for(int i=0; i<tabella->rowCount(); ++i){
            QTableWidgetItem* item1 = new QTableWidgetItem;
            QTableWidgetItem* item2 = new QTableWidgetItem;
            item1->setText(QString::fromStdString(leg.at(i)));
            item2->setData(Qt::EditRole,val.at(i));
            tabella->setItem(i,0,item1);
            tabella->setItem(i,1,item2);
        }
    }else if(gi){
        std::vector<std::string> leg = gi->getLegenda();
        std::vector<double> val = gi->getValori();
        tabella->setRowCount(val.size());
        tabella->setColumnCount(2);
        setMaximumWidth(300);
        QStringList headerLabels;
        headerLabels << QString::fromStdString(gi->getNomeLegenda()) << QString::fromStdString(gi->getNomeValori());
        tabella->setHorizontalHeaderLabels(headerLabels);
        for(int i=0; i<tabella->rowCount(); ++i){
            QTableWidgetItem* item1 = new QTableWidgetItem;
            QTableWidgetItem* item2 = new QTableWidgetItem;
            item1->setText(QString::fromStdString(leg.at(i)));
            item2->setData(Qt::EditRole,val.at(i));
            tabella->setItem(i,0,item1);
            tabella->setItem(i,1,item2);
        }
    }else if(gb){
        std::vector<std::string> leg = gb->getLegenda();
        std::vector<double> val = gb->getValori();
        std::vector<std::string> cat = gb->getCategorie();
        tabella->setRowCount(leg.size());
        tabella->setColumnCount(cat.size());
        setMaximumWidth(170*cat.size()); //Da Vedere
        QStringList headerLabels;
        for(auto it = cat.begin(); it!= cat.end(); ++it){
            headerLabels << QString::fromStdString(*it);
        }
        tabella->setHorizontalHeaderLabels(headerLabels);
        QStringList rowLabels;
        for(auto it = leg.begin(); it!= leg.end(); ++it){
            rowLabels << QString::fromStdString(*it);
        }
        tabella->setVerticalHeaderLabels(rowLabels);
        for(int i=0; i<tabella->rowCount(); i++){
            for(int j=0; j<tabella->columnCount(); j++){
                QTableWidgetItem* item = new QTableWidgetItem;
                double v = val.at(j+(i*cat.size()));
                item->setData(Qt::EditRole,v);
                tabella->setItem(i,j,item);
            }
        }
    }else if(gl){
        gl->ordinaPunti();
        std::vector<std::pair<double,double>> punti = gl->getPunti();
        tabella->setRowCount(punti.size());
        tabella->setColumnCount(2);
        setMaximumWidth(300);
        QStringList headerLabels;
        headerLabels << QString::fromStdString(gl->getNomeAsseX()) << QString::fromStdString(gl->getNomeAsseY());
        tabella->setHorizontalHeaderLabels(headerLabels);
        for(int i=0; i<tabella->rowCount(); i++){
            QTableWidgetItem* itemX = new QTableWidgetItem;
            QTableWidgetItem* itemY = new QTableWidgetItem;
            itemX->setData(Qt::EditRole,punti.at(i).first);
            itemY->setData(Qt::EditRole,punti.at(i).second);
            tabella->setItem(i,0,itemX);
            tabella->setItem(i,1,itemY);
        }
    }else if(gd){
        std::vector<std::pair<double,double>> punti = gd->getPunti();
        std::vector<double> reg = gd->regressioneLineare();
        tabella->setRowCount(punti.size());
        tabella->setColumnCount(3);
        setMaximumWidth(450);
        tabella->setColumnWidth(2,150);
        QStringList headerLabels;
        headerLabels << QString::fromStdString(gd->getNomeAsseX()) << QString::fromStdString(gd->getNomeAsseY()) << "Regressione Lineare";
        tabella->setHorizontalHeaderLabels(headerLabels);
        for(int i=0; i<tabella->rowCount(); ++i){
            QTableWidgetItem* itemX = new QTableWidgetItem;
            QTableWidgetItem* itemY = new QTableWidgetItem;
            QTableWidgetItem* itemReg = new QTableWidgetItem;
            itemX->setData(Qt::EditRole,punti.at(i).first);
            itemY->setData(Qt::EditRole,punti.at(i).second);
            itemReg->setData(Qt::DisplayRole,reg.at(i));
            itemReg->setFlags(itemReg->flags() ^ Qt::ItemIsEditable);
            tabella->setItem(i,0,itemX);
            tabella->setItem(i,1,itemY);
            tabella->setItem(i,2,itemReg);
        }
    }


}