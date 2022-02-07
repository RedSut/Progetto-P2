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

class tableView: public QWidget{
    private:
        QTableWidget* tabella;
        QVBoxLayout* mainLayout;
        QPushButton* aggiornaButton;
    public:
        explicit tableView(QWidget* = nullptr);
        void populateTable(grafico*);
};

#endif
