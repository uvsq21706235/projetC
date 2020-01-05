#include "simulateur.h"

Simulateur::Simulateur()
    {

        p11 = new Pompe(1);
        p12 = new Pompe;
        p21 = new Pompe(1);
        p22 = new Pompe;
        p31 = new Pompe(1);
        p32 = new Pompe;

        r1 = new Reservoir(100, "Tank1", p11, p12);
        r2 = new Reservoir(50, "Tank2", p21, p22);
        r3 = new Reservoir(100, "Tank3", p32, p32);

        m1 = new Moteur(*r1 );
        m2 = new Moteur(*r2);
        m3 = new Moteur(*r3);


         VT12 = new Vanne();
         VT23 = new Vanne();
         V12 = new Vanne();
         V13 = new Vanne();
         V23 = new Vanne();

    }

Simulateur::~Simulateur(){}

