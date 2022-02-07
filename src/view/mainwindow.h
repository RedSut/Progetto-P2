#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QFrame>
#include <QString>
#include <QStackedWidget>
//#include<secondarywindow.h>
#include "graficoView.h"
#include "tableView.h"
//#include "Controller.h"

class Controller;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow :public QWidget
{
    Q_OBJECT
    //SecondaryWindow *secondary;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //void setController(Controller *c);
    graficoView* getGraficoView()const;
private:
    graficoView* graficoWindow;
    //Ui::MainWindow *ui;
    QMenuBar* menuBar;
    //QHBoxLayout* buttonLayout;
    QStackedWidget* pagine;

    //Controller* C;

    void addMenuBar();
    QHBoxLayout* addMainButtons();
public slots:
    void goToGrafico();

};
#endif // MAINWINDOW_H
