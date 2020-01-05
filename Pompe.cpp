#include "Pompe.h"
#include <iostream>
using namespace std;



        //constructeur de la classe pompe qui prend en argument l'état initial de la pompe
    Pompe::Pompe (int e){
        etat = e;
    }

        //permet d'activer ou de desactiver la pompe
    void Pompe::power(){
        etat = 1-etat;
    }

        //permet de déclancher une panne
    void Pompe::panne(){
        etat = -1;
    }


        //destructeur de la classe Pompe
    Pompe::~Pompe(){}

