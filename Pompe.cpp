#include "Pompe.h"
#include <iostream>
using namespace std;



        //constructeur de la classe pompe qui prend en argument l'état initial de la pompe
    Pompe::Pompe ( QString nom,int e){
        etat = e;
        this->nom = nom;
    }

        //permet d'activer ou de desactiver la pompe
    void Pompe::power(){
        etat = 1-etat;
        QString tmpNom;
        if (etat) tmpNom = "Activée";
        else tmpNom = "Desactivée";
       qDebug()<<"La Pompe " << nom << " est en "<< tmpNom<< endl;
    }

        //permet de déclancher une panne
    void Pompe::panne(){
        etat = -1;
    }


        //destructeur de la classe Pompe
    Pompe::~Pompe(){}

