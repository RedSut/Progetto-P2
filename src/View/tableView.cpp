#include "tableView.h"
#include "Controller.h"

#include<iostream>
#include <QHeaderView>
#include<QAbstractItemView>

tableView::tableView(QWidget* parent): QWidget(parent){
    mainLayout = new QVBoxLayout;
    tabella = new QTableWidget;
    //tableVista = new QTableView(tabella);
    aggiornaButton = new QPushButton("Aggiorna");
    aggiungiRigaButton = new QPushButton("Aggiungi Riga");
    aggiungiColonnaButton = new QPushButton("Aggiungi Colonna");

    tabella->horizontalHeader()->setDefaultSectionSize(120);


    mainLayout->addWidget(tabella);
    mainLayout->addWidget(aggiornaButton);
    mainLayout->addWidget(aggiungiRigaButton);
    mainLayout->addWidget(aggiungiColonnaButton);
    aggiungiColonnaButton->hide();
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
        aggiungiColonnaButton->show();
        std::vector<std::string> leg = gb->getLegenda();
        std::vector<double> val = gb->getValori();
        std::vector<std::string> cat = gb->getCategorie();
        tabella->setRowCount(leg.size()+1);
        tabella->setColumnCount(cat.size()+1);
        if(cat.size()<3){
            setMaximumWidth((140*tabella->columnCount())+15); //Da Vedere
        }
        QTableWidgetItem* itemNotEditable = new QTableWidgetItem;
        itemNotEditable->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
        tabella->setItem(0,0,itemNotEditable);
        for(int i = 0; i<cat.size(); i++){
            QTableWidgetItem* headerItem = new QTableWidgetItem;
            headerItem->setText(QString::fromStdString(cat.at(i)));
            tabella->setItem(0,i+1,headerItem);
        }
        for(int j = 0; j<leg.size(); j++){
            QTableWidgetItem* headerItem = new QTableWidgetItem;
            headerItem->setText(QString::fromStdString(leg.at(j)));
            tabella->setItem(j+1,0,headerItem);
        }

        for(int i=1; i<tabella->rowCount(); i++){
            for(int j=1; j<tabella->columnCount(); j++){
                QTableWidgetItem* item = new QTableWidgetItem;
                double v = val.at((j-1)+((i-1)*cat.size()));
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

void tableView::extractTable(grafico* G){

    torta* gt = dynamic_cast<torta*>(G);
    istogramma* gi = dynamic_cast<istogramma*>(G);
    barre* gb = dynamic_cast<barre*>(G);
    linea* gl = dynamic_cast<linea*>(G);
    dispersione* gd = dynamic_cast<dispersione*>(G);

    if(gt || gi){
        std::vector<std::string> leg;
        std::vector<double> val;
        QList<int> righeDaRimuovere;
        int nRows = tabella->rowCount();
        for(int i=0; i<nRows; i++){
            QTableWidgetItem* item1 = tabella->item(i,0);
            QTableWidgetItem* item2 = tabella->item(i,1);
            QString l = item1->text();
            QString v = item2->text();
            if(l.isEmpty() && v.toDouble()==0){
                righeDaRimuovere.append(i);
            }else{
                leg.push_back(l.toStdString());
                val.push_back(v.toDouble());
            }
        }
        rimuoviRighe(righeDaRimuovere);
        if(gt){
            gt->setLegenda(leg);
            gt->setValori(val);
        }else if(gi){
            gi->setLegenda(leg);
            gi->setValori(val);
        }
    }else if(gb){
        std::vector<std::string> leg;
        std::vector<std::string> cat;
        std::vector<double> val;
        for(int i=1; i<tabella->columnCount(); i++){
            QTableWidgetItem* item = tabella->item(0,i);
            QString v = item->text();
            cat.push_back(v.toStdString());
        }
        gb->setCategorie(cat);
        for(int j=1; j<tabella->rowCount(); j++){
            QTableWidgetItem* item = tabella->item(j,0);
            QString v = item->text();
            leg.push_back(v.toStdString());
        }
        gb->setLegenda(leg);
        for(int i=1; i<tabella->rowCount(); i++){
            for(int j=1; j<tabella->columnCount(); j++){
                QTableWidgetItem* item = tabella->item(i,j);
                QString v = item->text();
                val.push_back(v.toDouble());
            }
        }
        gb->setValori(val);
    }else if(gl || gd){
        std::vector<std::pair<double,double>> p;
        for(int i=0; i<tabella->rowCount(); i++){
            QTableWidgetItem* item1 = tabella->item(i,0);
            QTableWidgetItem* item2 = tabella->item(i,1);
            QString l = item1->text();
            QString v = item2->text();
            p.push_back({l.toDouble(),v.toDouble()});
        }
        if(gl){
            gl->setPunti(p);
        }else if(gd){
            gd->setPunti(p);
        }
    }
}

void tableView::setController(Controller* contr){
    C = contr;
    connect(aggiornaButton,SIGNAL(clicked()),C,SLOT(aggiornaGrafico()));

    connect(aggiungiRigaButton,SIGNAL(clicked()),C,SLOT(aggiungiRigaTabella()));
    connect(aggiungiColonnaButton,SIGNAL(clicked()),C,SLOT(aggiungiColonnaTabella()));
}

void tableView::aggiungiRiga(grafico* G){
    int nRows = tabella->rowCount();
    tabella->insertRow(nRows);
    if(dynamic_cast<torta*>(G) || dynamic_cast<istogramma*>(G)){
        QTableWidgetItem* item1 = new QTableWidgetItem;
        QTableWidgetItem* item2 = new QTableWidgetItem;
        item1->setText("");
        item2->setData(Qt::EditRole,0.00);
        tabella->setItem(nRows,0,item1);
        tabella->setItem(nRows,1,item2);
    }else if(dynamic_cast<linea*>(G) || dynamic_cast<dispersione*>(G)){
        QTableWidgetItem* item1 = new QTableWidgetItem;
        QTableWidgetItem* item2 = new QTableWidgetItem;
        item1->setData(Qt::EditRole,0.00);
        item2->setData(Qt::EditRole,0.00);
        tabella->setItem(nRows,0,item1);
        tabella->setItem(nRows,1,item2);
        if(dynamic_cast<dispersione*>(G)){
            QTableWidgetItem* item3 = new QTableWidgetItem;
            item3->setText("nan");
            //item3->setFlags(item3->flags() ^ Qt::ItemIsEnabled);
            tabella->setItem(nRows,2,item3);
        }
    }else if(dynamic_cast<barre*>(G)){
        QTableWidgetItem* legend = new QTableWidgetItem;
        QString leg = "Gruppo ";
        leg.append(QString::number(nRows));
        legend->setText(leg);
        tabella->setItem(nRows,0,legend);
        for(int i=1; i<tabella->columnCount();i++){
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setData(Qt::EditRole,0.00);
            tabella->setItem(nRows,i,item);
        }
    }

}

void tableView::rimuoviRighe(QList<int> indici){
    for(int i = indici.size()-1; i>=0; i--){
        tabella->removeRow(indici.at(i));
    }
}

void tableView::aggiungiColonna(grafico* G){
    int nCols = tabella->columnCount();
    tabella->insertColumn(nCols);
    if(dynamic_cast<barre*>(G)){
        QTableWidgetItem* categories = new QTableWidgetItem;
        QString cat = "Categoria ";
        cat.append(QString::number(nCols));
        categories->setText(cat);
        tabella->setItem(0,nCols,categories);
        for(int i=1; i<tabella->rowCount();i++){
             QTableWidgetItem* item = new QTableWidgetItem;
             item->setData(Qt::EditRole,0.00);
             tabella->setItem(i,nCols,item);
        }
        setMinimumWidth(this->maximumWidth()+130);
        if(nCols<3){
            setMaximumWidth(this->maximumWidth()+130);
        }
    }
}
