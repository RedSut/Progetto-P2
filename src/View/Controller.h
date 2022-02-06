#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>

#include "../Model/classi/Model.h"

class graficoMenu; // Vista iniziale DA TOGLIERE

class Controller : public QObject{
    Q_OBJECT
    private:
        graficoMenu* menu;
        Model* model;

    public:
        void setModel(Model* m);
	    void setView(graficoMenu* gm);

    public solts:
        void prova()const;
};

#endif