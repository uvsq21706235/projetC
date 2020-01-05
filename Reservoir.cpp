#include "Reservoir.h"
//#include "Vanne.h"
#include <iostream>
using namespace std;





    Reservoir :: Reservoir(int c, string name, Pompe* pp, Pompe* ps){
        nom = name;
        capacite = c;
        primaire = pp;
        secondaire = ps;
    }

        //permet de vider le reservoir
    void Reservoir :: vidange(){
        capacite = 0;
    }

        //getter de la classe



    bool Reservoir :: get_etat(){
        if(capacite) return true;
        return false;
    }

    int Reservoir::get_etat_pompe_primaire(){
        return primaire.etat;

    }

    int Reservoir::get_etat_pompe_secondaire(){
        return secondaire.etat;

    }

    int Reservoir:: get_capacite(){
        return capacite;
    }

    string Reservoir::get_nom(){
        return nom;
    }

    void Reservoir::set_capacite(int i){
        capacite = i;
    }

        //permet d'equilibrer les reservoirs
    void Reservoir::equilibre_res(const Vanne &v12, const Vanne &v23, Reservoir &r2, Reservoir &r3){
        int glob;
        if (v12.etat) {
            if (v23.etat){
                glob = this->capacite + r2.get_capacite() + r3.get_capacite();
                if (glob/3 < MAX2){
                    this->capacite = glob;
                    r2.set_capacite(glob);
                    r3.set_capacite(glob);
                }
                else{
                    r2.set_capacite(MAX2);
                    glob = (glob-MAX2)/2;
                    this->capacite = glob;
                    r3.set_capacite(glob);

                }
            }
            else {
                glob = this->capacite + r2.get_capacite();
                if (glob/2 < MAX2){
                    r2.set_capacite(glob/2);
                    this->capacite = glob/2;
                }
                else{
                    r2.set_capacite(MAX2);
                    this->capacite = glob-MAX2;
                }
            }
        }
        else{
            if (v23.etat){
                glob = r3.get_capacite() + r2.get_capacite();
                if (glob/2 < MAX2){
                    r2.set_capacite(glob/2);
                    r3.set_capacite(glob/2);
                }
                else{
                    r2.set_capacite(MAX2);
                    r3.set_capacite(glob-MAX2);
                }
            }
        }


    }


        // destructeur de la classe Reservoir
    Reservoir::~Reservoir(){}
//	friend  Reservoir::operator=(Reservoir &r){ return r;}
