#ifndef _MOTEUR_H
#define _MOTEUR_H

#include "Reservoir.h"
#include <iostream>

using namespace std;

class Moteur{

private:

    Reservoir *origine;
    int chemin; //1 si pompe primaire d'origine, 0 si pompe secondaire

public:

        //constructeur de la classe Moteur
    Moteur(Reservoir &res);

        //changement du reservoir d'origine
    void set_reservoir(Reservoir &res);

        //changement de la pompe d'origine
    void set_chemin();

        //getters
    Reservoir* getReservoir(){return origine;}
    int getPompe(){return chemin;}

        //alimentation du moteur
    void alimentation();

        //destructeur de la classe Moteur
    ~Moteur();

};

#endif
