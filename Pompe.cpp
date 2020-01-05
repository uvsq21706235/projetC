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
         QString tmpNom;
        if (etat == -1)
        {
            tmpNom = " Panne !";
            qDebug()<<"La Pompe " << nom << " est en "<< tmpNom<< endl;

        }

        else  {
               etat = 1-etat;

               if (etat) tmpNom = "Activée";
               else tmpNom = "Desactivée";
               qDebug()<<"La Pompe " << nom << " est en "<< tmpNom<< endl;
                  }
            }

        //permet de déclancher une panne
    void Pompe::panne(){
        etat = -1;
        qDebug()<<"Panne du la Pompe  " << nom << endl;
         }

    int Pompe::get_etat(){return etat;}

        //destructeur de la classe Pompe
    Pompe::~Pompe(){}

