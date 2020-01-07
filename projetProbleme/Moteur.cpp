#include "Moteur.h"
#include <iostream>
using namespace std;

        //constructeur de la classe Moteur
    Moteur::Moteur(Reservoir &res){
        origine = &res;
        chemin = 1;
    }

        //changement du reservoir d'origine
    void Moteur::set_reservoir(Reservoir &res){
        origine = &res;
        this->set_chemin();
    }

        //changement de la pompe
    void Moteur::set_chemin(){
        chemin = 0;
    }

        //alimentation du moteur
    void Moteur::alimentation(){
        origine->capacite -= 6;
        if (origine->capacite < 0) origine->capacite = 0;

    }

        //destructeur de la classe Moteur
    Moteur::~Moteur(){}
