#include "Reservoir.h"
//#include "Vanne.h"
#include <iostream>
using namespace std;





    Reservoir ::Reservoir(int c, QString name, Pompe*pp, Pompe* ps){
        nom = name;
        capacite = c;
        primaire = pp;
        secondaire = ps;
    }

        //permet de vider le reservoir
    void Reservoir :: vidange(){
        capacite = 0;
       // primaire->etat = 0;
       // secondaire->etat = 0;
         qDebug()<<"Vidange du Reservoir  " << nom << endl;

    }

        //getter de la classe



    bool Reservoir :: get_etat(){
        if(capacite) return true;
        return false;
    }


    int Reservoir::get_etat_pompe_primaire(){
        return primaire->etat;
    }

    int Reservoir::get_etat_pompe_secondaire(){
        return secondaire->etat;
     }

    int Reservoir::get_etatReservoir(){
        return capacite;
    }

    QString Reservoir::get_nom(){
        return nom;
    }

    void Reservoir::set_capacite(int i){
        capacite = i;
    }



        // destructeur de la classe Reservoir
    Reservoir::~Reservoir(){}
//	friend  Reservoir::operator=(Reservoir &r){ return r;}
