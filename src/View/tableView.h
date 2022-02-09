#ifndef TABLE_VIEW
#define TABLE_VIEW

#include <QTableWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

#include "../Model/classi/barre.h"
#include "../Model/classi/dispersione.h"
#include "../Model/classi/istogramma.h"
#include "../Model/classi/torta.h"
#include "../Model/classi/linea.h"

class Controller;

class tableView: public QWidget{
    private:
        QTableWidget* tabella;
        QVBoxLayout* mainLayout;
        QPushButton* aggiornaButton;
        QPushButton* aggiungiRigaButton;
        QPushButton* aggiungiColonnaButton;

        Controller* C;

    public:
        explicit tableView(QWidget* = nullptr);
        void populateTable(grafico*);
        void extractTable(grafico*);
        void setController(Controller*);
        void aggiungiRiga(grafico*);
        void aggiungiColonna(grafico*);
        void rimuoviRighe(QList<int>);
};

#endif
