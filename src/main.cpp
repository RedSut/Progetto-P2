#include "View/MainWindow.h"
#include "View/Controller.h"
#include "Model/classi/Model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    Controller c;

    MainWindow mw;
    c.setModel(&m);
    c.setView(&mw);
    mw.setController(&c);

    mw.show();
    return a.exec();
}

