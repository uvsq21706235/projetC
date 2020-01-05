#ifndef SIMULATEUR_H
#define SIMULATEUR_H

#include "Reservoir.h"
#include "Pompe.h"
#include "Vanne.h"
#include "Moteur.h"
#include <QWidget>
#include  <QDebug>
#include <QMessageBox>
#include <QDebug>

#include <iostream>



class Simulateur
{
 private :
   Moteur *m1;
   Moteur *m2;
   Moteur *m3;

   Pompe* p11;
   Pompe* p12;
   Pompe* p21;
   Pompe* p22;
   Pompe* p31;
   Pompe* p32;

   Reservoir *r1;
   Reservoir *r2;
   Reservoir *r3;

   Vanne *VT12;
   Vanne *VT23;
   Vanne *V12;
   Vanne *V13;
   Vanne *V23;


public slots :


    //infos Vannes
    void infoVanneVT12( );
    void infoVanneVT23();
    void infoVanneV12();
    void infoVanneV13();
    void infoVanneV23();

   /* Pompe& getPompe11();
    Pompe& getPompe12();
    Pompe& getPompe21();
    Pompe& getPompe22();
    Pompe& getPompe31();
    Pompe& getPompe32();
    */
public :
    Simulateur();
   // Simulateur(Moteur * m1, Moteur * m2, Moteur *m3 );
    ~Simulateur();
};

#endif // SIMULATEUR_H
