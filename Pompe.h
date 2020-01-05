#ifndef _POMPE_H
#define _POMPE_H

#include <iostream>

using namespace std;

class Pompe{
    friend class Reservoir;

private:

        //etat égal à 1 si la pompe est en marche, à 0 si la pompe est à l'arrêt, à -1 si elle est en panne
    int etat;

public:

        //constructeur de la classe pompe qui prend en argument l'état initial de la pompe
    Pompe(int e=0);

        //permet d'activer ou de desactiver la pompe
    void power();

        //permet de déclancher une panne
    void panne();

        //destructeur de la classe Pompe
    ~Pompe();

};

#endif
