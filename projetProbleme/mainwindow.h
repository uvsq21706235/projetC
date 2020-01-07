#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "simulateur.h"
#include "window3.h"
#include "window2.h"


class MainWindow : public QMainWindow
{
    friend class Window2;
    friend class Window3;
    Q_OBJECT

public:
    MainWindow(Simulateur &simi, QWidget *parent = nullptr);

    ~MainWindow();
    string boutonActive1();

public slots:
    void  OnOffVanneVT12();
    void  OnOffVanneVT23();
    void  OnOffVanneV12();
    void  OnOffVanneV13();
    void  OnOffVanneV23();


    void  OnOffPompeP12();
    void  OnOffPompeP22();
    void  OnOffPompeP32();


private :
    QString nom;
    Simulateur s;
    string bouton;
 //   Window2 *window;

 //  CustomButton  * m_customBtn;

    QList<QPushButton*> m_listBtn;

    QVBoxLayout * m_vLayout1;
    QVBoxLayout * m_vLayout2;
    QVBoxLayout * m_vLayout3;
    QVBoxLayout * m_vLayoutbis;

    QHBoxLayout * m_hLayout;
    QHBoxLayout * m_hLayout1;
    QWidget * m_mainWidget;
};
#endif // MAINWINDOW_H
