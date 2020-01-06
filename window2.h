#ifndef WINDOW2_H
#define WINDOW2_H
#include <QMainWindow>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include "simulateur.h"
#include "mainwindow.h"
#include "mywidget.h"


class Window2 : public QMainWindow{

    Q_OBJECT

public:
    Window2(Simulateur &simi ,QWidget *parent = nullptr);

    ~Window2();
public slots:

   //vidange reservoir
    void  VidangeReservoir1();
    void  VidangeReservoir2();
    void  VidangeReservoir3();

    //panne Pompe
    void  PannePompe11();
    void  PannePompe12();
    void  PannePompe21();
    void  PannePompe22();
    void  PannePompe31();
    void  PannePompe32();

private :
    QString nom;
    Simulateur s;

    QString info;

 //  CustomButton  * m_customBtn;

    QList<QPushButton*> m_listBtn;

    QVBoxLayout * m_vLayout1;
    QVBoxLayout * m_vLayout2;
    QVBoxLayout * m_vLayout3;
    QVBoxLayout * m_vLayoutbis;
    QHBoxLayout *text;
    QHBoxLayout * m_hLayout;
    QHBoxLayout * m_hLayout1;
    QWidget * m_mainWidget;

};

#endif // WINDOW2_H
