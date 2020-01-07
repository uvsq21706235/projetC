#ifndef WINDOW3_H
#define WINDOW3_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include "simulateur.h"
#include "mainwindow.h"
#include <QInputDialog>
#include <iostream>
#include <fstream>
#include <string>
#include <QFile>
#include "window2.h"
#include <QApplication>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

using namespace std;


class Window3 : public QMainWindow{
    friend class Window2;
    friend class MainWindow;
     Q_OBJECT

private:
    Simulateur s;
    string nom;
    QGridLayout *layout;
    QWidget *test;


    MainWindow *fenetre1;
    Window2 *fenetre2;

public:
    Window3(Simulateur &simi, QWidget *parent = nullptr);
    bool verificationID(QString user, QString password);
    ~Window3();

 public slots :
    void identifier();
    void deconnexion();
    void entrainement();
    void historique();
    void sauvegarde();
};
#endif // WINDOW3_H
