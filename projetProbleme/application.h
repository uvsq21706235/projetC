#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QPushButton>
#include "simulateur.h"
#include "mainwindow.h"

class Application : public QMainWindow
{

    Q_OBJECT // genere des bout de code en plus pour que le mecanisme fonctionne

private:
    Simulateur* S;
    MainWindow* M;

public:
    Application(QWidget *parent = nullptr);
    ~Application();
/*
public slots:
    void powerVanne(Vanne& v);
    void powerPompe(Pompe& p);
    void pannePompe(Pompe& p);
*/
};

#endif
