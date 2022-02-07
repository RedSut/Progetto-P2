//#include "View/graficoView.h"
#include "View/MainWindow.h"
//#include "View/tableView.h"
//#include "View/gestorePagine.h"
#include "View/Controller.h"
#include "Model/classi/Model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        //QMainWindow* mw = new QMainWindow();
        Model* m = new Model();
        Controller* c = new Controller();
        /*grafico* G = m->getGrafico();

        torta* t = dynamic_cast<torta*>(G);

        std::vector<std::string> leg = {"Prova","Prova2"};
        t->setLegenda(leg);
        std::vector<double> val = {24,12};
        t->setValori(val);

        gw->showGrafico(G);*/
        graficoCreator* gc = new graficoCreator();
        std::vector<std::string> leg = {"Prova","Prova2"};
        std::vector<double> val = {24,12};
        std::vector<std::pair<double,double>> punti = {{24,12},{25,13},{22,12},{21,13},{25,15},{27,12},{30,15},{32,18},{27,14}};
        std::vector<std::string> cat = {"Maschi","Femmine"};
        grafico* g = gc->createDispersione("Prova",punti,"Asse X","Asse Y");
        grafico* gu = gc->createTorta("Update",leg,val);
        //Model* m = new Model();
        //m->setGrafico(*g);

        MainWindow* mw = new MainWindow();
        mw->setController(c);
        c->setModel(m);
        c->setView(mw);

        //tableView* tv = new tableView();

        //graficoView* gw = new graficoView(mw);
        //gw->setModel(m);
        //gw->updateTheme(1);
        //gw->showGrafico(g);
        //gw->updateGrafico(gu);

        //tv->populateTable(gu);


        mw->show();
        //gw->show();
        //tv->show();


		//c.setModel(&m);
		//c.setView(&gw);
		//w.setController(&c);
        //mw->setCentralWidget(gw);
        //mw->show();

		return a.exec();
}

