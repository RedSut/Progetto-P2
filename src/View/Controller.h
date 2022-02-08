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
        explicit Controller(QObject* = nullptr);
        void setModel(Model*);
	    void setView(MainWindow*);

    public slots:
        void createTorta() const;

        void nuovo() const;
        void open() const;
        void save() const;
        void saveAs() const;
};

#endif
