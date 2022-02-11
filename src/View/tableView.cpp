#include "tableView.h"
#include "Controller.h"

#include<iostream>
#include <QHeaderView>
#include<QAbstractItemView>

tableView::tableView(QWidget* parent): QWidget(parent){
    mainLayout = new QVBoxLayout;
    tabella = new QTableWidget;

    aggiornaButton = new QPushButton("Aggiorna Grafico");
    aggiungiRigaButton = new QPushButton("Aggiungi Riga");
    rimuoviRigaButton = new QPushButton("Rimuovi Ultima Riga");
    aggiungiColonnaButton = new QPushButton("Aggiungi Colonna");
    rimuoviColonnaButton = new QPushButton("Rimuovi Ultima Colonna");

    aggiornaButton->setStyleSheet("background-color: #FFA62B; color: black;");
    aggiungiRigaButton->setStyleSheet("background-color: #FFA62B; color: black;");
    rimuoviRigaButton->setStyleSheet("background-color: #FFA62B; color: black;");
    aggiungiColonnaButton->setStyleSheet("background-color: #FFA62B; color: black;");
    rimuoviColonnaButton->setStyleSheet("background-color: #FFA62B; color: black;");

    tabella->horizontalHeader()->setDefaultSectionSize(120);
    tabella->verticalHeader()->setDefaultSectionSize(30);
    tabella->setStyleSheet("QWidget {border: 0px; background-color: #82ADC4; color: black;\n}" //#7DCFB6 #628395 #86BBD8
                           "QTableCornerButton::section {background-color: #F06543}");
    tabella->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color: #F06543; color: white;}");
    tabella->verticalHeader()->setStyleSheet("QHeaderView::section {background-color: #F06543; color: white;}");
    tabella->setSortingEnabled(true);

    mainLayout->addWidget(tabella);
    mainLayout->addWidget(aggiornaButton);
    mainLayout->addWidget(aggiungiRigaButton);
    mainLayout->addWidget(rimuoviRigaButton);
    mainLayout->addWidget(aggiungiColonnaButton);
    mainLayout->addWidget(rimuoviColonnaButton);
    aggiungiColonnaButton->hide();
    rimuoviColonnaButton->hide();
    setLayout(mainLayout);
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
        std::vector<double> valPer = gt->getValoriInPercentage();
        tabella->setRowCount(val.size());
        tabella->setColumnCount(3);
        setMaximumWidth(450);
        QStringList headerLabels;
        headerLabels << "Legenda" <<"Valori" <<"Valori %";
        tabella->setHorizontalHeaderLabels(headerLabels);
        for(int i=0; i<tabella->rowCount(); ++i){
            QTableWidgetItem* item1 = new QTableWidgetItem;
            QTableWidgetItem* item2 = new QTableWidgetItem;
            QTableWidgetItem* item3 = new QTableWidgetItem;
            item1->setText(QString::fromStdString(leg.at(i)));
            item2->setData(Qt::EditRole,val.at(i));
            QString p;
            p.append(QString::number(valPer.at(i)));
            p.append("%");
            item3->setData(Qt::DisplayRole,p);
            item3->setFlags(item3->flags() ^ Qt::ItemIsEditable);
            tabella->setItem(i,0,item1);
            tabella->setItem(i,1,item2);
            tabella->setItem(i,2,item3);
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
        rimuoviColonnaButton->show();
        std::vector<std::string> leg = gb->getLegenda();
        std::vector<double> val = gb->getValori();
        std::vector<std::string> cat = gb->getCategorie();
        tabella->setRowCount(leg.size());
        tabella->setColumnCount(cat.size());
        resizeColonne();
        /*QTableWidgetItem* itemNotEditable = new QTableWidgetItem;
        itemNotEditable->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
        tabella->setItem(0,0,itemNotEditable);*/
        for(int i = 0; i<cat.size(); i++){
            QTableWidgetItem* headerItem = new QTableWidgetItem;
            headerItem->setText(QString::fromStdString(cat.at(i)));
            //tabella->setItem(0,i+1,headerItem);
            tabella->setHorizontalHeaderItem(i,headerItem);
        }
        for(int j = 0; j<leg.size(); j++){
            QTableWidgetItem* headerItem = new QTableWidgetItem;
            headerItem->setText(QString::fromStdString(leg.at(j)));
            //tabella->setItem(j+1,0,headerItem);
            tabella->setVerticalHeaderItem(j,headerItem);
        }

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

void tableView::extractTable(grafico* G){

    torta* gt = dynamic_cast<torta*>(G);
    istogramma* gi = dynamic_cast<istogramma*>(G);
    barre* gb = dynamic_cast<barre*>(G);
    graficoPianoCartesiano* pc = dynamic_cast<graficoPianoCartesiano*>(G);

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
            leg.push_back(l.toStdString());
            val.push_back(v.toDouble());
        }
        QString headerLeg = tabella->horizontalHeaderItem(0)->text();
        QString headerVal = tabella->horizontalHeaderItem(1)->text();
        if(gt){
            gt->setLegenda(leg);
            gt->setValori(val);
        }else if(gi){
            gi->setLegenda(leg);
            gi->setValori(val);
            gi->setNomeLegenda(headerLeg.toStdString());
            gi->setNomeValori(headerVal.toStdString());
        }
    }else if(gb){
        std::vector<std::string> leg;
        std::vector<std::string> cat;
        std::vector<double> val;
        for(int i=0; i<tabella->columnCount(); i++){
            QTableWidgetItem* item = tabella->horizontalHeaderItem(i);
            QString v = item->text();
            cat.push_back(v.toStdString());
        }
        gb->setCategorie(cat);
        for(int j=0; j<tabella->rowCount(); j++){
            QTableWidgetItem* item = tabella->verticalHeaderItem(j);
            QString v = item->text();
            leg.push_back(v.toStdString());
        }
        gb->setLegenda(leg);
        for(int i=0; i<tabella->rowCount(); i++){
            for(int j=0; j<tabella->columnCount(); j++){
                QTableWidgetItem* item = tabella->item(i,j);
                QString v = item->text();
                val.push_back(v.toDouble());
            }
        }
        gb->setValori(val);
    }else if(pc){
        std::vector<std::pair<double,double>> p;
        for(int i=0; i<tabella->rowCount(); i++){
            QTableWidgetItem* item1 = tabella->item(i,0);
            QTableWidgetItem* item2 = tabella->item(i,1);
            QString l = item1->text();
            QString v = item2->text();
            p.push_back({l.toDouble(),v.toDouble()});
        }
        QString headerAsseX = tabella->horizontalHeaderItem(0)->text();
        QString headerAsseY = tabella->horizontalHeaderItem(1)->text();
        pc->setPunti(p);
        pc->setNomeAsseX(headerAsseX.toStdString());
        pc->setNomeAsseY(headerAsseY.toStdString());
    }
}

void tableView::setController(Controller* contr){
    C = contr;
    connect(aggiornaButton,SIGNAL(clicked()),C,SLOT(aggiornaGrafico()));

    connect(aggiungiRigaButton,SIGNAL(clicked()),C,SLOT(aggiungiRigaTabella()));
    connect(aggiungiColonnaButton,SIGNAL(clicked()),C,SLOT(aggiungiColonnaTabella()));

    connect(rimuoviRigaButton,SIGNAL(clicked()),C,SLOT(rimuoviRigaTabella()));
    connect(rimuoviColonnaButton,SIGNAL(clicked()),C,SLOT(rimuoviColonnaTabella()));

    connect(tabella->horizontalHeader(), &QHeaderView::sectionDoubleClicked, C, &Controller::modificaSezioneHTabella);
    connect(tabella->verticalHeader(), &QHeaderView::sectionDoubleClicked, C, &Controller::modificaSezioneVTabella);
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
        if(dynamic_cast<torta*>(G)){
            QTableWidgetItem* item3 = new QTableWidgetItem;
            item3->setText("0%");
            item3->setFlags(item3->flags() ^ Qt::ItemIsEditable);
            tabella->setItem(nRows,2,item3);
        }
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
            item3->setFlags(item3->flags() ^ Qt::ItemIsEditable);
            tabella->setItem(nRows,2,item3);
        }
    }else if(dynamic_cast<barre*>(G)){
        QTableWidgetItem* legend = new QTableWidgetItem;
        QString leg = "Gruppo ";
        leg.append(QString::number(nRows+1));
        legend->setText(leg);
        tabella->setVerticalHeaderItem(nRows,legend);
        for(int i=0; i<tabella->columnCount();i++){
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setData(Qt::EditRole,0.00);
            tabella->setItem(nRows,i,item);
        }
    }

}

void tableView::rimuoviRiga(){
    int row = tabella->rowCount()-1;
    if(row>0){
        tabella->removeRow(row);
    }
}

void tableView::aggiungiColonna(grafico* G){
    int nCols = tabella->columnCount();
    tabella->insertColumn(nCols);
    if(dynamic_cast<barre*>(G)){
        QTableWidgetItem* categories = new QTableWidgetItem;
        QString cat = "Categoria ";
        cat.append(QString::number(nCols+1));
        categories->setText(cat);
        tabella->setHorizontalHeaderItem(nCols,categories);
        for(int i=0; i<tabella->rowCount();i++){
             QTableWidgetItem* item = new QTableWidgetItem;
             item->setData(Qt::EditRole,0.00);
             tabella->setItem(i,nCols,item);
        }
        resizeColonne();
    }
}

void tableView::rimuoviColonna(){
    int col = tabella->columnCount()-1;
    if(col>0){
        tabella->removeColumn(col);
        resizeColonne();
    }
}

void tableView::resizeColonne(){
    if(tabella->columnCount()<5){
        setMaximumWidth(tabella->columnCount()*130 + 100);
        setMinimumWidth(tabella->columnCount()*130 + 100);
    }
}

void tableView::modificaSezioneH(int i, grafico* G){
    if(!dynamic_cast<torta*>(G)){
        QInputDialog* inputDialog = new QInputDialog;
        bool ok;
        QString text = inputDialog->getText(this, "Modifica", "Rinomina sezione:", QLineEdit::Normal, "", &ok);
        if(ok && !text.isEmpty()){
            QTableWidgetItem* item = tabella->horizontalHeaderItem(i);
            item->setText(text);
        }
    }
}

void tableView::modificaSezioneV(int i, grafico* G){
    if(dynamic_cast<barre*>(G)){
        QInputDialog* inputDialog = new QInputDialog;
        inputDialog->setStyleSheet("color:white");
        bool ok;
        QString text = inputDialog->getText(this, "Modifica", "Rinomina sezione:", QLineEdit::Normal, "", &ok);
        if(ok && !text.isEmpty()){
            QTableWidgetItem* item = tabella->verticalHeaderItem(i);
            item->setText(text);
        }
    }
}