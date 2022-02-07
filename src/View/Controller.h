#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>

#include "../Model/classi/Model.h"
#include "MainWindow.h"

class Controller : public QObject{
    Q_OBJECT
    private:
        MainWindow* mainWin;
        Model* model;

    public:
        Controller();
        void setModel(Model*);
	    void setView(MainWindow*);

    public solts:
        void createTorta()const;
};

#endif