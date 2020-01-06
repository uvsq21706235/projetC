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
using namespace std;


class Window3 : public QMainWindow{
     Q_OBJECT

private:
    Simulateur s;
    string username;
    QGridLayout *layout;
    QWidget *test;

public:
    Window3(Simulateur &simi, QWidget *parent = nullptr);
    bool verificationID(QString user, QString password);
    ~Window3();

 public slots:
    void identifier();
    void entrainement();
    void historique();
};

#endif // WINDOW3_H
