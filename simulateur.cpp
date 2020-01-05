#include "simulateur.h"


Simulateur::Simulateur()
    {

        p11 = new Pompe( "p11",1);
        p12 = new Pompe("p12");
        p21 = new Pompe("p21",1);
        p22 = new Pompe("p22");
        p31 = new Pompe("p31",1);
        p32 = new Pompe("p32");

        r1 = new Reservoir(100, "Tank1", p11, p12);
        r2 = new Reservoir(50, "Tank2", p21, p22);
        r3 = new Reservoir(100, "Tank3", p32, p32);

        m1 = new Moteur(*r1 );
        m2 = new Moteur(*r2);
        m3 = new Moteur(*r3);


         VT12 = new Vanne("VT12");
         VT23 = new Vanne("VT23");
         V12 = new Vanne("V12");
         V13 = new Vanne("V13");
         V23 = new Vanne("V23");
}

        void Simulateur::infoVanneVT12() { VT12->power();}
        void Simulateur::infoVanneVT23() { VT23->power();}
        void Simulateur::infoVanneV12()  { V12->power();}
        void Simulateur::infoVanneV13()  { V13->power();}
        void Simulateur::infoVanneV23()  { V23->power();}


        void Simulateur::infoPompe12() { p12->power();}
        void Simulateur::infoPompe22() { p22->power();}
        void Simulateur::infoPompe32() { p32->power();}

        void Simulateur::ex_vidangeR1(){r1->vidange(); }
        void Simulateur::ex_vidangeR2(){r2->vidange();}
        void Simulateur::ex_vidangeR3(){r3->vidange();}

        void Simulateur::ex_pannepompe11(){}
        void Simulateur::ex_pannepompe12(){}
        void Simulateur::ex_pannepompe21(){}
        void Simulateur::ex_pannepompe22(){}
        void Simulateur::ex_pannepompe31(){}
        void Simulateur::ex_pannepompe32(){}

Simulateur::~Simulateur(){}

