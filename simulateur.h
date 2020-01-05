#ifndef SIMULATEUR_H
#define SIMULATEUR_H

#include "Reservoir.h"
#include "Pompe.h"
#include "Vanne.h"
#include "Moteur.h"
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


public:
    Simulateur();
   // Simulateur(Moteur * m1, Moteur * m2, Moteur *m3 );
    ~Simulateur();

    //getters
    Vanne& getVanneVT12() { return VT12; }
    Vanne& getVanneVT23() { return VT23; }
    Vanne& getVanneV12() { return V12; }
    Vanne& getVanneV13() { return V13; }
    Vanne& getVanneV23() { return V23; }

    Pompe& getPompe11() { return p11; }
    Pompe& getPompe12() { return p12; }
    Pompe& getPompe21() { return p21; }
    Pompe& getPompe22() { return p22; }
    Pompe& getPompe31() { return p31; }
    Pompe& getPompe32() { return p32; }

};

#endif // SIMULATEUR_H
